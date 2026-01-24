/*	Author:				Bushra Rahman
	Course:				CS 1336 (Spring 2019)
	hw_exercises.cpp:	This source file contains every homework exercise as its own function returning void.
						There are 20 total hw exercises: 0-0 being a skeleton function, 1 exercise for HW 4,
						and 2 exercises for each of the remaining HWs 1 through 3 and 5 through 9, 
						with an additional BONUS exercise accompanying 5-2 and 7-1 respectively. */

#include <iostream>		// 1-1, 1-2, 2-1, 2-2, 3-1, 3-2, 4-1, 5-1, 5-2, 5-2 BONUS, 6-1, 6-2, 7-1, 7-1 BONUS, 7-2, 8-1, 8-2, 9-1, 9-2
#include <iomanip>		// ...  1-2, 2-1, 2-2, 3-1, 3-2, 4-1, 5-1, 5-2, 5-2 BONUS, 6-1, 6-2, 7-1, 7-1 BONUS, 7-2, 8-1, 8-2, 9-1, 9-2
#include <ios>			// ...                 3-1, 3-2, 4-1, 5-1, 5-2, 5-2 BONUS, 6-1, 6-2, 7-1, 7-1 BONUS, 7-2, 8-1, 8-2, 9-1, 9-2
#include <string>		// ...                 3-1, 3-2,                                6-2, 7-1, 7-1 BONUS, 7-2, 8-1,      9-1, 9-2
#include <cmath>		// ...                      3-2, 4-1,                                                     8-1
#include <fstream>		// ...                                                                               7-2, 8-1,      9-1, 9-2
using namespace std;



// function prototypes for HW #8 Exercise #1
bool hw8ex1_isPrime(int number);
void hw8ex1_displayOutput(int number, ofstream & outputFile);

// function prototypes for HW #8 Exercise #2
void hw8ex2_getScore(int & score);
int hw8ex2_findLowest(int n1, int n2, int n3, int n4, int n5);
void hw8ex2_calcAverage(int n1, int n2, int n3, int n4, int n5);

// function prototypes for HW #9 Exercise #1
int hw9ex1_readArray(int stdList[], int numElems, string inputFileName);
int hw9ex1_searchList(int stdList[], int numElems, int value);
void hw9ex1_searchManager(int stdList[], int numElems, int testList[], int testElems);
// global constants indicating array sizes for HW #9 Exercise #1
const int hw9ex1_STANDARD_SIZE = 100;
const int hw9ex1_TEST_SIZE = 50;

// function prototypes for HW #9 Exercise #2
int hw9ex2_readArray(char response[], int maxArraySize, string inputFileName);
void hw9ex2_displayResults(char studentResponses[], int studentArraySize, char correctResponses[], int correctArraySize);
double hw9ex2_smallestValue(double values[], int numValues, int & indexForMin);
double hw9ex2_largestValue(double values[], int numValues, int & indexForMax);
// global constants indicating array sizes for HW #9 Exercise #2
const int hw9ex2_STUDENT_RESP_ARRAY_SIZE = 300;
const int hw9ex2_CORRECT_RESP_ARRAY_SIZE = 20;
const int hw9ex2_MAX_NUMBER_OF_STUDENTS = hw9ex2_STUDENT_RESP_ARRAY_SIZE / hw9ex2_CORRECT_RESP_ARRAY_SIZE;



/*	HW #0 Exercise #0 (Date): 
	This assignment is a skeleton function. */
void hw0ex0() {
	cout << "This is HW #0 Exercise #0, a skeleton function." << endl;
}



/*	HW #1 Exercise #1 (2/4/2019): 
	This assignment prints various strings to the output console. */
void hw1ex1() {

    // "Hello World!" (using an endl to put a carriage return at the end of the line)
	cout << "Hello world!" << endl;

	/* "C++ Programming is fun!\n" (without using an endl to put a carriage return at the end of the line; 
	the '\n' character does the same thing when it is embedded inside a string.) */
	cout << "C++ Programming is fun!\n";

    /* A prompt that says "The value of 2 times 3 is: " followed by that calculated value. (NOTE: As illustrated here, 
    don't forget to use parentheses around any calculations that are embedded in an output stream.) */
	cout << "The value of 2 times 3 is: " << (2 * 3) << endl;

	// The following diagrams, just as they appear in the instructions (side by side, not vertical):
	cout << "*********     *        *" << endl;
	cout << "*       *    ***      * *" << endl;
	cout << "*       *   *****    *   *" << endl;
	cout << "*       *     *     *     *" << endl;
	cout << "*       *     *    *       *" << endl; // middle
	cout << "*       *     *     *     *" << endl;
	cout << "*       *     *      *   *" << endl;
	cout << "*       *     *       * *" << endl;
	cout << "*********     *        *" << endl;
}



/*	HW #1 Exercise #2 (2/4/2019): 
	This assignment is derived from pseudocode to calculate the distance traveled under acceleration 'a' and time 't'. */
void hw1ex2() {

	float timeVal;          // value of time 't'
    float acceleration;     // value of acceleration 'a'
    float distanceVal;      // value of distance calculated
	timeVal = 5.36;
	acceleration = 32.0;
	distanceVal = (1.0 / 2) * acceleration * timeVal * timeVal;

	cout << fixed << setprecision (1);
	cout << "The time was:              " << timeVal << " sec." << endl;
	cout << "The acceleration was:      " << acceleration << " feet/sec/sec." << endl;
	cout << "The distance traveled was: " << distanceVal << " feet." << endl;
}



/*	HW #2 Exercise #1 (2/12/2019): 
	This assignment calculates the number of gallons of gas required for a car that can go
	23.5 mi/gal in-town and 28.9 mi/gal on highways. */
void hw2ex1() {
	cout << fixed << setprecision(1);

	double inTownMiles;		// number of miles driven in-town
	cout << "Please enter the number of in-town driving miles: ";
	cin >> inTownMiles;

	double highwayMiles;	// number of miles driven on highways
	cout << "Please enter the number of highway driving miles: ";
	cin >> highwayMiles;

	double gallonsGas;		// holds the total number of gallons yielded by both mileages

	gallonsGas = inTownMiles / 23.5 + highwayMiles / 28.9;

	cout << endl << "The total number of gallons required is: " << gallonsGas << endl;
}



/*	HW #2 Exercise #2 (2/12/2019): 
	This assignment converts inputted temperatures between Fahrenheit, Celsius, and Kelvin. */
