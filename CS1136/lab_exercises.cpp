/*	Author:				Bushra Rahman
	Course:				CS 1136 (Spring 2019)
	lab_exercises.cpp:	This source file contains every lab exercise as its own function returning void.
						There are 21 total lab exercises: 2 exercises for Lab 1 (1-1 being a skeleton function),
						3 exercises for Lab 2, and 2 exercises for each of the remaining Labs 3 through 10. */

#include <iostream>		// 1-2, 2-1, 2-2, 2-3, 3-1, 3-2, 4-1, 4-2, 5-1, 5-2, 6-1, 6-2, 7-1, 7-2, 8-1, 8-2, 9-1, 9-2, 10-1, 10-2
#include <iomanip>		// ...       2-2,      3-1, 3-2, 4-1, 4-2, 5-1, 5-2, 6-1, 6-2, 7-1, 7-2, 8-1, 8-2, 9-1, 9-2, 10-1, 10-2
#include <ios>			// ...                      3-2, 4-1, 4-2, 5-1, 5-2, 6-1, 6-2, 7-1, 7-2, 8-1, 8-2, 9-1, 9-2, 10-1, 10-2
#include <fstream>		// ...                                                         7-1, 7-2,                9-2, 10-1, 10-2
#include <string>		// ...                                                         7-1, 7-2,                9-2, 10-1, 10-2
#include <cmath>		// ...                                                                   8-1, 8-2, 9-1, 9-2, 10-1, 10-2
#include <sstream>		// ...                                                                                             10-2
using namespace std;



// function prototypes for Lab #8 Exercise #1
double lab8ex1_readSeconds();
double lab8ex1_calculateDistance(double seconds);
void lab8ex1_displayResults(double seconds, double distance);

// function prototypes for Lab #8 Exercise #2
double lab8ex2_readFutureValue();
double lab8ex2_readAnnualRate();
int lab8ex2_readYears();
double lab8ex2_calculatePresentValue(double futureValue, double interestRate, int numberYears);
void lab8ex2_displayResults(double presentValue, double futureValue, double interestRate, int numberYears);

// function prototypes for Lab #9 Exercise #1
void lab9ex1_getInputs(int & intSpoolsOrdered, int & intSpoolsInStock, double & shippingAndHandlingCharges);
void lab9ex1_displayOutput(int intSpoolsOrdered, int intSpoolsInStock, double shippingAndHandlingCharges);
// global constant indicating the price of each spool for Lab #9 Exercise #1
const double lab9ex1_DBL_SPOOL_PRICE = 100.00;

// function prototypes for Lab #9 Exercise #2
unsigned int lab9ex2_getInput(ifstream & inputFile, double & presentValue, double & monthlyInterestRate, int & numMonths);
double lab9ex2_calculateFutureValue(double presentValue, double interestRate, int months);
void lab9ex2_writeOutput(ofstream & outputFile, double & futureValue, double & presentValue, double & monthlyInterestRate, int & numMonths, bool & writeHeader);

// global constant indicating the number of questions in any set of responses for Lab #10 Exercise #1
const int lab10ex1_ARRAY_SIZE = 20;
// function prototypes for Lab #10 Exercise #1
bool lab10ex1_readArray(char response[lab10ex1_ARRAY_SIZE], string inputFileName);
void lab10ex1_displayResults(char studentResponses[lab10ex1_ARRAY_SIZE], char correctResponses[lab10ex1_ARRAY_SIZE]);

// global constants indicating maximum 2D array dimensions for Lab #10 Exercise #2
const int lab10ex2_MAX_ROWS = 20;
const int lab10ex2_MAX_COLUMNS = 5;
// function prototypes for Lab #10 Exercise #2
int lab10ex2_readFile(double grades[][lab10ex2_MAX_COLUMNS], int maxRowsToRead, string inputFileName);
double lab10ex2_average(double values[][lab10ex2_MAX_COLUMNS], int numberRows);
double lab10ex2_columnAverage(double values[][lab10ex2_MAX_COLUMNS], int column, int numberRows);
double lab10ex2_smallestValue(double values[][lab10ex2_MAX_COLUMNS], int currentRow);



/*	Lab #1 Exercise #1 (Date): 
	This assignment is a skeleton function. */
void lab1ex1() {
	cout << "This is Lab #1 Exercise #1, a skeleton function." << endl;
}



 /*	Lab #1 Exercise #2 (2/3/2019): 
 	This assignment calculates the user's ending balance.
	Convert the following pseudocode into a program:
    └── Display "Enter the starting balance"
    └── Input balance
    └── Display "Enter total deposits"
    └── Input deposits
    └── Display "Enter total withdrawals"
    └── Input withdrawals
    └── Store the value of balance plus deposits minus withdrawals in variable endingBalance
    └── Display "The ending balance is " endingBalance */
void lab1ex2() {

    double balance, deposits, withdrawals, endingBalance;

	// Get the starting balance
	cout << "Please enter your starting balance:" << endl;
	cin >> balance;

	// Get the deposits
	cout << "Please enter your total deposits:" << endl;
	cin >> deposits;

	// Get the withdrawals
	cout << "Please enter your total withdrawals:" << endl;
	cin >> withdrawals;

	// Calculate the ending balance
	endingBalance = balance + deposits - withdrawals;

	// Output the results
	cout << "Your ending balance is $" << endingBalance << "." << endl;
}



/*	Lab #2 Exercise #1 (2/10/2019): 
	This assignment computes the total sales tax on a $95 purchase, 
	wherein the state sales tax is 6% and the county sales tax is 2%. */
void lab2ex1() {
	double purchasePrice = 95;		// cost of the purchase, $95
	double stateSalesTax = 0.06;	// state sales tax of 6%
	double countySalesTax = 0.02;	// county sales tax of 2%
	double totalSalesTax;			// will hold total sales tax
	totalSalesTax = purchasePrice * stateSalesTax + purchasePrice * countySalesTax; //total sales tax is equal to 6% of 95 plus 2% of 95
	
	cout << "Purchase price = $" << purchasePrice << endl;
	cout << "State sales tax = " << stateSalesTax << endl;
	cout << "County sales tax = " << countySalesTax << endl;
	cout << "The total sales tax on a $95 purchase, with 6" << '%' << " states sales tax and 2" << '%' << " county sales tax, is " << totalSalesTax << '%' << "." << endl;
}



/*	Lab #2 Exercise #2 (2/10/2019): 
	This assignment calculates the rise in ocean levels over 5, 10, and 50 years. */
void lab2ex2() {
	cout << "Please enter the rise in ocean levels per year in millimeters: ";
	double risingLevel;							// rise in ocean levels (per year) in millimeters
	cin >> risingLevel;							// read in the estimated rising ocean level
	cout << "Level: " << risingLevel << endl;	// output the estimated rising ocean level

	risingLevel = risingLevel * 5;				// the raise in mm over 5 years
	cout << "Years: 5, Rise: " << risingLevel << endl;

	risingLevel = risingLevel * 2;				// the raise in mm over 10 years; multiplies by 2 because 5*2 is 10
	cout << "Years: 10, Rise: " << risingLevel << endl;

	risingLevel = risingLevel * 5;				// the raise in mm over 50 years; multiplies by 5 because 10*5 is 50
	cout << "Years: 50, Rise: " << risingLevel << endl;
}



