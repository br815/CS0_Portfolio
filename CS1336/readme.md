<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS0 Lecture Portfolio - Bushra Rahman
## CS 1336 (Programming Fundamentals Lecture) - UTD Spring 2019
These homework assignments were done through the course and have accompanying instructions.

## Execution Instructions (Simple)
Open terminal while in `CS0_Portfolio` and run:
<!-- CODE START -->
```
cd CS1336/src
g++ main.cpp hw_exercises.cpp
./a.exe
```
<!-- CODE END -->
This compilation instruction produces an executable directly in the `src` folder.

## Execution Instructions (Alternate)
Open terminal while in `CS0_Portfolio` and run:
<!-- CODE START -->
```
cd CS1336/src
mkdir ../build
g++ main.cpp hw_exercises.cpp -o ../build/hw
../build/hw
```
<!-- CODE END -->
These compilation instructions are intended to produce an executable in the `build` folder (by using the `-o` flag and providing the relative file path `../build/hw`). The `build` folder must be created first if it does not exist (using `mkdir`).

The executable can be named anything (eg. `a.exe`), but a descriptive name like `hw.exe` (or just `hw`) is preferred.

Compilation and execution can be done either...
* ...with or without providing the `.exe` extention (the code block above does it without)
* ...with a forward slash `/` or backslash `\` (the code block above does it with `/`)

## Homework Instructions
* [HW 1: Basic Programming](/CS1336/instructions/HW1_BasicProgramming.pdf)
* [HW 2: Basic Calculations](/CS1336/instructions/HW2_BasicCalculations.pdf)
* [HW 3: Calculations Continued](/CS1336/instructions/HW3_CalculationsContinued.pdf)
* [HW 4: Calculations Review](/CS1336/instructions/HW4_CalculationsReview.pdf)
* [HW 5: Selection Logic](/CS1336/instructions/HW5_SelectionLogic.pdf)
* [HW 6: Looping 1](/CS1336/instructions/HW6_Looping1.pdf)
* [HW 7: Looping 2 and File Operations](/CS1336/instructions/HW7_Looping2AndFileOperations.pdf)
* [HW 8: Functions](/CS1336/instructions/HW8_Functions.pdf)
* [HW 9: Arrays](/CS1336/instructions/HW9_Arrays.pdf)

## src Folder
### Header File
* [hw_exercises.h](/CS1336/hw_exercises.h): contains 20 homework function prototypes
  * 0-0
  * 1-1, 1-2
  * 2-1, 2-2
  * 3-1, 3-2
  * 4-1
  * 5-1, 5-2, 5-2 BONUS
  * 6-1, 6-2
  * 7-1, 7-1 BONUS, 7-2
  * 8-1, 8-2
  * 9-1, 9-2

### Source Files
* [main.cpp](/CS1336/main.cpp): program driver containing main()
* [hw_exercises.cpp](/CS1336/hw_exercises.cpp): implementation of 20 homework functions and 12 helper functions

## data Folder
Input files need to be provided using their relative path (ie. with the prefix `../data/`). Output files are also created using the same prefix.
* HW 7-2:
  * [hw7ex2_NumListLong.txt](/CS1336/data/hw7ex2_NumListLong.txt): input file choice 1 (for standard output)
  * [hw7ex2_NumListShort.txt](/CS1336/data/hw7ex2_NumListShort.txt): input file choice 2 (for program testing)
* HW 8-1:
  * [hw8ex1_PrimeOut.txt](/CS1336/data/hw8ex1_PrimeOut.txt): output file
* HW 9-1:
  * [hw9ex1_LSStandard.txt](/CS1336/data/hw9ex1_LSStandard.txt): input file
  * [hw9ex1_LSTest.txt](/CS1336/data/hw9ex1_LSTest.txt): input file
* HW 9-2:
  * [hw9ex2_StudentsListLong.txt](/CS1336/data/hw9ex2_StudentsListLong.txt): input file choice 1 (for standard output)
  * [hw9ex2_StudentsListShort.txt](/CS1336/data/hw9ex2_StudentsListShort.txt): input file choice 2 (for program testing)
  * [hw9ex2_CorrectList.txt](/CS1336/data/hw9ex2_CorrectList.txt): input file
  * [hw9ex2_ExamAnalysis.txt](/CS1336/data/hw9ex2_ExamAnalysis.txt): output file