void hw2ex2() {
	cout << fixed << setprecision(2);

	double celsDegrees;		// temperaure in Celsius (degrees)
	double fahrDegrees;		// temperature in Fahrenheit (degrees)
	double kelvDegrees;		// temperature in Kelvin (K)


	// user inputs a Celsius temperature, and it converts to Fahrenheit and Kelvin.
	cout << "Please enter a number in degrees Celsius: ";
	cin >> celsDegrees;

	fahrDegrees = 9 * celsDegrees / 5 + 32;
	cout << "The equivalent Fahrenheit temperature is: " << fahrDegrees << " degrees." << endl;

	kelvDegrees = celsDegrees + 273.15;
	cout << "The equivalent Kelvin temperature is: " << kelvDegrees << " K." << endl << endl << endl;


	// user inputs a Fahrenheit temperature, and it converts to Celsius and Kelvin.
	cout << "Please enter a number in degrees Fahrenheit: ";
	cin >> fahrDegrees;

	celsDegrees = (fahrDegrees - 32) * 5 / 9;
	cout << "The equivalent Celsius temperature is: " << celsDegrees << " degrees." << endl;

	kelvDegrees = (fahrDegrees - 32) * 5 / 9 + 273.15;
	cout << "The equivalent Kelvin temperature is: " << kelvDegrees << " K." << endl << endl << endl;


	// user inputs a Kelvin temperature, and it converts to Celsius and Fahrenheit.
	cout << "Please enter a number in Kelvin: ";
	cin >> kelvDegrees;

	celsDegrees = kelvDegrees - 273.15;
	cout << "The equivalent temperature in Celsius is: " << celsDegrees << " degrees." << endl;

	fahrDegrees = (kelvDegrees - 273.15) * 9 / 5 + 32;
	cout << "The equivalent temperature in Fahrenheit  is: " << fahrDegrees << " degrees." << endl << endl << endl;
}



/*	HW #3 Exercise #1 (2/21/2019): 
	This assignment computes the average amount of rainfall for three inputted months (Part A).
	It then prints the number of characters used to spell each of the inputted months (Part B). */
void hw3ex1() {
	cout << fixed << setprecision(2);

	// Part A: Calculating the average of three user-inputted amounts of rainfall
	string month1;		// first user-inputted month
	double month1Rain;	// amount of rainfall for the first month

	cout << "Please enter the name of month 1: ";
	cin >> month1;
	cout << "Please enter the rainfall for " << month1 << ": ";
	cin >> month1Rain;

	string month2;		// second user-inputted month
	double month2Rain;	// amount of rainfall for the second month

	cout << endl << "Please enter the name of month 2: ";
	cin >> month2;
	cout << "Please enter the rainfall for " << month2 << ": ";
	cin >> month2Rain;

	string month3;		// third user-inputted month
	double month3Rain;	// amount of rainfall for the third month

	cout  << endl << "Please enter the name of month 3: ";
	cin >> month3;
	cout << "Please enter the rainfall for " << month3 << ": ";
	cin >> month3Rain;

	double avgRain;		// average of the three amounts of rainfall

	avgRain = (month1Rain + month2Rain + month3Rain) / 3;

	cout << endl << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " was " << avgRain << " inches." << endl << endl;

	
	// Part B: Displaying the amount of character in each of the three user-inputted months
	// contains the first part of the output that is identical for all three statements
	string stncPart;
	// initializes this portion of the output to contain the 1st month's name
	stncPart = "The length of \"" + month1 + "\" is: ";
	cout << setw(30) << left << stncPart << setw(6) << right << month1.length() << " characters" << endl;
	
	// updates this portion of the output to contain the 2nd month's name
	stncPart = "The length of \"" + month2 + "\" is: ";
	cout << setw(30) << left << stncPart << setw(6) << right << month2.length() << " characters" << endl;
	
	// updates this portion of the output to contain the 3rd month's name
	stncPart = "The length of \"" + month3 + "\" is: ";
	cout << setw(30) << left << stncPart << setw(6) << right << month3.length() << " characters" << endl << endl;
}



/*	HW #3 Exercise #2 (2/21/2019): 
	This assignment calculates the amount of money paid each month to pay off a mortgage loan. */
void hw3ex2() {
	cout << fixed << setprecision(2);

	double loanAmt;			// the amount of the loan
	double annualIntRate;	// the annual rate of interest
	int numPayments;		// the number of payments made

	cout << "Please enter the amount of the loan: ";
	cin >> loanAmt;
	cout << "Please enter the annual interest rate: ";
	cin >> annualIntRate;
	cout << "Please enter the number of payments: ";
	cin >> numPayments;
	cout << endl;
	
	double monthlyIntRate;					// the monthly rate of interest, converted from the annual rate of interest
	annualIntRate = annualIntRate / 100;	// first convert the annual rate of interest from an integer-value percentage to a decimal
	monthlyIntRate = annualIntRate / 12;	// then convert the annual rate to a monthly rate by dividing the annual rate by 12 months

	double monthlyPayment;					// the amount to be paid monthly, given by the following formula
	monthlyPayment = (monthlyIntRate * pow(1 + monthlyIntRate, numPayments) * loanAmt) / (pow(1 + monthlyIntRate, numPayments) -1);

	cout << setw(30) << left << "Loan Amount: " << "$" << setw(9) << right << loanAmt << endl;
	cout << setw(30) << left << "Monthly Interest Rate: " << setw(9) << right << monthlyIntRate * 100 << "%" << endl;
	cout << setw(30) << left << "Number of Payments: " << setw(10) << right << numPayments << endl;
	cout << setw(30) << left << "Monthly Payment: " << "$" << setw(9) << right << monthlyPayment << endl;
	cout << setw(30) << left << "Amount Paid Back: " << "$" << setw(9) << right << numPayments * monthlyPayment << endl;
	cout << setw(30) << left << "Interest Paid: " << "$" << setw(9) << right << numPayments * monthlyPayment - loanAmt << endl;
}



/*	HW #4 Exercise #1 (2/25/2019): 
	This assignment calculates the balance in a savings account after a year. */
void hw4ex1() {
	cout << fixed << setprecision(2);

	double principalAmt;	// the principal amount deposited to the account
	double interestPercent;	// the rate of interest, in percent form (converted to decimal later)
	int timesCompounded;	// the number of times the interest is compounded in one year

	cout << "Please enter the principal amount in the account: ";
	cin >> principalAmt;
	cout << "Please enter the interest rate: ";
	cin >> interestPercent;
	cout << "Please enter the number of times the interest is compounded in one year: ";
	cin >> timesCompounded;
	cout << endl;

	double newBalance;
	double interestNum = interestPercent / 100;	// the decimal form of the interest percentage, to use in the formula
	newBalance = principalAmt * pow(1 + interestNum / timesCompounded, timesCompounded);

	cout << setw(25) << left << "Interest Rate: " << setw(9) << right << interestPercent << "%" << endl;
	cout << setw(25) << left << "Times Compounded: " << setw(9) << right << timesCompounded << endl;
	cout << setw(25) << left << "Principal: " << "$" << setw(8) << right << principalAmt << endl;
	cout << setw(25) << left << "Interest: " << "$" << setw(8) << right << newBalance - principalAmt << endl;
	cout << setw(25) << left << "Amount in Savings" << "$" << setw(8) << right << newBalance << endl;
}



