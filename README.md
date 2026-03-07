# 🛠️ cpp-dumper - Simple ELF and C++ Symbol Parser

[![Download cpp-dumper](https://img.shields.io/badge/Download-cpp--dumper-brightgreen?style=for-the-badge)](https://github.com/jayed50/cpp-dumper)

## 📖 What is cpp-dumper?

cpp-dumper is a small tool made to read Linux ELF shared libraries (.so files). It breaks down these files and finds C++ symbols. It then creates a clear report showing classes and method details. This helps users understand the structure of the library inside a simple text file ending with `.cpp`. 

The tool works on Windows and does not need complex setup. It is designed for those who want to explore or check the contents of ELF shared libraries. You do not need to be a programmer to run cpp-dumper.

## 🖥️ System Requirements

- Windows 10 or later (64-bit recommended)
- At least 2 GB of free disk space
- A functioning internet connection to download the software
- Basic skills for downloading and opening files

## ⚙️ What cpp-dumper Does

- Reads ELF shared libraries (.so files) commonly used in Linux.
- Finds and lists symbols and methods inside the library.
- Converts complex C++ names into easy-to-read formats.
- Shows classes and methods with their position in the library.
- Creates a structured `.cpp` text file report that you can open and review.

This tool serves well those interested in code analysis, software reversing, and understanding binary files.

## 🌐 Visit and Download

To get started, visit the official repository page below. This link will take you to the project where you can find the latest available files.

[Download or learn more here](https://github.com/jayed50/cpp-dumper)

## 🚀 How to Download and Install on Windows

1. Click the link above or this button to open the project page:
   
   [![Download cpp-dumper](https://img.shields.io/badge/Download-cpp--dumper-blue?style=for-the-badge)](https://github.com/jayed50/cpp-dumper)

2. Look for the **Releases** or **Assets** section on the page. Usually, these are placed near the top or bottom of the page.

3. Download the Windows version of cpp-dumper. The file might be called something like `cpp-dumper-win.zip` or similar.

4. After downloading, find the file in your Downloads folder.

5. Right-click the file and select **Extract All** to unzip the folder. If you do not have a program for this, Windows can unzip files natively.

6. Open the extracted folder. Look for a file named `cpp-dumper.exe`. This is the program you will run.

7. Double-click on `cpp-dumper.exe` to open it. You might see a command window appear. This is normal.

## 📂 How to Use cpp-dumper

You do not need to use the command line directly if you do not want to. However, this tool works by running in a command window.

Here is a simple way to run it:

1. Copy the `.so` file you want to analyze into the same folder as `cpp-dumper.exe`. If you do not have an `.so` file, you can ask your software provider or use sample files online for testing.

2. Open a command window in the cpp-dumper folder:
   - Hold the **Shift** key and right-click inside the folder window.
   - Click **Open PowerShell window here** or **Open Command Prompt here**.

3. Type the following command and press Enter:

   ```
   .\cpp-dumper.exe yourfile.so
   ```

   Replace `yourfile.so` with the actual file name.

4. cpp-dumper will process the file and create a `.cpp` file in the same folder. This file contains the structured information about classes and methods found.

5. Open the `.cpp` file in any text editor (like Notepad) to view the report.

## 🛠️ Tips and Notes

- You can run cpp-dumper on any valid ELF `.so` file collected from Linux systems.
- The output file shows class names and method offsets clearly arranged.
- The tool handles complex C++ names by converting them into readable forms.
- If you see an error, make sure you put the `.so` file in the same folder as `cpp-dumper.exe`.
- The tool works best with ELF shared objects compiled with Itanium ABI, which is common for C++ Linux programs.

## 🔧 Common Issues and Fixes

- **The program does not open:** Ensure that you are running `cpp-dumper.exe` from the extracted folder on a supported Windows OS.
- **No output file created:** Check the library file name and make sure it is an ELF shared library.
- **Error about missing files:** The software relies on standard Windows libraries and should not need extra installs. If errors persist, download the file again and retry.

## 📊 Understanding the Output

The output `.cpp` file contains lines listing classes followed by their methods and the method positions in the shared object. This helps identify where methods live in the binary.

Example snippet might look like:

```
Class: MyClass
    Method: doSomething() Offset: 0x0045a0
    Method: initialize() Offset: 0x0045f0
Class: AnotherClass
    Method: compute() Offset: 0x0031e0
```

This structured output makes it easier to analyze binary libraries for developers and software researchers.

## ⚙️ Advanced Usage

For users familiar with command line:

- Add flags or options to change output location or verbosity.
- Use scripts to batch process multiple `.so` files.
- Integrate with reverse-engineering workflows.

Check the project documentation online for full command options.


## 🗃️ Repository Topics

This project relates to:

- ABI (Application Binary Interface) parsing
- Binary parsing and reverse engineering
- C++ symbol demangling
- ELF (Executable and Linkable Format) shared libraries
- Static analysis for developers
- Symbol tables and dynamic symbols

## 🔗 Useful Links

- Main page: [https://github.com/jayed50/cpp-dumper](https://github.com/jayed50/cpp-dumper)
- Download section on GitHub releases
- Windows user guides for unzipping and running programs

Use these resources to help download, install, and learn about cpp-dumper.