/*	Lab #2 Exercise #3 (2/10/2019): 
	This assignment consists of a number of cout statements to output two shapes: 
	a rectangle (10x10) and a triangle (with a base of 11 characters). */
void lab2ex3() {
	
	cout << "  SQUARE   " << endl;
	cout << "@@@@@@@@@@" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@        @" << endl;
	cout << "@@@@@@@@@@" << endl << endl;

	cout << "  TRIANGLE" << endl;
	cout << "     %" << endl;
	cout << "    % %" << endl;
	cout << "   %   %" << endl;
	cout << "  %     %" << endl;
	cout << " %       %" << endl;
	cout << "%%%%%%%%%%%" << endl;
}



/*	Lab #3 Exercise #1 (2/17/2019): 
	This assignment calculates the average of five inputted test scores. */
void lab3ex1() {
	cout << fixed << setprecision(1);

	double score1, score2, score3, score4, score5;   // each variable holds the respective test score

	cout << "Please enter five test scores:" << endl;
	cin >> score1;
	cin >> score2;
	cin >> score3;
	cin >> score4;
	cin >> score5;

	double scoreAvg;                                 // the average of the five scores
	scoreAvg = (score1 + score2 + score3 + score4 + score5) / 5;

	cout << "Test score average: " << scoreAvg << endl;
}



/*	Lab #3 Exercise #2 (2/17/2019): 
	This assignment converts an inputted amount in US dollars to yen, euros, and pesos. */
void lab3ex2() {
	cout << fixed << setprecision(2);

	cout << "Please enter an amount of money in US dollars: ";
	double dollarsUS;				// user-given amount in dollars
	cin >> dollarsUS;

	const double yen = 113.27;		// dollars-to-yen conversion rate
	const double euros = 0.84;		// dollars-to-euros conversion rate
	const double pesos = 19.73;		// dollars-to-pesos conversion rate

	double yenJP;					// amount in Japanese yen
	yenJP = yen * dollarsUS;

	double eurosEU;					// amount in EU euros
	eurosEU = euros * dollarsUS;

	double pesosMX;					// amount in Mexican pesos
	pesosMX = pesos * dollarsUS;

	cout << setw(15) << right << "Dollars" << setw(15) << "Yen" << setw(15) << "Euros" << setw(15) << "Pesos" << endl;
	cout << setw(15) << right << dollarsUS << setw(15)  << yenJP << setw(15) << eurosEU << setw(15) << pesosMX << endl;
}



/*	Lab #4 Exercise #1 (2/24/2019): 
	This assignment reads in the mass of an object (in kg) 
	and outputs the weight (in N) on the Earth, on the Moon, and on Venus. */
void lab4ex1() {
	cout << fixed << setprecision(4);

	double objMass;			// object's mass in kilograms

	cout << "Please enter the mass of an object in kilograms: ";
	cin >> objMass;

	if (objMass <= 0)		// scenario if object's mass invalid (less than or equal to zero)
	{
		cout << "The mass is " << objMass << " kg" << endl;
		cout << "The mass must be greater than zero kg" << endl;
	}
	else if (objMass > 0)	// scenario if object's mass is valid (greater than zero)
	{
		const double accelEarth = 9.81;		// 9.81 meters per second squared = acceleration due to gravity on Earth
		const double accelMoon = 1.62;		// 1.62 meters per second squared = acceleration due to gravity on the Moon
		const double accelVenus = 8.87;		// 8.87 meters per second squared = acceleration due to gravity on Venus

		double weightEarth = objMass * accelEarth;	// weight in Newtons of the object on Earth
		double weightMoon = objMass * accelMoon;	// weight in Newtons of the object on the Moon
		double weightVenus = objMass * accelVenus;	// weight in Newtons of the object on Venus

		cout << "The mass is " << objMass << " kg" << endl;
		cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)"
			<< endl;
		cout << setw(8) << left << "Earth " << setw(14) << right << weightEarth
			<< endl;
		cout << setw(8) << left << "Moon " << setw(14) << right << weightMoon
			<< endl;
		cout << setw(8) << left << "Venus " << setw(14) << right << weightVenus
			<< endl;

		if (weightEarth >= 1500)			// notes the object as heavy if its weight on Earth is >= 1500
		{
			cout << "This object is heavy." << endl;
		}
		else if (weightEarth < 5)			// notes the object as light if its weight on Earth is < 5
		{
			cout << "This object is light." << endl;
		}
	}
}



/*	Lab #4 Exercise #2 (3/3/2019): 
	This assignment reads in a number of seconds and converts it 
	to days, hours, minutes, and remaining seconds, depending on the amount. */
void lab4ex2() {
	cout << fixed << setprecision(4);

	long long int numSeconds;

	//input number of seconds
	cout << "Please enter the total number of seconds: ";
	cin >> numSeconds;
	cout << numSeconds << " seconds is equivalent to:" << endl;
	
	if (numSeconds <= 0)								// the inputted amount is invalid (zero or less)
	{
		cout << "Total seconds must be greater than zero" << endl;
	}

	long long int numDays = numSeconds / 60/ 60/ 24;	// the number of days within these seconds
	if (numDays > 0)									// prints only if it's greater than zero
	{
		cout << numDays << " day(s)" << endl;
	}
	
	numSeconds = numSeconds - numDays * 60 * 60 * 24;	// update the number of seconds to exclude the days within it
	long long int numHrs = numSeconds / 60 / 60;		// the number of hours within these seconds
	if (numHrs > 0)										// prints only if it's greater than zero
	{
		cout << numHrs << " hour(s)" << endl;
	}

	numSeconds = numSeconds - numHrs * 60 * 60;			// update the number of seconds to exclude the days + hrs within it
	long long int numMins = numSeconds / 60;			// the number of minutes within these seconds
	if (numMins > 0)									// prints only if it's greater than zero
	{
		cout << numMins << " minute(s)" << endl;
	}

	numSeconds = numSeconds - numMins * 60;				// update the number of seconds to exclude days + hrs + mins
	if (numSeconds > 0)									// all that remains is the seconds; prints only if it's greater than zero
	{
		cout << numSeconds << " second(s)" << endl;
	}
}



/*	Lab #5 Exercise #1 (3/25/2019): 
	This assignment calculates the number of seconds it will take for sound to travel though a medium. 
	The structure used is a switch menu. */
