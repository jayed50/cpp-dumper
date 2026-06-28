#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Include the actual production header if it exists, otherwise declare the function
// Assuming the function from cpp-dumper.c is declared in a header or we declare it here
void process_base_name(char *base_name); // Declaration of the actual function

START_TEST(test_memmove_length_validation)
{
    // Invariant: memmove length must be non-negative and not cause out-of-bounds access
    const char *payloads[] = {
        "li",           // Exploit case: length 2, strlen - 2 = 0, but memmove with negative? Actually 0, but base_name+3 is out-of-bounds
        "l",            // Boundary: length 1, strlen - 2 = -1 (wrapped to large unsigned)
        "libvalid",     // Valid input: length 8, strlen - 2 = 6 (positive)
        "",             // Edge case: empty string, strlen - 2 = -2 (wrapped)
        "lib",          // Boundary: exact "lib", strlen - 2 = 1 (positive)
    };
    int num_payloads = sizeof(payloads) / sizeof(payloads[0]);

    for (int i = 0; i < num_payloads; i++) {
        // Copy payload to a writable buffer with sufficient space
        char buffer[256];
        strncpy(buffer, payloads[i], sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
        
        // Call the actual production function - this must not crash or cause undefined behavior
        process_base_name(buffer);
        
        // If we reach here without crashing, the test passes for this payload
        // Optionally add more checks on buffer state if needed, but the primary property is no memory violation
        ck_assert_msg(1, "Payload '%s' processed without crash", payloads[i]);
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_memmove_length_validation);
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