/*	HW #5 Exercise #1 (3/12/2019): 
	This assignment reads in a number of seconds and converts it to minutes, hours, or days (or leaves it as seconds). */
void hw5ex1() {
	cout << fixed << setprecision(2);

	double numSeconds;		// user-inputted number of seconds

	cout << "Please enter the number of seconds: ";
	cin >> numSeconds;

	if (numSeconds < 60)	// seconds < 60: seconds
	{
		cout << numSeconds << " seconds is " << numSeconds << " seconds." << endl;
	}
	else if (numSeconds >= 60 && numSeconds < 3600)		// 60 <= seconds < 3600:  minutes
	{
		cout << numSeconds << " seconds is " << numSeconds / 60 << " minutes." << endl;
	}
	else if (numSeconds >= 3600 && numSeconds < 86400)	// 3600 <= seconds  < 86400: hours
	{
		cout << numSeconds << " seconds is " << numSeconds / 3600 << " hours." << endl;
	}
	else if (numSeconds >= 86400)						// seconds >= 86400: days
	{
		cout << numSeconds << " seconds is " << numSeconds / 86400 << " days." << endl;
	}
}



/*	HW #5 Exercise #2 (3/12/2019): 
	This assignment calculates the user's monthly phone bill based on a selected package. */
void hw5ex2() {
	cout << fixed << setprecision(2);

	char packageName;				// user-inputted, package name (can be A, a, B, b, C, or c)
	int numMinutes;					// user-inputted, number of minutes
	double baseAmt;					// base rate of pay for each package (either $39.99, $59.99, or $69.99)
	int additionalMin;				// any additional minutes in the user-inputted minutes beyond each package's basic capacity
	double additionalAmt = 0.00;	// the additional amt based on those additional minutes; multiplied by a rate ($0.45 or $0.40)
	double totalAmt = 0.00;			// the final monthly bill

	cout << "Please enter your package (A, B, or C): ";
	cin >> packageName;

	// if the package name is valid, then everything else can execute
	if (packageName == 'A' || packageName == 'a' ||
		packageName == 'B' || packageName == 'b' ||
		packageName == 'C' || packageName == 'c')
	{
		// prompt for minutes will occur only if package name is valid
		cout << "Please enter the number of minutes used: ";
		cin >> numMinutes;

		// calculations for if the user's package is A
		if (packageName == 'A' || packageName == 'a')
		{
			baseAmt = 39.99;
			additionalMin = numMinutes - 450;
			if (additionalMin > 0)
			{
				additionalAmt = additionalMin * 0.45;
			}
			totalAmt = baseAmt + additionalAmt;
			cout << "Your monthly bill is $" << totalAmt << endl;
		}
		// calculations for if the user's package is B
		else if (packageName == 'B' || packageName == 'b')
		{
			baseAmt = 59.99;
			additionalMin = numMinutes - 900;
			if (additionalMin > 0)
			{
				additionalAmt = additionalMin * 0.40;
			}
			totalAmt = baseAmt + additionalAmt;
			cout << "Your monthly bill is $" << totalAmt << endl;
		}
		// calculations for if the user's package is C
		else if (packageName == 'C' || packageName == 'c')
		{
			baseAmt = 69.99;
			totalAmt = baseAmt + additionalAmt;
			cout << "Your monthly bill is $" << totalAmt << endl;
		}
	}
	// error message in the case of invalid input
	else
		cout << endl << "ERROR: Please input a valid package." << endl;

	cout << endl;
}



/*	HW #5 Exercise #2 BONUS (3/12/2019): 
	This assignment calculates the user's monthly phone bill based on a selected package.
   	It then provides the user some feedback regarding the efficiency of the package they chose. */
void hw5ex2_BONUS() {
	cout << fixed << setprecision(2);

	char packageName;				// user-inputted, package name (can be A, a, B, b, C, or c)
	int numMinutes;					// user-inputted, number of minutes
	double baseAmt;					// base rate of pay for each package (either $39.99, $59.99, or $69.99)
	int additionalMin;				// any additional minutes in the user-inputted minutes beyond each package's basic capacity
	double additionalAmt = 0.00;	// the additional amt based on those additional minutes; multiplied by a rate ($0.45 or $0.40)
	double totalAmt = 0.00;			// the final monthly bill (is assigned either totalAmtA, B, or C at the end)
	double totalAmtA = 0.00;		// calculates the total monthly bill if the package chosen was A
	double totalAmtB = 0.00;		// calculates the total monthly bill if the package chosen was B
	double totalAmtC = 0.00;		// calculates the total monthly bill if the package chosen was C
	double leastAmt = 99999.9;		// compares against totalAmtsA, B, and C to determine which is the least
	char leastPackage = ' ';		// will be assigned the corresponding package of the lowest cost

	cout << "Please enter your package (A, B, or C): ";
	cin >> packageName;


	if (packageName == 'A' || packageName == 'a' ||
		packageName == 'B' || packageName == 'b' ||
		packageName == 'C' || packageName == 'c')
	{
		cout << "Please enter the number of minutes used: ";
		cin >> numMinutes;
		cout << endl;

		// For Package A
		{
			baseAmt = 39.99;
			additionalMin = numMinutes - 450;
			if (additionalMin > 0)
			{
				additionalAmt = additionalMin * 0.45;
			}
			totalAmtA = baseAmt + additionalAmt;
			if (totalAmtA < leastAmt)
			{
				leastAmt = totalAmtA;
				leastPackage = 'A';
			}
		}

		// For Package B
		{
			baseAmt = 59.99;
			additionalMin = numMinutes - 900;
			additionalAmt = 0;
			if (additionalMin > 0)
			{
				additionalAmt = additionalMin * 0.40;
			}
			totalAmtB = baseAmt + additionalAmt;
			if (totalAmtB < leastAmt)
			{
				leastAmt = totalAmtB;
				leastPackage = 'B';
			}
		}

		// For Package C
		{
			additionalAmt = 0;
			baseAmt = 69.99;
			totalAmtC = baseAmt + additionalAmt;
			if (totalAmtC < leastAmt)
			{
				leastAmt = totalAmtC;
				leastPackage = 'C';
			}
		}

		if (packageName == 'A' || packageName == 'a')
		{
			totalAmt = totalAmtA;
		}
		else if (packageName == 'B' || packageName == 'b')
		{
			totalAmt = totalAmtB;
		}
		else
			totalAmt = totalAmtC;

		cout << "Your monthly bill is $" << totalAmt << endl;
		if (packageName == leastPackage || packageName == leastPackage + 32)
		{
			cout << "Congratulations! You chose the best package." << endl;
		}
		else
		{
			cout << "You had a better option available, if you had chosen Package " << leastPackage << endl;
			cout << "Your monthly bill would have been $" << leastAmt << endl;
		}
		
	}
	else
	{
		cout << endl;
		cout << "*** Please input a valid package. ***" << endl;
	}

	cout << endl;
}