void lab5ex1() {
	unsigned int medium;	// holds the value 1, 2, or 3, corresponding to the user's choice
	double distance;		// the distance value inputted by the user
	double seconds;			// the seconds taken by the sound to travel through the medium; seconds = distance/a constant

	cout << fixed << setprecision(3);

	cout << "Select the medium that sound is traveling through:" << endl;	// displays the menu
	cout << "1 Air" << endl << "2 Water" << endl << "3 Steel" << endl;
	cin >> medium;			// user inputs their choice of 1, 2, or 3

	switch (medium)
	{
	case 1: cout << "Enter distance (in feet)" << endl;
		cin >> distance;
		if (distance <= 0)
		{
			cout << "The distance must be greater than zero" << endl;
		}
		else
		{
			seconds = distance / 1100;
			cout << "Air: " << distance << " ft" << endl;
			cout << "Traveled for " << seconds << " seconds" << endl;
		}
		break;
	case 2: cout << "Enter distance (in feet)" << endl;
		cin >> distance;
		if (distance <= 0)
		{
			cout << "The distance must be greater than zero" << endl;
		}
		else
		{
			seconds = distance / 4900;
			cout << "Water: " << distance << " ft" << endl;
			cout << "Traveled for " << seconds << " seconds" << endl;
		}
		break;
	case 3: cout << "Enter distance (in feet)" << endl;
		cin >> distance;
		if (distance <= 0)
		{
			cout << "The distance must be greater than zero" << endl;
		}
		else
		{
			seconds = distance / 16400;
			cout << "Steel: " << distance << " ft" << endl;
			cout << "Traveled for " << seconds << " seconds" << endl;
		}
		break;
	default: cout << "The menu value is invalid. Please run the program again." << endl;
	}
}



/*	Lab #5 Exercise #2 (3/25/2019): 
	This assignment calculates the speed that sound takes to travel through gases at 0 degrees centigrade. 
	The structure used is an if-else if-else block. */
void lab5ex2() {
	unsigned int medium;	// holds the value 1, 2, 3, or 4, corresponding to the user's choice
	double seconds;			// the seconds value inputted by the user
	double distance;		// the distance the sound travels through the medium in the given seconds; distance = seconds * a constant

	cout << "Select the medium that sound is traveling through:" << endl;
	cout << "1 Carbon Dioxide" << endl << "2 Air" << endl << "3 Helium" << endl << "4 Hydrogen" << endl;
	cin >> medium;

	if (medium == 0 || medium > 4)
	{
		cout << "The menu value is invalid. Please run the program again." << endl;
	}
	else if (medium == 1)
	{
		cout << "Enter time (in seconds)" << endl;
		cin >> seconds;
		if (seconds < 0 || seconds > 30)
		{
			cout << "The time must be between 0.00 and 30.00 (inclusive)" << endl;
		}
		else
		{
			distance = 258 * seconds;
			cout << fixed << setprecision(2) << "Carbon Dioxide: " << seconds << " seconds" << endl;
			cout << fixed << setprecision(3) << "Traveled " << distance << " meters" << endl;
		}
	}
	else if (medium == 2)
	{
		cout << "Enter time (in seconds)" << endl;
		cin >> seconds;
		if (seconds < 0 || seconds > 30)
		{
			cout << "The time must be between 0.00 and 30.00 (inclusive)" << endl;
		}
		else
		{
			distance = 331.5 * seconds;
			cout << fixed << setprecision(2) << "Air: " << seconds << " seconds" << endl;
			cout << fixed << setprecision(3) << "Traveled " << distance << " meters" << endl;
		}
	}
	else if (medium == 3)
	{
		cout << "Enter time (in seconds)" << endl;
		cin >> seconds;
		if (seconds < 0 || seconds > 30)
		{
			cout << "The time must be between 0.00 and 30.00 (inclusive)" << endl;
		}
		else
		{
			distance = 972 * seconds;
			cout << fixed << setprecision(2) << "Helium: " << seconds << " seconds" << endl;
			cout << fixed << setprecision(3) << "Traveled " << distance << " meters" << endl;
		}
	}
	else
	{
		cout << "Enter time (in seconds)" << endl;
		cin >> seconds;
		if (seconds < 0 || seconds > 30)
		{
			cout << "The time must be between 0.00 and 30.00 (inclusive)" << endl;
		}
		else
		{
			distance = 1270 * seconds;
			cout << fixed << setprecision(2) << "Hydrogen: " << seconds << " seconds" << endl;
			cout << fixed << setprecision(3) << "Traveled " << distance << " meters" << endl;
		}
	}
}



/*	Lab #6 Exercise #1 (3/31/2019): 
	This assignment outputs the characters that map to the ASCII codes 32 through 126.
	A loop is used to iterate through the input values and output the corresponding character. */
void lab6ex1() {
	unsigned int lowerVal;    // the lower-limit numeric value, inputted by the user
	unsigned int upperVal;    // the upper-limit numeric value, inputted by the user

	cout << "Please enter lower and upper ASCII values:" << endl;
	cin >> lowerVal >> upperVal;
	
	//while-loop for input validation, checks that both vals are within [32, 126] and in ascending order
	while (lowerVal < 32 || upperVal < 32 || lowerVal > 126 || upperVal > 126 || lowerVal > upperVal)
	{
		cout << "ERROR: Values must be in range 32 to 126 inclusive." << endl;
		cout << "Please enter lower and upper ASCII values:" << endl;
		cin >> lowerVal >> upperVal;
	}

	char lower = lowerVal;    // the character corresponding to the lower-limit numeric value
	char upper = upperVal;    // the character corresponding to the upper-limit numeric value 

	cout << "Characters for ASCII values between " << lowerVal << " and " << upperVal << ":" << endl;
	cout << "----+----+----+-" << endl;

	unsigned int i;               // for-loop counter used to loop through the user-specified range
	unsigned int counter = 0;     // counter to check if 16 characters has been reached in each line

	// for-loop that loops through the characters within the user-specified range
	for (i = lowerVal; i <= upperVal; i++)
	{
		cout << lower++;
		counter++;

		// if-block that checks if a new line must be created
		if (counter == 16 && i != upperVal)
		{
			cout << endl;
			counter = 0;
		}
	}

	cout << endl << "----+----+----+-" << endl;
}



/*	Lab #6 Exercise #2 (3/31/2019): 
	This assignment converts a set of temperatures from Fahrenheit to Celsius. */
void lab6ex2() {
	cout << fixed << setprecision(5);
	
	cout << "Please enter a starting Fahrenheit temperature, an ending Fahrenheit temperature, and an increment value:" << endl;
	// example values: 10, 100, 30: results in 10, 40, 70, and 100 degrees Fahrenheit for conversion to Celsius
	double startingVal;
	cin >> startingVal;
	double endingVal;
	cin >> endingVal;
	double incrementVal;
	cin >> incrementVal;

	// while-loop to validate user input
	while (startingVal > endingVal || incrementVal <= 0)
	{
		cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
		cin >> startingVal;
		cin >> endingVal;
		cin >> incrementVal;
	}

	double fVal;	// for-loop counter; assigned to every value between [startingVal, endingVal]
	double cVal;	// celsius value that is calculated from every fVal (fahrenheit value)

	cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << endl;

	// for-loop that creates the table of Fahrenheit and Celsius values
	for(fVal = startingVal; fVal <= endingVal; fVal += incrementVal)
	{
		cVal = (fVal - 32) / 1.8;
		cout << setw(18) << fVal << setw(18) << cVal << endl;
	}
}



