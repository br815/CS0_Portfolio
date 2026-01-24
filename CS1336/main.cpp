/*	Author:		Bushra Rahman
	Course:		CS 1336 (Spring 2019)
	main.cpp:	This source file contains the driver for the user to select which of the available 17 homeworks they wish to execute
				(excluding 0-0 and excluding 5-2 BONUS and 7-1 BONUS, which are called automatically with 5-2 and 7-1 respectively). */

#include <iostream>         // for cout & cin in main()
#include <string>		    // for strings in main()
#include <vector>		    // for vector<> in main()
#include <utility>		    // for pair<> in main()
#include <limits>			// for numeric_limits for cin.ignore() in main()
#include "hw_exercises.h"	// header file containing all 20 homework exercise function declarations
using namespace std;



// Global struct to contain a hw exercise's nums as well as its function ptr.
struct HWExercise {
    /*	Use ints for a hw exercise's nums (not strings b/c it's more intuitive to contain numeric variables in ints;
		string conversion methods (stoi) can be used later in main() if needed). */
	int homeworkNum;
    int exerciseNum;
	/*	Use a function pointer so that a function can be called using user input:
		1. *fp means a pointer* variable named fp
		2. (*fp)() means (*fp) points to a function()
		3. void (*fp)() means a pointer* fp to a function() that returns void
		So the resulting statement is (*fp) + void() = void (*fp)() */
    void (*fp)();
};
// Global array of HWExercise structs.
HWExercise HWExercises[17] = {
	{1, 1, hw1ex1},	{1, 2, hw1ex2},	// hw1ex1 here is NOT a string, it's the ADDRESS to the hw1ex1() function (located in hw_exercises.cpp)
	{2, 1, hw2ex1},	{2, 2, hw2ex2},	
	{3, 1, hw3ex1},	{3, 2, hw3ex2},	
	{4, 1, hw4ex1},	
	{5, 1, hw5ex1},	{5, 2, hw5ex2}, 
	{6, 1, hw6ex1},	{6, 2, hw6ex2},	
	{7, 1, hw7ex1}, {7, 2, hw7ex2}, 
	{8, 1, hw8ex1},	{8, 2, hw8ex2},	
	{9, 1, hw9ex1},	{9, 2, hw9ex2}
};