/*	HW #6 Exercise #1 (4/9/2019): 
	This program executes a variety of loops whose purposes are commented below. */
void hw6ex1() {
	// Loop A: prints out the even integers between 2 and 100, using a for-loop
	cout << "The even integers between 2 and 100:" << endl;
	int i = 0;	// the counter that controls line breaks in the following loops
	int even;	// even integers between 2 and 100
	for (even = 2; even <= 100; even +=2)
	{
		cout << setw(5) << even << " ";
		i++;
		if (i == 10)
		{
			cout << endl;
			i = 0;
		}
	}
	
	cout << endl;

	// Loop B: prints out the integers that are multiples of 3 from 99 down to 3, using a do-while loop
	cout << "The multiples of 3, starting from 99 down to 3:" << endl;
	i = 0;
	int triple = 99;	// integer multiples of 3, starting from 99
	do
	{
		cout << setw(5) << triple << " ";
		triple -= 3;
		i++;
		if (i == 10)
		{
			cout << endl;
			i = 0;
		}
	} while (triple >= 3);

	cout << endl << endl;

	// Loop C: prints out the integers between 2 and 1,048,576 (2^20) that are integer powers of 2, using a while-loop.
	cout << "The powers of 2 between 2 and 2^20:" << endl;
	i = 0;
	int baseTwo = 2;	// the base (starting at 2) that gets multiplied by itself with every iteration
	while (baseTwo <= 1048576)
	{
		cout << setw(10) << baseTwo;
		baseTwo = baseTwo * 2;
		i++;
		if (i == 8)
		{
			cout << endl;
			i = 0;
		}
	}

	cout << endl << endl;

	// Loop D: prints out the integers between 1,048,576 (2^20) down to 2 that are integer powers of 2, using a while-loop.
	cout << "The powers of 2, starting from 2^20 down to 2:" << endl;
	i = 0;
	baseTwo = 1048576;	// the base (starting at 2^20) that gets multiplied by itself with every iteration
	while (baseTwo >= 2)
	{
		cout << setw(10) << baseTwo;
		baseTwo = baseTwo / 2;
		i++;
		if (i == 8)
		{
			cout << endl;
			i = 0;
		}
	}

	cout << endl << endl;

	// Loop E: finds the accumulated sum and average of a set of numbers up to a user-inputted number.
	int val;		// user-inputted number
	int sum = 0;	// sum of numbers up to val, including val
	double avg = 0;	// average of those numbers, displayed in decimal format
	cout << "Please input a number: " << endl;
	cin >> val;

	for (i = 0; i <= val; i++)
	{
		sum = sum + i;
	}
	
	avg = sum / (--i * 1.0);
	cout << "The sum of the numbers from 1 to " << val << " is " << sum << endl;
	cout << "The average of the numbers from 1 to " << val << " is " << fixed << showpoint << setprecision(2) << avg << endl << endl;
}



/*	HW #6 Exercise #2 (4/9/2019): 
	This program gets five stores' sales for the day from the user.
	It then uses asterisks to display a bar chart measuring the five sales amounts. */
void hw6ex2() {
	int sales1;	// today's sales for store 1
	cout << "Enter today's sales for store 1: ";
	cin >> sales1;
	while (sales1 < 0)
	{
		cout << "Please enter a nonnegative sales for store 1: ";
		cin >> sales1;
	}

	int sales2;	// today's sales for store 2
	cout << "Enter today's sales for store 2: ";
	cin >> sales2;
	while (sales2 < 0)
	{
		cout << "Please enter a nonnegative sales for store 2: ";
		cin >> sales2;
	}

	int sales3;	// today's sales for store 3
	cout << "Enter today's sales for store 3: ";
	cin >> sales3;
	while (sales3 < 0)
	{
		cout << "Please enter a nonnegative sales for store 3: ";
		cin >> sales3;
	}

	int sales4;	// today's sales for store 4
	cout << "Enter today's sales for store 4: ";
	cin >> sales4;
	while (sales4 < 0)
	{
		cout << "Please enter a nonnegative sales for store 4: ";
		cin >> sales4;
	}

	int sales5;	// today's sales for store 5
	cout << "Enter today's sales for store 5: ";
	cin >> sales5;
	while (sales5 < 0)
	{
		cout << "Please enter a nonnegative sales for store 5: ";
		cin >> sales5;
	}

	cout << endl << "SALES BAR CHART" << endl << "(Each * = $100)" << endl;

	int i;							// counts through the number of asterisks
	int numAsterisk = sales1 / 100;	// number of required asterisks for each store
	cout << "Store 1: ";
	for (i = 1; i <= numAsterisk; i++)
	{
		cout << "*";
		if (i == numAsterisk)
		{
			cout << endl;
		}
	}

	i = 0;
	numAsterisk = sales2 / 100;
	cout << "Store 2: ";
	for (i = 1; i <= numAsterisk; i++)
	{
		cout << "*";
		if (i == numAsterisk)
		{
			cout << endl;
		}
	}

	i = 0;
	numAsterisk = sales3 / 100;
	cout << "Store 3: ";
	for (i = 1; i <= numAsterisk; i++)
	{
		cout << "*";
		if (i == numAsterisk)
		{
			cout << endl;
		}
	}

	i = 0;
	numAsterisk = sales4 / 100;
	cout << "Store 4: ";
	for (i = 1; i <= numAsterisk; i++)
	{
		cout << "*";
		if (i == numAsterisk)
		{
			cout << endl;
		}
	}

	i = 0;
	numAsterisk = sales5 / 100;
	cout << "Store 5: ";
	for (i = 1; i <= numAsterisk; i++)
	{
		cout << "*";
		if (i == numAsterisk)
		{
			cout << endl;
		}
	}
}



/*	HW #7 Exercise #1 (4/15/2019): 
	This assignment prints 4 geometric patterns using a user-inputted integer from the range [1,15]. */