/*	Lab #7 Exercise #1 (4/7/2019): 
	This assignment reads sales information from a file
	and writes out a bar chart for each of the stores. */
void lab7ex1() {
	// creates an input file and gets its name from the user
	ifstream inputFile;
	string inputFileName;
	cout << "Please enter the name of the sales information input file: ";
	cin >> inputFileName;			// the input file provided is lab7ex1_sales.txt

	inputFile.open(inputFileName);

	int validRecordCounter = 0;		// tracks the number of valid values in the input file
	unsigned int storeNum;			// value in input file that is the store number
	long long int salesAmt;			// value in input file that is the sales amount
	bool validInput;				// checks for valid input
	int numX;						// number of X's that will be used in the bar chart
	string strX;					// string that displays the X's in the form of a bar chart

	// the input file opened successfully
	if (inputFile)
	{
		ofstream outputFile;
		outputFile.open("lab7ex1_saleschart.txt");

		// the output file opened successfully 
		if (outputFile)
		{
			// processes the values in the input file
			while (inputFile >> storeNum >> salesAmt)
			{
				validInput = true;  // initialize the validity check to true

				// checks that storeNum is within the range [1, 99]; if not, the validity check is false
				if (storeNum < 1 || storeNum > 99)
				{
					cout << "The store number " << storeNum << " is not valid" << endl;
					validInput = false;
				}
				// checks that salesAmt is positive; if not, the validity check is false
				if (salesAmt < 0)
				{
					cout << "The sales value for store " << storeNum << " is negative" << endl;
					validInput = false;
				}

				// if the validity check is true, meaning the previous two validity tests were passed
				if (validInput == true)
				{
					validRecordCounter++;

					// begins writing into the output file
					if (validRecordCounter == 1)
					{
						outputFile << "SALES BAR CHART" << endl << "(Each X equals 1,000 dollars)" << endl;
					}
					numX = salesAmt / 1000;
					strX.assign(numX, 'X');
					outputFile << "Store " << setw(2) << storeNum << ": " << strX << endl;

				}
			}

			outputFile.close();
			inputFile.close();
		}
		// the output file did not open successfully
		else
		{
			cout << "ERROR: File \"lab7ex1_saleschart.txt\" could not be opened." << endl;
		}
	}
	// the input file did not open successfully
	else
	{
	cout << "ERROR: File \"" << inputFileName << "\" could not be opened." << endl;
	}
}



/*	Lab #7 Exercise #2 (4/7/2019): 
	This assignment reads numbers from a file.
	It validates the numbers and calculates the average of all of the valid numbers.
	Additionally, it writes invalid values to another file. */
void lab7ex2() {
	// create the input file and get its name from the user
	ifstream inputFile;
	string inputFileName;
	cout << "Please enter the name of the input file containing values to be averaged: ";
	cin >> inputFileName;			// the input file provided is lab7ex2_avg.txt

	inputFile.open(inputFileName);

	int validRecordCounter = 0;		// tracks the number of valid values in the input file
	int invalidRecordCounter = 0;	// tracks the number of invalid values in the input file
	double value;					// values in the input file
	double avg = 0;					// average of the values in the input file
	double sum = 0;					// sum of the values in the input file

	// the input file opened successfully
	if (inputFile)
	{
		// creates the output file for invalid values
		ofstream outputFile;
		outputFile.open("lab7ex2_invalids.txt");

		cout << "Reading from file \"" << inputFileName << "\"" << endl;

		// the output file opened successfully 
		if (outputFile)
		{
			// processes the values in the input file
			while (inputFile >> value)
			{
				outputFile << fixed << setprecision(4);
				
				// checks for invalid values in the input file and updates the corresponding counter
				if (value < 0 || value > 110)
				{
				outputFile << value << endl;
				invalidRecordCounter++;
				}
				// checks for valid values in the input file and updates the corresponding counter
				else
				{
				validRecordCounter++;
				sum += value;                             // calculation of the sum
				avg = sum / validRecordCounter;           // calculation of the average
				}
			}
			cout << "Total values: " << (validRecordCounter + invalidRecordCounter) << endl;
			cout << "Invalid values: " << invalidRecordCounter << endl;
			cout << "Valid values: " << validRecordCounter << endl;
			if (validRecordCounter >= 1)
			{
				cout << "Average of valid values: " << fixed << setprecision(3) << avg << endl;
			}
			else
			{
				cout << "An average cannot be calculated" << endl;
			}
			outputFile.close();
			inputFile.close();
		}
		// the output file did not open successfully
		else
		{
			cout << "ERROR: File \"lab7ex2_invalids\" could not be opened." << endl;
		}
	}
	// the input file did not open successfully
	else
	{
		cout << "ERROR: File \"" << inputFileName << "\" could not be opened." << endl;
	}
}



/*	Lab #8 Exercise #1 (4/14/2019): 
	This assignment uses 3 helper functions (with prototypes) in addition to its driver function.
	The 1st function reads in the amount of time in seconds from the user,
	the 2nd function calculates the distance fallen by an object in those seconds,
	and the 3rd function displays those results. */
void lab8ex1() {
	// This driver function body was formerly contained within main() of lab8ex1's own source file.
	
	double seconds = -1;	/*	user-inputted seconds, initialized to negative so that it will
                                change to positive when a valid value is entered */
	double distance = -1;   /*	calculated distance, initialized to negative so that it will
								change to positive in a valid input scenario */
	bool keepRunning = true;	// checks whether the program should continue or terminate

	// uses keepRunning to continue the program for valid input
	while (keepRunning)
	{
		// condition for the first function to occur
		while (seconds < 0)
		{
			seconds = lab8ex1_readSeconds();
		}

		// condition for the second and third function to occur
		if (seconds > 0)
		{
			distance = lab8ex1_calculateDistance(seconds);
			lab8ex1_displayResults(seconds, distance);
			seconds = -1;
		}
		else
		{
			keepRunning = false;	// terminate the while loop
		}
	}
}
/*	Helper Function:	lab8ex1_readSeconds()
	Descr:				This function reads in the double value for the amount of seconds the object falls for.
						The function displays a prompt, reads in the seconds, and notifies the user if the input is invalid.
	Input:				None.
	Return:				double seconds
						The first value that is read in. */
