<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS0 Lecture/Laboratory Portfolio | Bushra Rahman
## CS 1336/1136 (Programming Fundamentals Lecture/Laboratory) | UTD Spring 2019
GitHub Pages link: https://br815.github.io/CS0_Portfolio/

This repository contains university programming assignments from my introductory C++ [lecture](/CS1336/readme.md) and [laboratory](/CS1136/readme.md) courses.

The purpose of this repository is archival and educational:
- to track my progress learning C++
- to practice writing clear, correct, and well-structured code
- to reflect on design decisions and showcase my improved understanding of the language

## Highlights
- Primitive data types, variable declarations, variable scope, and primitive operations
- Control statements/flow
- Input validation, output formatting, and file handling using loops and conditionals
- Function organization, prototyping, and implementation
- Arrays and strings using primitive data arrays
- String parsing and delimiter handling (explored beyond course requirements)
- Use of function pointers for user-driven execution (explored beyond course requirements)

## Instructions to Install MinGW
A C++ compiler is necessary to run these assignments (eg. the `g++` compiler in MinGW, a Microsoft Windows port of the GNU Compiler Collection).

To install MinGW on Windows 11 or less, follow [these instructions](https://github.com/br815/CS1_Portfolio/blob/main/CS1337/Eclipse_for_Windows_with_MinGW.pdf) (refer to Pages 3-4 of the linked PDF):
1. Download the latest version of the MinGW installer from [this SourceForge link](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/).
2. Run the installer. On the second installer screen, make sure to select the `X86_64` architecture. Don’t make any other changes with the installer.
3. Add the MinGW compiler the `Path` Environment Variable. [This YouTube video](https://www.youtube.com/watch?v=uadGsNA6h5Q) has the steps to follow:
    * Open `Control Panel >> System and Security >> System >> Advanced System Settings`.\
    (Alternatively, open `Settings >> System >> About >> Advanced System Settings`.)\
    This opens a window for `System Properties`.
    * In `System Properties`, go to `Environment Variables`.\
    In `Environment Variables`, look down at `System variables` and scroll until you reach `Path`.\
    Select `Path` and hit `Edit`.
    * Once you’ve opened `Edit environment variable`, find the file path for MinGW’s `/bin` folder in your File Explorer and copy it.\
    It should look similar to:
    <!-- CODE START -->
    ```
    C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin
    ```
    <!-- CODE END -->
    * Go back to `Edit environment variable`, hit `New`, and paste the file path for `/bin`.
    * Then hit `OK` in `Edit environment variable`, hit `OK` in `Environment Variables`, and hit `OK` in `System Properties`.
    * MinGW should now be properly installed and locatable within `Path`. To test in Command Prompt, run:
    <!-- CODE START -->
    ```
    g++ --version
    ```
    <!-- CODE END -->
    You should see output similar to:
    <!-- CODE START -->
    ```
    g++ (MinGW.org GCC-6.3.0-1) 6.3.0
    Copyright (C) 2016 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```
    <!-- CODE END -->
After installing MinGW and adding it to `Path`, make sure to restart your IDE to avoid compilation errors.

## C++ Compilation & Execution Overview
(Using [CS1336](/CS1336/) as an example. CS1336 contains a [src](/CS1336/src/) folder,\
which contains 2 source files [main.cpp](/CS1336/src/main.cpp) and [hw_exercises.cpp](/CS1336/src/hw_exercises.cpp), and 1 header file [hw_exercises.h](/CS1336/src/hw_exercises.h).)

Open terminal in `CS0_Portfolio` and run:
<!-- CODE START -->
```
cd CS1336                       # cd to project root
mkdir build                     # make a build folder if it doesn't exist
g++ src/*.cpp -o build/hw       # compile executable file into the build folder
build/hw                        # provide the build folder as the path to the .exe file
```
<!-- CODE END -->
C++ compilation & execution can occur from anywhere through the use of relative paths, as long as the compilation instruction specifies the relative path to the `.cpp` source files & the execution instruction specifies the relative path to the `.exe` executable file. However, execution *should* occur from the project root (because that is the conventional location from which your program should retrieve any IO files).

In order to achieve both compilation & execution from the project root, this compilation instruction goes through `src/` to compile all `.cpp` source files in [src](/CS1336/src/). Alternatively, each source file can be compiled individually through their paths:
<!-- CODE START -->
```
g++ src/main.cpp src/hw_exercises.cpp -o build/hw
```
<!-- CODE END -->
By default, C++ compilation produces `.exe` files directly in the same folder where compilation occurred; however, the provided compilation instruction uses the `-o` flag to produce the `.exe` file in a [build](/CS1336/build/) folder for clearer file organization.

Then, execution can occur from the project root as long as the path to the executable is specified, which for this project is through `build/`.

Technically, compilation & execution *can* occur from anywhere as long as the user provides the necessary relative file paths to the source files & executable. However, for user ease in this project, file paths to IO files are hard-coded in the source code to be preprended with `data/` so that the user can execute easily from the project root while still only needing to provide the base name of any IO file (eg. [`hw7ex2_NumListShort.txt`](/CS1336/data/hw7ex2_NumListShort.txt)). So for this project, compilation & execution *must* occur from the project root; or, the hard-coded preprending of the `data/` file path would need to be edited directly in the source code.

Similar compilation & execution behavior can be achieved through alternative commands, like:
<!-- CODE START -->
```
cd CS1336/src
g++ *.cpp                       # or, g++ main.cpp hw_exercises.cpp (note that here, the default a.exe file is produced directly in src)
cd ..                           # go back to the project root
src/a.exe                       # can be executed with or without providing the .exe extension
```
<!-- CODE END -->

Note that compilation and execution can be done either...
* ...with or without providing the `.exe` extention (the code blocks above illustrate both)
* ...with a forward slash `/` or backslash `\` (the code blocks above do it with `/`)

## Notes
As a learning exercise, some of my code explores alternative designs that go beyond what was required for these courses.

This code is not intended as production software.
