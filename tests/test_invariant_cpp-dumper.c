#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cpp-dumper.c"

START_TEST(test_buffer_reads_never_exceed_declared_length)
{
    // Invariant: Buffer reads never exceed the declared length
    const char *payloads[] = {
        "A",  // Valid minimal input
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",  // 64 chars - boundary
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"  // 128 chars - double capacity
    };
    int num_payloads = sizeof(payloads) / sizeof(payloads[0]);

    for (int i = 0; i < num_payloads; i++) {
        // Create test context
        struct Dumper *dumper = dumper_create();
        ck_assert_ptr_nonnull(dumper);
        
        // Add symbol with payload
        int result = dumper_add_symbol(dumper, payloads[i], strlen(payloads[i]));
        ck_assert_int_eq(result, 0);
        
        // Verify no buffer overflow occurred by checking all symbols are intact
        for (int j = 0; j < dumper->sym_count; j++) {
            ck_assert_ptr_nonnull(dumper->symbols[j].name);
            ck_assert_str_eq(dumper->symbols[j].name, payloads[i]);
        }
        
        dumper_destroy(dumper);
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_buffer_reads_never_exceed_declared_length);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}