double lab8ex1_readSeconds() {
	double seconds;
	cout << "Please enter the time (in seconds), or enter 0 or any non-number character(s) to exit:" << endl;
	cin >> seconds;

	if (seconds < 0)
	{
		cout << "ERROR: The time must be zero or more." << endl;
	}

	return seconds;
}
/*	Helper Function:	lab8ex1_calculateDistance()
	Descr:				This function calculates the distance that is travelled by the object using the general formula
						d = 0.5 * g * pow(t, 2).
	Input:				double seconds
						The user-inputted time value.
	Return:				double distance
						The distance fallen, the result of the function's calculations. */
double lab8ex1_calculateDistance(double seconds) {
	double distance = 0;
	const double gravity = 9.8;
	distance = 0.5 * gravity * pow(seconds, 2);

	return distance;
}
/*	Helper Function:	lab8ex1_displayResults()
	Descr:    			This function displays the values that have thus far been used in the assignment:
						the distance travelled, which was calculated; and the seconds travelled for, which was user-inputted.
	Input:				double seconds, double distance
						The user-inputted time value, and the calculated distance value.
	Return:				None. */
void lab8ex1_displayResults(double seconds, double distance) {
	cout << "The object traveled " << fixed << setprecision(3) << distance << " meters in " << fixed << setprecision(2) << seconds << " seconds." << endl;
}



/*	Lab #8 Exercise #2 (4/14/2019): 
	This assignment uses 5 helper functions (with prototypes) in addition to its driver function.
	The first 3 functions read in the user's desired future amount in their bank account,
	their account's annual interest rate, and the amount of years they'll wait.
	The following function calculates the amount that must be deposited now,
	and the last function displays these results. */
void lab8ex2() {
	// This driver function body was formerly contained within main() of lab8ex2's own source file.

	double futureValue = lab8ex2_readFutureValue();
	double interestRate = lab8ex2_readAnnualRate();
	int numberYears = lab8ex2_readYears();
	double presentValue = lab8ex2_calculatePresentValue(futureValue, interestRate, numberYears);

	lab8ex2_displayResults(presentValue,futureValue, interestRate, numberYears);
}
/*	Helper Function:	lab8ex2_readFutureValue()
	Descr:				This function reads in the double value for the user's desired future amount in their bank account.
						The function displays a prompt, reads in the future value, and then validates the input with a while-loop.
	Input:				None.
	Return:				double futureValue
						The first valid future value that is read in. */
double lab8ex2_readFutureValue() {
	double futureValue = -1;
	cout << "Please enter the desired future value for your bank account:" << endl;
	cin >> futureValue;

	while (futureValue == 0 || futureValue < 0)
	{
		cout << "ERROR: The future value must be greater than zero." << endl;
		cout << "Please enter the desired future value for your bank account:" << endl;
		cin >> futureValue;
	}

	return futureValue;
}
/*	Helper Function:	lab8ex2_readAnnualRate()
	Descr:				This function reads in the annual rate of interest for the user's bank account.
						The function displays a prompt, reads in the interest rate, and then validates the input with a while-loop.
	           			This inputted rate is considered a percentage, and is converted to a decimal in the return statement.
	Input:				None.
	Return:				double (interestRate / 100.0)
						The first valid future interest rate that is read in, divided by 100
						to convert it to a decimal for further calculations in a later function. */
double lab8ex2_readAnnualRate() {
	double interestRate = -1;
	cout << "Please enter the annual interest rate:" << endl;
	cin >> interestRate;

	while (interestRate == 0 || interestRate < 0)
	{
		cout << "ERROR: The annual interest rate must be greater than zero." << endl;
		cout << "Please enter the annual interest rate:" << endl;
		cin >> interestRate;
	}

	return (interestRate / 100.0);
}
/*	Helper Function:	lab8ex2_readYears()
	Descr:				This function reads in the number of years the user will leave their present deposit in their bank account
						to accumulate interest. The function displays a prompt, reads in the number of years, and then
						validates the input with a while-loop.
	Input:				None.
	Return:				int numYears
						The first valid number of years that is read in. */
int lab8ex2_readYears() {
	int numYears = -1;
	cout << "Please enter number of years to accumulate interest:" << endl;
	cin >> numYears;

	while (numYears == 0 || numYears < 0)
	{
		cout << "ERROR: The number of years must be greater than zero." << endl;
		cout << "Please enter number of years to accumulate interest:" << endl;
		cin >> numYears;
	}

	return numYears;
}
/*	Helper Function:	lab8ex2_calculatePresentValue()
	Descr:    			This function uses the general formula "P = F / ((1 + r)^n)" to  calculate the present value,
						the amount that must presently be deposited in the user's account.
	Input:    			double futureValue, double interestRate, int numberYears
						The future value, interest rate, and number of years that were previously read in by the last 3 functions.
	Return:				double presentValue
						The present value, the result of the function's calculations. */
double lab8ex2_calculatePresentValue(double futureValue, double interestRate, int numberYears) {
	double presentValue = 0;
	presentValue = futureValue / (pow(1 + interestRate, numberYears));

	return presentValue;
}
/*	Helper Function:	lab8ex2_displayResults()
	Descr:				This function displays the values that have thus far been used in the program:
						1) the present value to deposit, which was calculated, 
						2) the future/desired value,
						3) the annual interest rate (in its percentage form), and
						4) number of years, which were all read in.
	Input:				double presentValue, double futureValue, double interestRate, int numberYears
						The calculated present value, and the three values used to calculate it.
	Return:				None. */
void lab8ex2_displayResults(double presentValue, double futureValue, double interestRate, int numberYears) {
	cout << fixed << setprecision(2);
	cout << "Present value: $" << presentValue << endl;
	cout << "Future value: $" << futureValue << endl;
	cout << "Annual interest rate: " << fixed << setprecision(1) << (interestRate * 100) << "%" << endl;
	cout << "Years: " << numberYears << endl;
}



/*	Lab #9 Exercise #1 (4/20/2019):
	This assignment uses 2 helper functions (with prototypes) in addition to its driver function.
	The 1st one receives the user's input, and the 2nd one displays the output. Additionally, a global constant is used.
	The assignment displays the status of an order for a company sells spools of copper wiring for $100 each. */
void lab9ex1() {
	// This driver function body was formerly contained within main() of lab9ex1's own source file.

	// all int variables are initialized to invalid values
	int intSpoolsOrdered = 0;                    // number of spools ordered
	int intSpoolsInStock = -1;                   // number of spools in stock
	double shippingAndHandlingCharges = 11.88;   // shipping/handling charge, initialized to the default rate

	lab9ex1_getInputs(intSpoolsOrdered, intSpoolsInStock, shippingAndHandlingCharges);
	
	lab9ex1_displayOutput(intSpoolsOrdered, intSpoolsInStock, shippingAndHandlingCharges);
}
/*	Helper Function:	lab9ex1_getInputs() 
	Descr:				This function reads in three values from the user:
						1) the number of spools in their order,
						2) the number of spools currently in the company's stock, and
						3) the shipping/handling charge, which the user can either say "yes" to input their own charge,
						or "no" to in order to keep the default charge.
						The parameters of this function are passed by reference, so that the inputted values
						can be directly transferred into the arguments in the driver function.
	Input:				int & intSpoolsOrdered, int & intSpoolsInStock, double & shippingAndHandlingCharges
						Number of spools ordered, number of them in stock, and the shipping/handling fee.
						(All passed by reference)
	Return:				None. */