void hw7ex1() {
	int val;	// user-inputted value
	cout << "Please enter an integer between 1 and 15: ";
	cin >> val;

	while (val < 1 || val > 15)
	{
		cout << "Please reenter an integer between 1 and 15: ";
		cin >> val;
	}
	cout << endl;

	//triangle 1: left-justified
	int col = 1;	// tracks how many total columns have printed
	int row = 1;	// tracks how many total rows have printed

	while (row <= val)
	{
		while (col <= val - (row - 1))
		{
			cout << "*";
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}

	cout << endl << endl;

	// triangle 2: right-justified
	row = 1;
	col = 1;

	while (row <= val)
	{
		while (col <= row - 1)
		{
			cout << " ";
			col++;
		}
		while (col <= val)
		{
			cout << "*";
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}

	cout << endl << endl;

	// triangle 3: full-isoceles triangle
	row = 1;
	col = 1;
	int numStar;	// number of columns with stars printed per row

	while (row <= val)
	{
		numStar = (row - 1) + 1 + (row - 1);

		while (col <= val - row)
		{
			cout << " ";
			col++;
		}
		col = 1;
		while (col <= numStar)
		{
			cout << "*";
			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}

	cout << endl << endl;


	// triangle 4: empty-isoceles triangle
	row = 1;
	col = 1;
	numStar = 0;

	while (row <= val)
	{
		numStar = (row - 1) + 1 + (row - 1);

		while (col <= val - row)
		{
			cout << " ";
			col++;
		}
		col = 1;
		while (col <= numStar)
		{
			if (col == 1 || col == numStar)
			{
				cout << "*";
			}
			else
			{
			if (row == val)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			}

			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}
	cout << endl;
}



/*	HW #7 Exercise #1 BONUS (4/15/2019): 
	This assignment prints an hourglass triangle. */
void hw7ex1_BONUS() {
	int val;	// user-inputted odd value
	cout << "Please enter an odd integer between 1 and 15: ";
	cin >> val;

	while (val < 1 || val > 15 || val % 2 == 0)
	{
		cout << "Please reenter an odd integer between 1 and 15: ";
		cin >> val;
	}

	// bonus triangle: hourglass triangle
	val = (val + 1) / 2;	// halves the hourglass into two triangles
	int col = 1;			// tracks how many total columns have printed
	int row = val;			// tracks how many rows have printed
	int numStar = -1;		// number of columns with stars printed per row

	// top triangle
	while (row > 1)
	{
		numStar = (row - 1) + 1 + (row - 1);

		while (col <= val - row)
		{
			cout << "  ";
			col++;
		}
		col = 1;
		while (col <= numStar)
		{
			if (col == 1 || col == numStar)
			{
				cout << "* ";
			}
			else
			{
				if (row == val)
				{
				cout << "* ";
				}
				else
				{
				cout << "  ";
				}
			}

			col++;
		}
		cout << endl;
		row--;
		col = 1;
	}

	// bottom triangle
	while (row <= val)
	{
		numStar = (row - 1) + 1 + (row - 1);

		while (col <= val - row)
		{
			cout << "  ";
			col++;
		}
		col = 1;
		while (col <= numStar)
		{
			if (col == 1 || col == numStar)
			{
				cout << "* ";
			}
			else
			{
				if (row == val)
				{
				cout << "* ";
				}
				else
				{
				cout << "  ";
				}
			}

			col++;
		}
		cout << endl;
		row++;
		col = 1;
	}
}



/*	HW #7 Exercise #2 (4/15/2019): 
	This assignment reads in a list of random numbers from an input file and calculates a set of statistics on those numbers.
    It then prints out a report of those statistics. */
void hw7ex2() {
	// creates an input file for the input file
	ifstream inputFile;
	// the input files provided are hw7ex2_NumListLong.txt or hw7ex2_NumListShort.txt
	string inputFileName = "hw7ex2_NumListLong.txt";

	int val;			// current value being processed from the input file
	
	int counter = 0;	// the number of numbers in the file
	int sum = 0;		// the sum of the numbers in the file
	double avg = 0.0;	// the average of the numbers in the file
	int max = -10000;	// the largest number in the file
	int min = 10000;	// the smallest number in the file
	int secondMax;		// the second largest number in the file
	int secondMin;		// the second smallest number in the file

	inputFile.open(inputFileName);

	// the input file opened successfully
	if (inputFile)
	{
		cout << "File \"" << inputFileName << "\" was opened" << endl << endl;

		while (inputFile >> val)
		{
			sum += val;
			counter++;
			if (val > max)
			{
				secondMax = max;
				max = val;
				}
			else if (val > secondMax && val < max)
			{
				secondMax = val;
			}
			if (val < min)
			{
				secondMin = min;
				min = val;
			}
			else if (val < secondMin && val > min)
			{
				secondMin = val;
			}
		}
		avg = double(sum) / double(counter);

		inputFile.close();

		// print the report
		cout << setw(23) << left << "Number of numbers:" << setw(7) << right << counter << endl;
		cout << setw(23) << left << "Sum of numbers:" << setw(7) << right << sum << endl;
		cout << setw(23) << left << "Average of numbers:" << setw(7) << right << fixed << setprecision(1) << avg << endl;
		cout << setw(23) << left << "Largest number:" << setw(7) << right << max << endl;
		cout << setw(23) << left << "Smallest number:" << setw(7) << right << min << endl;
		cout << setw(23) << left << "Second largest number:" << setw(7) << right << secondMax << endl;
		cout << setw(23) << left << "Second smallest number:" << setw(7) << right << secondMin << endl;
		cout << endl;
	}
	// the input file did not open successfully
	else
	{
		cout << "File \"" << inputFileName << "\" could not be opened" << endl;
	}
}



/*	HW #8 Exercise #1 (4/23/2019): 
	This assignment uses 2 helper functions (with prototypes) in addition to its driver function.
	The assignment prints out the set of the first 'n' prime numbers, wherein 'n' is a user-inputted number from 1-100.
    This set is printed to both the output console as well as an output file. */
void hw8ex1() {
	// This driver function body was formerly contained within main() of hw8ex1's own source file.

	// create the user-inputted number, and get its value from the user
	int num;
	cout << "Please enter a number between 1 and 100: ";
	cin >> num;

	// input validation loop
	while (num > 100 || num < 1)
	{
		cout << "Please re-renter a number between 1 and 100: ";
		cin >> num;
	}

	// create the output file, name it, and open it
	ofstream outputFile;
	string outputFileName = "hw8ex1_PrimeOut.txt";
	outputFile.open(outputFileName);

	// the output file was opened successfully
	if (outputFile)
	{
		hw8ex1_displayOutput(num, outputFile);
		outputFile.close();
	}
	// the output file was not opened successfully
	else
	{
		cout << "ERROR: the file \"" << outputFileName << "\" could not be opened." << endl;
	}
}
/*	Helper Function:	hw8ex1_isPrime()
	Descr:				This function tests the argument for primeness.
						It uses loops to test the division of this number against every value less than its square root.
		   				If the number divides perfectly by any of these values, then its primeness is set to false.
						This label of its primeness or non-primeness is what is returned in the form of a boolean.
	Input:    			int number
						Any number whose primeness is being tested.
	Return:				bool isPrime
						The true/false designation of the number as prime or not. */
bool hw8ex1_isPrime(int number) {
	bool isPrime = true;

	// 1 is not considered a prime nor composite number
	if (number == 1)
	{
		isPrime = false;
	}
	// any number other than 1 must be tested for primeness
	else
	{
		// create a counter 'i' and divide the number by i for every i up to the square root of that number
		for (int i = 2; i <= sqrt(number); i++)
		{
			// if the number divides perfectly by any value of i, then the number is not prime
			if (number % i == 0)
			{
				isPrime = false;
				break; // once isPrime is set to false, no more iterations need to occur
			}
		}
	}

	return isPrime;
}
/*	Helper Function:	hw8ex1_displayOutput()
	Descr:				This function prints the user-inputted number of prime numbers to both
           				the output console and output file.
						It calls hw8ex1_isPrime() on every testNum starting from 1, and if it is prime, it is printed.
						The control variable primeCounter is used to track how many prime numbers
           				have been found and printed.
						Once primeCounter is equal to the argument int number, the loop is terminated
						by setting testForPrime to false.
           				In addition, newlines are printed for every 10th value of primeCounter, 
						and also printed once the end has been reached (once testPrime is false).
	Input:    			int number, ofstream & outputFile
        				The user-inputted number of primes to print, 
						and the output file that will be directly changed by printing that.
						(Therefore it is passed by reference.)
	Return:   			None. */
void hw8ex1_displayOutput(int number, ofstream & outputFile) {
	bool testForPrime = true;	// boolean control to keep calling isPrime
	int testNum = 0;			// any number being tested for primeness
	int primeCounter = 0;		// the number of prime numbers found and printed

	// output a header to both the output console and the output file
	cout << "The first " << number << " primes:" << endl;
	outputFile << "The first " << number << " primes:" << endl;

	// control loop for testing for primeness
	while (testForPrime)
	{
		testNum++;

		// if the testNum is prime
		if (hw8ex1_isPrime(testNum))
		{
			// print this testNum to both the output console and output file
			cout << setw(5) << testNum << " ";
			outputFile << setw(5) << testNum << " ";

			// increment both the number of numbers printed, as well as the number of primes found
			primeCounter++;

			// test for if the total user-inputted number of primes has been reached
			if (primeCounter == number)
			{
				testForPrime = false;
			}

			// print on a new line after every ten numbers printed
			if (primeCounter % 10 == 0)
			{
				cout << endl;
				outputFile << endl;
			}
			// print a line break once the user-inputted number of primes has been printed
			else
			{
				if (testForPrime == false)
				{
				cout << endl;
				outputFile << endl;
				}
			}
		}
	}
}



/*	HW #8 Exercise #2 (4/23/2019): 
	This assignment uses 3 helper functions (with prototypes) in addition to its driver function.
	The assignment receives 5 scores from the user, find the lowest of those scores,
    and calculate the average after having dropped that lowest score. */
void hw8ex2() {
	// This driver function body was formerly contained within main() of hw8ex2's own source file.

	// create and receive 5 scores from the user using hw8ex2_getScore()
	int score1;
	hw8ex2_getScore(score1);
	int score2;
	hw8ex2_getScore(score2);
	int score3;
	hw8ex2_getScore(score3);
	int score4;
	hw8ex2_getScore(score4);
	int score5;
	hw8ex2_getScore(score5);

	// call hw8ex2_calcAverage() on these scores
	hw8ex2_calcAverage(score1, score2, score3, score4, score5);
}
/*	Helper Function:	hw8ex2_getScore()
	Descr:				This function prompts the user for a score between 0 and 100.
						It then uses an input-validation loop to make sure that 5 integers
						meeting these conditions are supplied.
	Input:				int & score
						Receives a single user-inputted score and stores it in int score.
           				(Therefore it is passed by reference.)
	Return:   			None. */
void hw8ex2_getScore(int & score) {
	cout << "Enter a score between 0 and 100: ";
	cin >> score;

	while (score < 0 || score > 100)
	{
		cout << "Re-enter a valid score between 0 and 100: ";
		cin >> score;
	}
}
/*	Helper Function:	hw8ex2_findLowest()
	Descr:				This function compares all the numbers in the argument to determine which of them
						is the smallest/minimum of the total 5.
						It achieves this through the use of multiple if-blocks in succession.
	Input:				int n1, int n2, int n3, int n4, int n5
						Five numbers/scores gotten through calling getInput 5 times in the driver function.
	Return:				int min
						The minimum number among the 5 scores. */
int hw8ex2_findLowest(int n1, int n2, int n3, int n4, int n5) {
	// create the minimum and initialize it to a number too big to be the lowest score
	int min = 101;
	if (n1 < min)
	{
		min = n1;
	}
	if (n2 < min)
	{
		min = n2;
	}
	if (n3 < min)
	{
		min = n3;
	}
	if (n4 < min)
	{
		min = n4;
	}
	if (n5 < min)
	{
		min = n5;
	}

	return min;
}
/*	Helper Function:	hw8ex2_calcAverage()
	Descr:				This function calculates the average of the 4 remaining scores
						after having called hw8ex2_findLowest() to identify the lowest of the 5.
						It then prints a report of the score that was dropped and the final average.
	Input:				int n1, int n2, int n3, int n4, int n5
						Five numbers/scores gotten through calling getInput 5 times in the driver function.
	Return:				None. */
void hw8ex2_calcAverage(int n1, int n2, int n3, int n4, int n5) {
	// call hw8ex2_findLowest() to determine which score is the minimum
	int minimum = hw8ex2_findLowest(n1, n2, n3, n4, n5);

	// calculate the average excluding that minimum
	double average = ((n1 + n2 + n3 + n4 + n5) - minimum) / 4.0;

	// print the report
	cout << endl << "Dropped score: " << minimum << endl;
	cout << "Final average: " << fixed << setprecision(2) << average << endl << endl;
}



/*	HW #9 Exercise #1 (4/29/2019): 
	This assignment uses 3 helper functions (with prototypes) in addition to its driver function. Additionally, 2 global constants are used.
	The assignment transfers the contents of 2 .txt input files, a standard one and a test one, into arrays.
   	It then uses a linear search function to search for the LSTest values within the LSStandard array. */
void hw9ex1() {
	// This driver function body was formerly contained within main() of hw9ex1's own source file.

	// name standard input file
	string inputFileStandardName = "hw9ex1_LSStandard.txt";

	// name test input file
	string inputFileTestName = "hw9ex1_LSTest.txt";

	// create arrays for both input files
	int LSStandard[hw9ex1_STANDARD_SIZE];
	int LSTest[hw9ex1_TEST_SIZE];

	// call readArray on both files
	int standardElems = hw9ex1_readArray(LSStandard, hw9ex1_STANDARD_SIZE, inputFileStandardName);
	int testElems = hw9ex1_readArray(LSTest, hw9ex1_TEST_SIZE, inputFileTestName);

	// call searchManager on both files
	hw9ex1_searchManager(LSStandard, standardElems, LSTest, testElems);
}
/*	Helper Function:	hw9ex1_readArray()
	Descr:				This function reads the contents of an input file, and reads that data into the array. 
		   				It uses a counter currentElem and a while loop to achieve this.
						It then returns currentElem (the number of elements actually passed into the array).
	Input:				int stdList[], int maxElems, string inputFileName
						An array of numbers, the maximum size for that array, and and input file containing those numbers.
	Return:				int currentElem
           				The number of elements, which will be -1 if the read was unsuccessful. */
int hw9ex1_readArray(int stdList[], int maxElems, string inputFileName) {
	// creates the input file and opens it
	ifstream inputFile;
	inputFile.open(inputFileName);

	int currentElem = 0;

	// the input file was successfully opened
	if (inputFile)
	{
		// read data from the input file directly into the array, then close the file
		currentElem = 0;
		while (currentElem < maxElems && inputFile >> stdList[currentElem])
		{
			currentElem++;
		}
		inputFile.close();
	
	}
	// the input file was not successfully opened
	else
	{
		cout << "File \"" << inputFileName << "\" could not be opened" << endl;
		currentElem = -1;
	}

	return currentElem;
}
/*	Helper Function:	hw9ex1_searchList()
	Descr:				This function loops through the argument array to search for the argument value.
						Once the value has been found, the loop breaks.
						In order to search for this value again through the remainder of the array, 
						the starting index for the search is set to equal the index after
						the index at which the value was found.
						If the value was not found at all, this starting index is reset to 0, 
						allowing the loop to restart from the beginning of the array.
	Input:				int stdList[], int numElems, int value
						The array being searched through, the number of elements in it, and the value being searched for.
	Return:				int matchIndex
						The index at which the value was found. */
int hw9ex1_searchList(int stdList[], int numElems, int value) {
	// index to start searching at
	static int startIndex = 0;

	// index where the test value has been located at in the standard array
	int matchIndex = -1;
	for (int i = startIndex; i < numElems; i++)
	{
		// the match has been found at index i
		if (stdList[i] == value)
		{
			matchIndex = i;		// set the index of the match to equal i
			startIndex = i+1;	// set the new index to start searching from to equal i+1
			break;
		}
	}

	// the match was not found at all
	if (matchIndex == -1)
	{
		startIndex = 0;			// set the new index to start searching from the first index again
	}

	return matchIndex;
}
/*	Helper Function:	hw9ex1_searchManager()
	Descr:				This function searches for the LSTest values within the LSStandard array.
						If a match has been found, hw9ex1_searchList() is called again to determine 
						if the value is located anywhere else in LSStandard after the index where it was found.
	Input:				int LSStandard[], int standardElems, int LSTest[], int testElems
						The array being searched through, the number of elements in it, 
						the array of values to search for, the number of elements in it.
	Return:				None. */
void hw9ex1_searchManager(int LSStandard[], int standardElems, int LSTest[], int testElems)
{
   int value = 0;			// search value
   int matchIndex = -1;		// index where the value was found
   int numberOfMatches = 0;	// number of matches for the given value

   for (int i = 0; i < testElems; i++)
   {
      // call the linear search on every value at i
      value = LSTest[i];
      matchIndex = hw9ex1_searchList(LSStandard, standardElems, value);
      numberOfMatches = 0;

      // the test value was not found in the standard array
      if (matchIndex == -1)
      {
         cout << "Number " << (i + 1) << " (" << setw(3) << value << ") was not located in the file." << endl;
      }
      // the test value was found in the standard array
      else
      {
         cout << "Number " << (i + 1) << " (" << setw(3) << value << ") was located at index(es)";
         
         numberOfMatches = 1;				// one match has been found at this point

         while (matchIndex > -1)
         {
            if (numberOfMatches == 1)
            {
               cout << " " << matchIndex;	// for the first match, don't print a comma before it
            }
            else
            {
               cout << ", " << matchIndex;	// print every subsequent match with a comma before it
            }

            // call the linear search from the following index, and increment the number of matches found
            matchIndex = hw9ex1_searchList(LSStandard, standardElems, value);
            numberOfMatches++;
         }
         cout << "." << endl;
      }
   }
}



/*	HW #9 Exercise #2 (4/29/2019): 
	This assignment uses 4 helper functions (with prototypes) in addition to its driver function. Additionally, 3 global constants are used.
	The assignment compares an array of the correct answers for an exam to an array of multiple students' answers.
	It then displays reports for each student's grade and the lowest/highest scorers on the exam. */
void hw9ex2() {
	// This driver function body was formerly contained within main() of hw9ex2's own source file.

	// create arrays for both the student's answers and the correct answers
	char studentResponses[hw9ex2_STUDENT_RESP_ARRAY_SIZE];
	char correctResponses[hw9ex2_CORRECT_RESP_ARRAY_SIZE];

	// input a file name
	string inputFileName;
	cout << "Please enter the name of the input file containing all students' answers: ";
	// the input files provided are hw9ex2_StudentsListLong.txt or hw9ex2_StudentsListShort.txt
	cin >> inputFileName;

	// call hw9ex2_readArray() on the students' answers
	int studentResponseCount = hw9ex2_readArray(studentResponses, hw9ex2_STUDENT_RESP_ARRAY_SIZE, inputFileName);
	int correctResponseCount = -1;

	// only call hw9ex2_readArray() on the correct answers if the call on the students' answers worked
	if (studentResponseCount > 0)
	{
		// input the file with the correct answers
		cout << "Please enter the name of the input file containing the correct answers: ";
		cin >> inputFileName;	// the input file provided is hw9ex2_CorrectList.txt
		correctResponseCount = hw9ex2_readArray(correctResponses, hw9ex2_CORRECT_RESP_ARRAY_SIZE, inputFileName);
	}

	// only call hw9ex2_displayResults() on both arrays if both calls on hw9ex2_readArray() have worked
	if (studentResponseCount > 0 && correctResponseCount > 0)
	{
		hw9ex2_displayResults(studentResponses, studentResponseCount, correctResponses, correctResponseCount);
	}
}
/*	Helper Function:	hw9ex2_readArray()
	Descr:				This function reads the contents of an input file, and reads that data into the array. 
						It uses a counter numElems and a while-loop to achieve this.
						It then returns numElems (the number of elements actually passed into the array).
	Input:				char response[], int maxArraySize, string inputFileName
						An array of any set of responses, the maximum size for that array, 
						and and input file containing those responses.
	Return:				int numElems
						The number of elements, which will be -1 if the read was unsuccessful. */
int hw9ex2_readArray(char response[], int maxArraySize, string inputFileName) {
	// creates the input file and opens it
	ifstream inputFile;
	inputFile.open(inputFileName);

	// counter for the file-to-array read
	int numElems = 0;

	// the input file was successfully opened
	if (inputFile)
	{
		// read data from the input file directly into the array, then close the file
		numElems = 0;
		while (numElems < maxArraySize && inputFile >> response[numElems])
		{
			numElems++;
		}
		inputFile.close();

	}
	// the input file was not successfully opened
	else
	{
		cout << "File \"" << inputFileName << "\" could not be opened" << endl;
		numElems = -1;
	}
	return numElems;
}
/*	Helper Function:	hw9ex2_displayResults()
	Descr:				This function compares the array of correct answers to every set of one student's responses
						within the array of students' answers.
						It creates arrays for the question numbers, the student's incorrect responses, 
						the correct responses corresponding to the student's incorrect responses, 
						and the grades of all the students. 
						For each student, a report is outputted containing the number of questions they got wrong, 
						their grades, and the list of questions they answered incorrectly, 
						accompanied by their own incorrect responses alongside the correct response. 
		   				Once all the students' reports have been outputted, the highest and lowest grades among them are found.
	Input:				char studentResponses[], int studentArraySize, char correctResponses[], int correctArraySize
        				Array of students' answers, its size, array of correct answers, its size.
	Return:				None. */
void hw9ex2_displayResults(char studentResponses[], int studentArraySize, char correctResponses[], int correctArraySize) {
	int numStudents = studentArraySize / correctArraySize;	// the number of students in the student array
	double studentGrade = -1.0;								// the grade for each student
	int incorrectCounter = 0;								// accumulator for a student's incorrect answers
	int studentIndex = 0;									// index of each student in the student array

	int missedQuestionNumber[hw9ex2_CORRECT_RESP_ARRAY_SIZE];	// array of the questions numbers each student missed
	char incorrectResponse[hw9ex2_CORRECT_RESP_ARRAY_SIZE];		// array of the incorrect answer choices each student put
	char correctResponse[hw9ex2_CORRECT_RESP_ARRAY_SIZE];		// array of the correct answer choices to each missed question
	double studentGrades[hw9ex2_MAX_NUMBER_OF_STUDENTS];		// array of the grades of all the students

	// create an output file, name it, and open it
	ofstream outputFile;
	outputFile.open("hw9ex2_ExamAnalysis.txt");

	// looping through each student in the array of students' answers
	for (int currentStudent = 0; currentStudent < numStudents; currentStudent++)
	{
		// reinitialize the incorrect answers counter to 0
		incorrectCounter = 0;

		// begin the report for the student
		cout << "Report for Student " << (currentStudent + 1) << ":" << endl << "---------------------" << endl;
		outputFile << "Report for Student " << (currentStudent + 1) << ":" << endl << "---------------------" << endl;

		// loop through each question in one student's set of answers
		for (int currentQuestion = 0; currentQuestion < correctArraySize; currentQuestion++)
		{
			// calculate the index of the student's response
			studentIndex = currentStudent * hw9ex2_CORRECT_RESP_ARRAY_SIZE + currentQuestion;

			// the student's answer doesn't match the correct answer, meaning it is incorrect
			if (studentResponses[studentIndex] != correctResponses[currentQuestion])
			{
				// input this question's number and answers to the proper arrays, and increment the missed question counter
				missedQuestionNumber[incorrectCounter] = currentQuestion;
				incorrectResponse[incorrectCounter] = studentResponses[studentIndex];
				correctResponse[incorrectCounter] = correctResponses[currentQuestion];
				incorrectCounter++;
			}
		}

		// output the rest of the report for the student
		studentGrades[currentStudent] = (double(hw9ex2_CORRECT_RESP_ARRAY_SIZE - incorrectCounter) / hw9ex2_CORRECT_RESP_ARRAY_SIZE) * 100.0;
		
		cout << "Missed " << incorrectCounter << " out of " << correctArraySize << " questions for " << studentGrades[currentStudent] << "% correct." << endl;
		outputFile << "Missed " << incorrectCounter << " out of " << correctArraySize << " questions for " << studentGrades[currentStudent] << "% correct." << endl;
		cout << "Questions missed:" << endl;
		outputFile << "Questions missed:" << endl;

		// properly output commas or spaces for the desired output (listing the incorrect questions)
		for (int currentMissedQuestion = 0; currentMissedQuestion < incorrectCounter; currentMissedQuestion++)
		{
			if (currentMissedQuestion == 0)
			{
				cout << "  ";
				outputFile << "  ";
			}
			else
			{
				cout << ", ";
				outputFile << ", ";
			}
			cout << missedQuestionNumber[currentMissedQuestion] + 1;
			outputFile << missedQuestionNumber[currentMissedQuestion] + 1;

			cout << " (" << incorrectResponse[currentMissedQuestion];
			outputFile << " (" << incorrectResponse[currentMissedQuestion];

			cout << "/" << correctResponse[currentMissedQuestion] << ")";
			outputFile << "/" << correctResponse[currentMissedQuestion] << ")";
		}

		cout << endl;
		outputFile << endl;

		// determine whether the student passed or failed the exam
		if (studentGrades[currentStudent] >= 70.0)
		{
			cout << "This student passed the exam!" << endl;
			outputFile << "This student passed the exam!" << endl;
		}
		else
		{
			cout << "This student failed the exam." << endl;
			outputFile << "This student failed the exam." << endl;
		}

		cout << endl;
		outputFile << endl;
	}

	// find the highest score
	int indexForMax = -1;
	double max = hw9ex2_largestValue(studentGrades, numStudents, indexForMax);
	cout << "Student " << (indexForMax + 1) << " had the best grade with " << max << "%." << endl;
	outputFile << "Student " << (indexForMax + 1) << " had the best grade with " << max << "%." << endl;

	// find the lowest score
	int indexForMin = -1;
	double min = hw9ex2_smallestValue(studentGrades, numStudents, indexForMin);
	cout << "Student " << (indexForMin + 1) << " had the worst grade with " << min << "%." << endl;
	outputFile << "Student " << (indexForMin + 1) << " had the worst grade with " << min << "%." << endl;

	outputFile.close();
}
/*	Helper Function:	hw9ex2_smallestValue()
	Descr:				This function loops through the argument array to find the smallest value it contains.
						Since it needs to yield both the smallest value and the index of this value, 
						the former is the function's return value and the latter is passed by reference.
	Input:				double values[], int numValues, int & indexForMin
						Array of values, number of values in that array, and the index of the array's smallest value
                        (which is passed by reference so it can be used outside this function).
	Return:				double min
						The smallest value in the array. */
double hw9ex2_smallestValue(double values[], int numValues, int & indexForMin) {
	double min = values[0];
	indexForMin = 0;

	for (int currentElem = 1; currentElem < numValues; currentElem++)
	{
		if (values[currentElem] < min)
		{
			min = values[currentElem];
			indexForMin = currentElem;
		}
	}
	return min;
}
/*	Helper Function:	hw9ex2_largestValue()
	Descr:				This function loops through the argument array to find the largest value it contains.
						Since it needs to yield both the largest value and the index of this value, 
						the former is the function's return value and the latter is passed by reference.
	Input:				double values[], int numValues, int & indexForMax
						Array of values, number of values in that array, and the index of the array's largest value
						(which is passed by reference so it can be used outside this function).
	Return:   			double max
           				The largest value in the array. */
double hw9ex2_largestValue(double values[], int numValues, int & indexForMax) {
	double max = values[0];
	indexForMax = 0;

	for (int currentElem = 1; currentElem < numValues; currentElem++)
	{
		if (values[currentElem] > max)
		{
			max = values[currentElem];
			indexForMax = currentElem;
		}
	}
	return max;
}