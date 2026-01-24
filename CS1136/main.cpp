/*	Author:		Bushra Rahman
	Course:		CS 1136 (Spring 2019)
	main.cpp:	This source file contains the driver for the user to select which of the available 20 labs (excluding 1-1) they wish to execute. */

#include <iostream>         // for cout & cin in main()
#include <string>		    // for strings in main()
#include <vector>		    // for vector<> in main()
#include <utility>		    // for pair<> in main()
#include <limits>			// for numeric_limits for cin.ignore() in main()
#include "lab_exercises.h"	// header file containing all 21 lab exercise function declarations
using namespace std;



// Global struct to contain a lab exercise's nums as well as its function ptr.
struct LabExercise {
    /*	Use ints for a lab exercise's nums (not strings b/c it's more intuitive to contain numeric variables in ints;
		string conversion methods (stoi) can be used later in main() if needed). */
	int laboratoryNum;
    int exerciseNum;
	/*	Use a function pointer so that a function can be called using user input:
		1. *fp means a pointer* variable named fp
		2. (*fp)() means (*fp) points to a function()
		3. void (*fp)() means a pointer* fp to a function() that returns void
		So the resulting statement is (*fp) + void() = void (*fp)() */
    void (*fp)();
};
// Global array of LabExercise structs.
LabExercise LabExercises[20] = {
    {1, 2, lab1ex2},	// lab1ex2 here is NOT a string, it's the ADDRESS to the lab1ex2() function (located in lab_exercises.cpp)
    {2, 1, lab2ex1},	{2, 2, lab2ex2},	{2, 3, lab2ex3},
    {3, 1, lab3ex1},	{3, 2, lab3ex2},
    {4, 1, lab4ex1},	{4, 2, lab4ex2},
	{5, 1, lab5ex1},	{5, 2, lab5ex2},
	{6, 1, lab6ex1},	{6, 2, lab6ex2},
	{7, 1, lab7ex1},	{7, 2, lab7ex2},
	{8, 1, lab8ex1},	{8, 2, lab8ex2},
	{9, 1, lab9ex1},	{9, 2, lab9ex2},
    {10, 1, lab10ex1},	{10, 2, lab10ex2}
};



// main(): Driver for running lab exercises chosen by the user.
int main() {	
	// First, print LabExercises[20] in a 4x5 box for user to view.
	int numLabs = sizeof(LabExercises) / sizeof(LabExercises[0]);	// # of elements = total bytes divided by bytes of 1 element
	int linePrinter = 0;
	cout << "Lab Exercises:" << endl;
	for (int i = 0; i < numLabs; i++)
	{
		if (i >= 0 && i <= 17)	// excludes Lab 10 exercises (the last 2 indexes, i = 18 and i = 19)
		{
			cout << "| ";
		}
		else
		{
			cout << "|";		// do not print "| " for Lab 10 exercises b/c 10 is 2 digits, so "| " makes the printed box uneven
		}

		// print LabExercises[i] in the form #-#
		cout << LabExercises[i].laboratoryNum << "-" << LabExercises[i].exerciseNum;

		linePrinter++;				// once whatever needs to be printed is printed, iterate linePrinter
		if(linePrinter == 4)		// ensures 4 items per line so that printed box is 4x5
		{
			cout << " |" << endl;	// print box edge + newline for last item in a line
			linePrinter = 0;		// reset linePrinter
		}
		else
		{
			cout << " ";			// else, print space for item contained within a line
		}
	}
	cout << endl;



	//	Second, ask user to choose lab exercises.
	vector<pair<int, int>> userChoices;     // Use vector instead of array b/c it's unknown how many lab exercises the user will choose,
                                            // and make the vector contain std::pair structs to contain labNum and exNum provided by user.
	string userChoice;	                    // stores user's chosen lab exercise(s)

	bool quitLoop = false;
	while (quitLoop == false)               // while loop to continue asking user for userChoices until they exit
	{
		// 1st task: print out appropriate user prompt (depending on if user has already picked at least 1 correct lab) and read in user input
		if (userChoices.size() < 1)
		{
    		cout << "Pick a lab exercise (in the form #-#):" << endl;
		}
		else
		{
    		cout << "Pick another lab exercise (in the form #-#), or hit x (lowercase or uppercase) to exit:" << endl;
		}
		cin >> userChoice;

		// 2nd task: handle quit command (also depends on if user has already picked at least 1 correct lab)
		if ((userChoice == "x" || userChoice == "X"))
		{
			if (userChoices.size() < 1)
			{
				cout << "ERROR: You must pick at least one lab exercise before quitting." << endl;
			}
			else
			{
				quitLoop = true;
			}
		}
		// 3rd task: validate userChoice
		else
		{
			// use dash delimiter to parse userChoice for labNum substring and exNum substring
			string delimiter = "-";
			int labNum = 0;
			int exNum = 0;
			size_t delimiterPosition = userChoice.find(delimiter);
			if (delimiterPosition != string::npos)
			{
				// Extract substrings for each part and convert to int
				labNum = stoi(userChoice.substr(0, delimiterPosition));	// from start to dash: labNum
				exNum = stoi(userChoice.substr(delimiterPosition + 1));	// from after dash to end: exNum
    		}

			// loop through LabExercises for an exact match to labNum and exNum
			bool choiceMatches = false;
			for (int i = 0; i < numLabs; i++)
			{
				if (LabExercises[i].laboratoryNum == labNum && LabExercises[i].exerciseNum == exNum)
				{
					choiceMatches = true;
					userChoices.push_back({labNum, exNum});	// add int pair to vector storing valid userChoices
					break;									// no more need to continue looping through LabExercises
				}
			}

			if (choiceMatches == false)
			{
				cout << "ERROR: You must pick a valid lab exercise in the form specified." << endl;
			}
		}
	}
	cout << endl;



	// Third, loop through userChoices to call each choice's corresponding function.
	for (pair<int, int> choice : userChoices)	// for each int pair in the vector
	{
		// retrieve labNum and exNum from pair<int, int>
  		int labNum = choice.first;
		int exNum = choice.second;

		// same match-searching for loop logic from the previous while loop
		bool choiceMatches = false;
		for (int i = 0; i < numLabs; i++)
		{
			if (LabExercises[i].laboratoryNum == labNum && LabExercises[i].exerciseNum == exNum)
				{
					cout << "NOW EXECUTING LAB #" << labNum << " EXERCISE #" << exNum << ":" << endl << endl;
					LabExercises[i].fp();	// execute corresponding function using function ptr of the LabExercise struct at i
					cout << endl << "EXECUTION OF LAB #" << labNum << " EXERCISE #" << exNum << " COMPLETE" << endl;

					/*	Because some of the functions in lab_exercises.cpp rely on invalid user input to terminate,
						cin should be reset after each function call to ensure that future calls to cin 
						in subsequently called functions will properly take user input. */
					// This problem is most apparent for the termination condition of 8-1.
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					choiceMatches = true;	// no more need to continue looping through LabExercises
					break;
				}
		}
		if (choiceMatches == false)
		{
			// if earlier user input validation has been correctly managed, then this error message should never be reached
			cout << "ERROR: Lab #" << labNum << " Exercise #" << exNum << " does not exist." << endl;
		}
	}

	system("pause");
	return 0;
}