void lab9ex1_getInputs(int & intSpoolsOrdered, int & intSpoolsInStock, double & shippingAndHandlingCharges) {
	cout << "Please enter the number of spools to be ordered:" << endl;
	cin >> intSpoolsOrdered;
	while (intSpoolsOrdered < 1)
	{
		cout << "ERROR: Number of spools ordered must be 1 or more." << endl;
		cout << "Please enter the number of spools to be ordered:" << endl;
		cin >> intSpoolsOrdered;
	}

	cout << "Please enter the number of spools in stock:" << endl;
	cin >> intSpoolsInStock;
	while (intSpoolsInStock < 0)
	{
		cout << "ERROR: Spools in stock must be 0 or more." << endl;
		cout << "Please enter the number of spools in stock:" << endl;
		cin >> intSpoolsInStock;
	}

	char yesNo = 'n';	// the user's "yes" or "no" to input their own shipping/handling charge
	cout << "Special shipping and handling? (y or n)" << endl;
	cin >> yesNo;
	if (yesNo == 'y')
	{
		cout << "Please enter the shipping and handling amount:" << endl;
		cin >> shippingAndHandlingCharges;
		while (shippingAndHandlingCharges < 0.0)
		{
			cout << "ERROR: The spool shipping and handling charge must be 0.0 or more." << endl;
			cout << "Please enter the shipping and handling amount:" << endl;
			cin >> shippingAndHandlingCharges;
		}
	}
}
/*	Helper Function:	lab9ex1_displayOutput()
	Descr:				This function displays a report detailing the status of the user's order.
						The report consists of 5 items:
						1) the number of spools ready to ship,
						2) the number of spools in back-order (if any),
						3) the subtotal for the spools ready to ship,
						4) the shipping and handling fee, and
						5) the total cost of the order ready to ship.
	Input:				int intSpoolsOrdered, int intSpoolsInStock, double shippingAndHandlingCharges
						Number of spools ordered, number of them in stock, and the shipping/handling fee.
						(No longer passed by reference, but by value)
	Return:				None. */
void lab9ex1_displayOutput(int intSpoolsOrdered, int intSpoolsInStock, double shippingAndHandlingCharges) {
	// all int variables are initialized to invalid values
	int intSpoolsReady = -1;		// the number of spools ready to ship
	int intSpoolsBackorder = 0;		// the number of spools in back-order (if any)

	if (intSpoolsOrdered <= intSpoolsInStock)
	{
		intSpoolsReady = intSpoolsOrdered;
	}
	else
	{
		intSpoolsReady = intSpoolsInStock;
		intSpoolsBackorder = intSpoolsOrdered - intSpoolsReady;
	}

	double dblSubtotalReadyToShip = intSpoolsReady * lab9ex1_DBL_SPOOL_PRICE;	// the subtotal for the spools ready to ship
	double dblShipping = intSpoolsReady * shippingAndHandlingCharges;			// the shipping and handling fee
	double dblChargeForCurrentShipment = dblSubtotalReadyToShip + dblShipping;	// the total cost of the order ready to ship
	

	cout << "Spools ready to ship: " << intSpoolsReady << endl;
	cout << "Spools on back-order: " << intSpoolsBackorder << endl;
	cout << "Subtotal ready to ship: $" << setw(10) << fixed << setprecision(2) << dblSubtotalReadyToShip << endl;
	cout << "Shipping and handling:  $" << setw(10) << fixed << setprecision(2) << dblShipping << endl;
	cout << "Total shipping charges: $" << setw(10) << fixed << setprecision(2) << dblChargeForCurrentShipment << endl;
}



/*	Lab #9 Exercise #2 (4/20/2019): 
	This assignment uses 3 helper functions (with prototypes) in addition to its driver function.
	The assignments calculates the future value of an investment in the user's bank account.
	The 1st function reads in the necessary values for this calculation
	(the present value, monthly interest rate, and the number of months for the investment) from an input file.
	The 2nd function computes compounded interest by month using the formula F = P * pow((1 + i),t).
	The 3rd function writes a report of these values into a .xls output file. */
void lab9ex2() {
	// This driver function body was formerly contained within main() of lab9ex2's own source file.
	
	// creates an input file, gets its name from the user, and opens it
	ifstream inputFile;
	string inputFileName;
	cout << "Please enter the name of the input file containing your bank account investment data: ";
	cin >> inputFileName;		// the input file provided is lab9ex2_data.txt
	inputFile.open(inputFileName);

	bool writeHeader = true;	// the control variable for lab9ex2_writeOutput() to write headers to the output file only once

	// the input file was successfully opened
	if (inputFile)
	{
		// creates an output file, names it, and opens it
		ofstream outputFile;
		outputFile.open("lab9ex2_output.xls");

		// the output file opened successfully 
		if (outputFile)
		{
			double presentValue = 0.0;				// the present value for the investment
			double monthlyInterestRate = 0.0;		// the monthly interest rate on the investment
			int numMonths = 0;						// the number of months for the investment

			unsigned int returnValue = 3;			// the return value (will be 0, 1, or 2) from getInput
			double futureValue = -1.0;				// the calculated future value, initialized to an invalid value
			double monthlyRateDecimal;				// the decimal form of the user-inputted percentage value for the monthly interest rate

			lab9ex2_writeOutput(outputFile, futureValue, presentValue, monthlyInterestRate,
				numMonths, writeHeader);

			/* when getInput's return value is not 0, so the end of the input file has not been reached
			(and therefore the assignment must continue executing its functions) */
			while (returnValue > 0)
			{
				returnValue = lab9ex2_getInput(inputFile, presentValue, monthlyInterestRate, numMonths);
				monthlyRateDecimal = monthlyInterestRate / 100.0;

				// when valid input values have been read in from the input file
				if (returnValue == 1)
				{
					futureValue = lab9ex2_calculateFutureValue(presentValue, monthlyRateDecimal, numMonths);
					lab9ex2_writeOutput(outputFile, futureValue, presentValue, monthlyInterestRate, numMonths, writeHeader);
				}
			}
			outputFile.close();
		}
		// the output file was not successfully opened
		else
		{
			cout << "ERROR: File \"lab9ex2_output.xls\" could not be opened." << endl;
		}
		inputFile.close();
	}
	// the input file was not successfully opened
	else
	{
		cout << "ERROR: File \"" << inputFileName << "\" could not be opened." << endl;
	}
}
/*	Helper Function:	lab9ex2_getInput()
	Descr:				This function opens the user-named file and reads in every 3 values inside as the
						presentValue, monthlyInterestRate, and numMonths, in that order.
						It runs a series of checks to determine whether the return value of the function should be
						0 (the end of the input file has been reached), 1 (the values read in are all valid),
						or 2 (one or more of the values read in is invalid).
	Input:				ifstream & inputFile, double & presentValue, double & monthlyInterestRate, int & numMonths
						The user's input file, and the 3 variables read in from that file that will be used to
						calculate the future value of the investment in a separate function.
						(All passed by reference)
	Return:				unsigned int returnValue
						A variable containing either 0, 1, or 2. */