// main(): Driver for running homework exercises chosen by the user.
int main() {	
	// First, print HWExercises[17] in a 4x5 box for user to view.
	int numHws = sizeof(HWExercises) / sizeof(HWExercises[0]);	// # of elements = total bytes divided by bytes of 1 element
	int linePrinter = 0;
	cout << "Homework Exercises:" << endl;
	for (int i = 0; i < numHws; i++)
	{
		// print HWExercises[i] in the form #-#
		cout << "| " << HWExercises[i].homeworkNum << "-" << HWExercises[i].exerciseNum;

		// once whatever needs to be printed is printed, iterate linePrinter
		linePrinter++;
		// ensures 4 items per line so that printed box is 4x5, and also includes the last element of the struct array
		if((linePrinter == 4) || (i == numHws - 1))
		{
			if (i == 8 || i == 11)
			{
				// if printing 5-2 or 7-1, print an asterisk
				cout << "*";
			}
			else
			{
				// else, print a space for last item in a line to precede the box edge
				cout << " ";
			}
			// print box edge + newline for last item in a line
			cout << "|" << endl;
			// reset linePrinter
			linePrinter = 0;
		}
		else
		{
			if (i == 8 || i == 11)
			{
				// if printing 5-2 or 7-1, print an asterisk
				cout << "*";
			}
			else
			{
				// else, print space for item contained within a line
				cout << " ";
			}
		}
	}
	cout << "*NOTE: Homeworks 5-2 and 7-1 include a *BONUS* exercise." << endl << endl;



	//	Second, ask user to choose hw exercises.
	vector<pair<int, int>> userChoices;     // Use vector instead of array b/c it's unknown how many hw exercises the user will choose,
                                            // and make the vector contain std::pair structs to contain hwNum and exNum provided by user.
	string userChoice;	                    // stores user's chosen hw exercise(s)

	bool quitLoop = false;
	while (quitLoop == false)               // while loop to continue asking user for userChoices until they exit
	{
		// 1st task: print out appropriate user prompt (depending on if user has already picked at least 1 correct hw) and read in user input
		if (userChoices.size() < 1)
		{
    		cout << "Pick a homework exercise (in the form #-#):" << endl;
		}
		else
		{
    		cout << "Pick another homework exercise (in the form #-#), or hit x (lowercase or uppercase) to exit:" << endl;
		}
		cin >> userChoice;

		// 2nd task: handle quit command (also depends on if user has already picked at least 1 correct hw)
		if ((userChoice == "x" || userChoice == "X"))
		{
			if (userChoices.size() < 1)
			{
				cout << "ERROR: You must pick at least one homework exercise before quitting." << endl;
			}
			else
			{
				quitLoop = true;
			}
		}
		// 3rd task: validate userChoice
		else
		{
			// use dash delimiter to parse userChoice for hwNum substring and exNum substring
			string delimiter = "-";
			int hwNum = 0;
			int exNum = 0;
			size_t delimiterPosition = userChoice.find(delimiter);
			if (delimiterPosition != string::npos)
			{
				// Extract substrings for each part and convert to int
				hwNum = stoi(userChoice.substr(0, delimiterPosition));	// from start to dash: hwNum
				exNum = stoi(userChoice.substr(delimiterPosition + 1));	// from after dash to end: exNum
    		}

			// loop through HWExercises for an exact match to hwNum and exNum
			bool choiceMatches = false;
			for (int i = 0; i < numHws; i++)
			{
				if (HWExercises[i].homeworkNum == hwNum && HWExercises[i].exerciseNum == exNum)
				{
					choiceMatches = true;
					userChoices.push_back({hwNum, exNum});	// add int pair to vector storing valid userChoices
					break;									// no more need to continue looping through HWExercises
				}
			}

			if (choiceMatches == false)
			{
				cout << "ERROR: You must pick a valid homework exercise in the form specified." << endl;
			}
		}
	}
	cout << endl;



	// Third, loop through userChoices to call each choice's corresponding function.
	for (pair<int, int> choice : userChoices)	// for each int pair in the vector
	{
		// retrieve hwNum and exNum from pair<int, int>
  		int hwNum = choice.first;
		int exNum = choice.second;

		// same match-searching for loop logic from the previous while loop
		bool choiceMatches = false;
		for (int i = 0; i < numHws; i++)
		{
			if (HWExercises[i].homeworkNum == hwNum && HWExercises[i].exerciseNum == exNum)
				{
					cout << "NOW EXECUTING HW #" << hwNum << " EXERCISE #" << exNum << ":" << endl << endl;
					HWExercises[i].fp();	// execute corresponding function using function ptr of the HWExercise struct at i
					cout << endl << "EXECUTION OF HW #" << hwNum << " EXERCISE #" << exNum << " COMPLETE" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					// if user chose to execute 5-2 or 7-1, automatically execute their corresponding BONUS exercise as well
					if((hwNum == 5 && exNum == 2) || (hwNum == 7 && exNum == 1))
					{
						cout << "NOW EXECUTING HW #" << hwNum << " EXERCISE #" << exNum << " *BONUS*:" << endl << endl;
						if (hwNum == 5 && exNum == 2)
						{
							hw5ex2_BONUS();	// bonus exercise is called directly, instead of bothering with a function ptr
						}
						else if (hwNum == 7 && exNum == 1)
						{
							hw7ex1_BONUS();
						}
						cout << endl << "EXECUTION OF HW #" << hwNum << " EXERCISE #" << exNum << " *BONUS* COMPLETE" << endl;
						
						/*	Because some of the functions in hw_exercises.cpp rely on invalid user input to terminate,
						cin should be reset after each function call to ensure that future calls to cin 
						in subsequently called functions will properly take user input. */
						// This may require the user to press any key to execute the next part of main() after certain function calls (eg. 1-1 then 1-2).
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}

					choiceMatches = true;	// no more need to continue looping through HWExercises
					break;
				}
		}
		if (choiceMatches == false)
		{
			// if earlier user input validation has been correctly managed, then this error message should never be reached
			cout << "ERROR: HW #" << hwNum << " Exercise #" << exNum << " does not exist." << endl;
		}
	}

	system("pause");
	return 0;
}