<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS0 Laboratory Portfolio - Bushra Rahman
## CS 1136 (Programming Fundamentals Laboratory) - UTD Spring 2019
These labs assignments were done through [zyBooks](https://www.zybooks.com/).

## Execution Instructions (Simple)
Open terminal while in `CS0_Portfolio` and run:
<!-- CODE START -->
```
cd CS1136/src
g++ main.cpp lab_exercises.cpp
./a.exe
```
<!-- CODE END -->
This compilation instruction produces an executable directly in the `src` folder.

Alternatively, run:
<!-- CODE START -->
```
cd CS1136/src
mkdir ../build
g++ main.cpp lab_exercises.cpp -o ../build/labs
../build/labs
```
<!-- CODE END -->
This compilation instruction is intended to produce an executable in a `build` folder (by using the `-o` flag and providing the relative file path `../build/labs`). A `build` folder must first be created in `CS1136` if it does not exist (using `mkdir`).

The executable can be named anything (eg. `a.exe`), but a descriptive name like `labs.exe` (or just `labs`) is preferred.

Compilation and execution can be done either...
* ...with or without providing the `.exe` extention (the code block above does it without)
* ...with a forward slash `/` or backslash `\` (the code block above does it with `/`)

## src Folder
### Header File
* [lab_exercises.h](/CS1136/src/lab_exercises.h): contains 21 lab function prototypes
  * 1-1, 1-2
  * 2-1, 2-2, 2-3
  * 3-1, 3-2
  * 4-1, 4-2
  * 5-1, 5-2
  * 6-1, 6-2
  * 7-1, 7-2
  * 8-1, 8-2
  * 9-1, 9-2
  * 10-1, 10-2

### Source Files
* [main.cpp](/CS1136/src/main.cpp): program driver containing main()
* [lab_exercises.cpp](/CS1136/src/lab_exercises.cpp): implementation of 21 homework functions and 19 helper functions

## data Folder
Input files need to be provided using their relative path (ie. with the prefix `../data/`). Output files are also created using the same prefix.
* Lab 7-1:
  * [lab7ex1_sales.txt](/CS1136/data/lab7ex1_sales.txt): input file
  * [lab7ex1_saleschart.txt](/CS1136/data/lab7ex1_saleschart.txt): output file
* Lab 7-2:
  * [lab7ex2_avg.txt](/CS1136/data/lab7ex2_avg.txt): input file
  * [lab7ex2_invalids.txt](/CS1136/data/lab7ex2_invalids.txt): output file
* Lab 9-2:
  * [lab9ex2_data.txt](/CS1136/data/lab9ex2_data.txt): input file
  * [lab9ex2_output.xls](/CS1136/data/lab9ex2_output.xls): output file
* Lab 10-1:
  * [lab10ex1_student.txt](/CS1136/data/lab10ex1_student.txt): input file
  * [lab10ex1_answers.txt](/CS1136/data/lab10ex1_answers.txt): input file
* Lab 10-2:
  * [lab10ex2_grades.txt](/CS1136/data/lab10ex2_grades.txt): input file