unsigned int lab9ex2_getInput(ifstream & inputFile, double & presentValue, double & monthlyInterestRate, int & numMonths) {
	// initially sets the function's return value to 2, indicating that none of them are valid
	unsigned int returnValue = 2;

	// the input file was opened successfully
	if (inputFile)
	{
		// there are values in the file to be read in
		if (inputFile >> presentValue >> monthlyInterestRate >> numMonths)
		{
			// input-validation check to set the function's return value to 1, meaning the inputs are all valid
			if (presentValue > 0 && monthlyInterestRate > 0 && numMonths > 0)
			{
				returnValue = 1;
			}
			// input-validation check leaves the function's return value as 2, and proceeds to print an error message
			else
			{
				cout << fixed << setprecision(2) << presentValue << " "
				<< fixed << setprecision(2) << monthlyInterestRate << " "
				<< numMonths << endl;
				cout << "One or more of the above values are not greater than zero" << endl;
			}
		}
		// there are no values in the file to be read in, meaning the end of the input file has been reached
		else
		{
			returnValue = 0;
		}
	}
	// the input file was not opened successfully
	else
	{
		cout << "ERROR: File could not be opened." << endl;
	}

	return returnValue;
}
/*	Helper Function:	lab9ex2_calculateFutureValue()
	Descr:				This function computes compounded interest by month using the formula F = P * pow((1 + i),t).
						This value is stored in a variable as the future value of the investment.
	Input:				double presentValue, double interestRate, int months
						The three variables read previously, used to calculate the future value of the investment in this function.
	Return:				double futureValue
						The value that was calculated. */
double lab9ex2_calculateFutureValue(double presentValue, double interestRate, int months) {
	double futureValue = -1;	// initially sets the future value to an invalid amount
	futureValue = presentValue * pow((1 + interestRate), months);

	return futureValue;
}
/*	Helper Function:	lab9ex2_writeOutput()
	Descr:				This function writes all the previous variables used into the .xls output file in the form of a report.
						The headers print only once, but then each iteration of the while-loop in the driver function
						will continue to use this function to print output to the output file,
						as long as there continue to be valid input values to be processed from the input file.
	Input:				ofstream & outputFile, double & futureValue, double & presentValue, double & monthlyInterestRate, int & numMonths, bool & writeHeader
						The output file; the 3 values used to calculate the future value, along with the future value itself;
						and the boolean control variable that allows the headers to print only once into the output file.
						(All passed by reference)
	Return:				None. */
void lab9ex2_writeOutput(ofstream & outputFile, double & futureValue, double & presentValue, double & monthlyInterestRate, int & numMonths, bool & writeHeader) {
	if (writeHeader)
	{
		outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;
		writeHeader = false;
	}
	else
	{
		outputFile << fixed << setprecision(2) << futureValue << "\t"
					<< fixed << setprecision(2) << presentValue << "\t"
					<< fixed << setprecision(2) << monthlyInterestRate << "\t"
					<< fixed << setprecision(2) << numMonths << endl;
	}
}



/*	Lab #10 Exercise #1 (4/20/2019): 
	This assignment uses 2 helper functions (with prototypes) in addition to its driver function. Additionally, a global constant is used.
	The assignment compares an array of quiz answers to an array of student answers and outputs the student's results. */
void lab10ex1() {
	// This driver function body was formerly contained within main() of lab10ex1's own source file.

	// input the file with the student's answers
	string inputFileName;
	cout << "Please enter the name of the input file containing the student's answers: ";
	cin >> inputFileName;	// the input file provided is lab10ex1_student.txt

	// create arrays for both the student's answers and the correct answers
	char studentResponses[lab10ex1_ARRAY_SIZE];
	char correctResponses[lab10ex1_ARRAY_SIZE];

	// create two bools for the returns of both arrays as arguments of the function lab10ex1_readArray()
	bool studentReadStatus = lab10ex1_readArray(studentResponses, inputFileName);
	bool correctReadStatus = false;

	// only call lab10ex1_readArray() on the correct answers if the call on the student's answers worked
	if (studentReadStatus)
	{
		// input the file with the correct answers
		cout << "Please enter the name of the input file containing the correct answers: ";
		cin >> inputFileName;	// the input file provided is lab10ex1_answers.txt
		correctReadStatus = lab10ex1_readArray(correctResponses, inputFileName);
	}
	
	// only call lab10ex1_displayResults() on both arrays if both calls on lab10ex1_readArray() have worked
	if (studentReadStatus && correctReadStatus)
	{
		lab10ex1_displayResults(studentResponses, correctResponses);
	}
}
/*	Helper Function:	lab10ex1_readArray()
	Descr:				This function reads the contents of an input file, and reads that data into the array.
						It uses a counter i and a while-loop to achieve this.
						It then returns a true or false depending on whether the file was opened successfully
						and the read was successful too.
	Input:				char response[lab10ex1_ARRAY_SIZE], string inputFileName
						An array of any set of responses, and and input file containing those responses.
	Return:				bool true or false
						Indicates if the read from the input file to the array was successful or not. */
bool lab10ex1_readArray(char response[lab10ex1_ARRAY_SIZE], string inputFileName) {
	// creates the input file and opens it
	ifstream inputFile;
	inputFile.open(inputFileName);

	// the input file was successfully opened
	if (inputFile)
	{
		// read data from the input file directly into the array, then close the file
		int i = 0;
		while (i < lab10ex1_ARRAY_SIZE && inputFile >> response[i])
		{
			i++;
		}
		inputFile.close();

		// if the read was successful, return true
		if (i == lab10ex1_ARRAY_SIZE)
		{
			return true;
		}
		// if the read was not successful, return false
		else
		{
			return false;
		}

	}
	// the input file was not successfully opened
	else
	{
		cout << "ERROR: File \"" << inputFileName << "\" could not be opened." << endl;
		return false;
	}
}
/*	Helper Function:	lab10ex1_displayResults()
	Descr:				This function loops through two arrays and compares each parallel element in the two arrays.
						An accumulator keeps count of how many elements aren't identical to their parallel in the other array,
						thus keeping score of how many questions the student missed.
						Every incorrect question is outputted with the student's answer alongside the correct answer.
						Afterwards, the student's grade is calculated, and a test determines whether their grade is a pass or fail.           
	Input:				char studentResponses[lab10ex1_ARRAY_SIZE], char correctResponses[lab10ex1_ARRAY_SIZE]
						An array of student responses, and an array of the correct answers.
	Return:   			None. */
void lab10ex1_displayResults(char studentResponses[lab10ex1_ARRAY_SIZE], char correctResponses[lab10ex1_ARRAY_SIZE]) {
	// accumulator for incorrect answers
	int incorrectCounter = 0;

	// loop through the array and output a statement for any incorrect answers
	for (int i = 0; i < lab10ex1_ARRAY_SIZE; i++)
	{
		if (studentResponses[i] != correctResponses[i])
		{
			cout << "Question " << (i + 1) << " has incorrect answer '" << studentResponses[i] << "', the correct answer is '" << correctResponses[i] << "'" << endl;
			incorrectCounter++;
		}
	}

	cout << incorrectCounter << " questions were missed." << endl;

	// calculate the student's grade, and determine if pass or fail
	double studentGrade = (double(lab10ex1_ARRAY_SIZE - incorrectCounter) / lab10ex1_ARRAY_SIZE) * 100.0;
	if (studentGrade >= 70.0)
	{
		cout << "The student has passed." << endl;
	}
	else
	{
		cout << "The student has failed." << endl;
	}
}



/*	Lab #10 Exercise #2 (4/20/2019):
	This assignment uses 4 helper functions (with prototypes) in addition to its driver function. Additionally, 2 global constants are used.
	The assignment reads the contents of a file into an array and calculates various values based on the contents of the file. */
void lab10ex2() {
	// This driver function body was formerly contained within main() of lab10ex2's own source file.

	// input a file name
	string inputFileName;
	cout << "Please enter the name of the input file containing grades: ";
	cin >> inputFileName;	// the input file provided is lab10ex2_grades.txt

	// array of grades
	double grades[lab10ex2_MAX_ROWS][lab10ex2_MAX_COLUMNS];

	// number of rows actually put into the array from the file
	int actualRows = lab10ex2_readFile(grades, lab10ex2_MAX_ROWS, inputFileName);
	
	// the number of rows is invalid, meaning file-to-array read was not successful
	if (actualRows == -1)
	{
		cout << "ERROR: File \"" << inputFileName << "\" could not be opened." << endl;
	}
	// the number of rows is 0, meaning the file contained no data
	else if (actualRows == 0)
	{
		cout << "ERROR: The input file \"" << inputFileName << "\" did not contain any data." << endl;
	}
	// the number of rows is valid, so subsequent calculations are made
	else
	{
		cout << "Average for all values is " << fixed << setprecision(2) << lab10ex2_average(grades, actualRows) << endl;

		for (int col = 0; col < lab10ex2_MAX_COLUMNS; col++)
		{
			cout << "Average for column " << col << " is " << lab10ex2_columnAverage(grades, col, actualRows) << endl;
		}

		for (int row = 0; row < actualRows; row++)
		{
			cout << "Smallest value for row " << row << " is " << lab10ex2_smallestValue(grades, row) << endl;
		}
	}
}
/*	Helper Function:	lab10ex2_readFile()
	Descr:				This function reads the contents of an input file, and reads that data into a 2D array.
						The doubles in the file are read as strings and converted to doubles in the array.
	Input:				double grades[][lab10ex2_MAX_COLUMNS], int maxRowsToRead, string inputFileName
						A 2D array of grades, the maximum number of rows for the 2D array, and and input file containing the grades.
	Return:				int currentRow
						The number rows read into the 2D array. */
int lab10ex2_readFile(double grades[][lab10ex2_MAX_COLUMNS], int maxRowsToRead, string inputFileName) {
	// creates an input file and opens it
	ifstream inputFile;
	inputFile.open(inputFileName);

	string rowContents = "";
	int currentRow = 0;

	// the input file was successfully opened
	if (inputFile)
	{
		while (!inputFile.eof())
		{
			getline(inputFile, rowContents);

			if (rowContents != "")
			{
				istringstream iss(rowContents);

				int currentColumn = 0;
				string str = "";
				do
				{
				iss >> str;
				if (str == "")
				{
					return 0;
				}
				else
				{
					grades[currentRow][currentColumn] = stod(str);
				}
				currentColumn++;
				if (currentColumn == lab10ex2_MAX_COLUMNS)
				{
					break;
				}

				str = "";
				} while (iss);

				iss.clear();

				if (currentColumn < 5)
				{
				return 0;
				}

				currentRow++;
				if (currentRow == 20)
				{
				break;
				}
			}

			
		}

		inputFile.close();
	}
	// the input file was not successfully opened
	else
	{
		return -1;
	}

	return currentRow;
   
}
/*	Helper Function:	lab10ex2_average()
	Descr:				This function adds up all the values in the 2D argument array and divides the sum by the number of values,
						thus calculating the average.
	Input:				double values[][lab10ex2_MAX_COLUMNS], int numberRows
						A 2D array of grades and the number of rows in that array.
	Return:				double avg
						The average of all the numbers in the array. */
double lab10ex2_average(double values[][lab10ex2_MAX_COLUMNS], int numberRows) {
	cout << "Processing " << numberRows << " rows, and " << lab10ex2_MAX_COLUMNS << " columns" << endl;

	double sum = 0.0;
	int numElems = 0;
	double avg = -1.0;

	for (int row = 0; row < numberRows; row++)
	{
		for (int col = 0; col < lab10ex2_MAX_COLUMNS; col++)
		{
			sum += values[row][col];
			numElems++;
		}
	}

	avg = sum / numElems;

	return avg;
}
/*	Helper Function:	lab10ex2_columnAverage()
	Descr:				This function adds up all the values in a column of the 2D array,
						then divides by the number of elements in the column,
						thus calculating the average for the given column.
	Input:				double values[][lab10ex2_MAX_COLUMNS], int column, int numberRows
						A 2D array of grades, the index of the column, and the number of rows in the array.
	Return:				double avg
						The average of all the numbers in a column. */
double lab10ex2_columnAverage(double values[][lab10ex2_MAX_COLUMNS], int column, int numberRows) {
	double sum = 0.0;
	int numElems = 0;
	double avg = -1.0;

	sum = 0.0;
	numElems = 0;
	for (int row = 0; row < numberRows; row++)
	{
		sum += values[row][column];
		numElems++;
	}
	avg = sum / numElems;

	return avg;
}
/*	Helper Function:	lab10ex2_smallestValue()
	Descr:				This function determines the smallest value in a given row of the 2D array.
	Input:				double values[][lab10ex2_MAX_COLUMNS], int currentRow
						A 2D array of grades and the row whose minimum is being determined.
	Return:				double min
						The smallest value in a given row. */
double lab10ex2_smallestValue(double values[][lab10ex2_MAX_COLUMNS], int currentRow) {
	double min = values[currentRow][0];

	for (int col = 1; col < lab10ex2_MAX_COLUMNS; col++)
	{
		if (values[currentRow][col] < min)
		{
			min = values[currentRow][col];
		}
	}

	return min;
}