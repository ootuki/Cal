#include <stdio.h>
// Using structures
typedef struct {
	
	// User's inputs.(Float) 2 numerics.
	float flt1;
	float flt2;

	// operator, in char
	char opec;
}user_input;
// function declarations
user_input getUserInput();
int convertInt (char);
float calc (float, float, int);
int fileInit ();
int fileWrt (float , float , char , float, int );

// main function
int main (void)
{
	// structure
	// input tmp values as my text book says that
	// "setting values to a structure at the time of initiation is a good manner "
	user_input ui;
	ui.flt1 = 1.1;
	ui.flt2 = 2.2;
	ui.opec = '+';
	
	float flt1;
	float flt2;
	int openum;
	char opec;
	// result of calculation
	float resf = 88.8;
	
	// flag to evaluate loop or not
	int flagLoop = 1;

	// user's decision, if continue calc or not. (y/n)
	char contc;
	
	// Boolean mentions file handle failed or not (0: not failed(success) 1: fail)
	int failed = 0;
	
	// count of the calculations.
	int calCount = 0;
	
	// initialize the file.
	fileInit ();
	while (flagLoop) {
		
		ui = getUserInput();

		// prepare some valuables to stock values in "ui" structure. 
		// Otherwise a duplicated structure declaration is mandatory inside the fileWrt function.
		// TODO ask Pranav san that which is the good manner. 
		// Prepare a temp storages or again declare in another function, which one is better.
		flt1 = ui.flt1;
		flt2 = ui.flt2;
		
		opec = ui.opec;
		
		// convert from char to int
		openum = convertInt (opec); 
		
		// calculate
		resf = calc(flt1, flt2, openum);
		// increments the count
		calCount++;
		
		// ask the user if continue calc or not.		
		printf("Wish to continue next calculation?(y/n)\n");
		getchar();
		scanf("%c", &contc);
		
		// write the result to the file.
		failed = fileWrt(flt1, flt2, opec, resf, calCount);
		// if filehandling get failed, print the error.
		if (failed == 1) {
			perror("failed on file handling. \n");
	}
		
		if (contc == 'n') {
			printf("Thank you for using. \n");
			flagLoop = 0;
		} else if (contc == 'y') {
			flagLoop = 1;
		} else {
			perror("Error:Invalid charactor input. \n");
			return 0;
		}
	}
	
	
	
	return 0;
}
user_input getUserInput() 
{
	user_input ui;
	ui.flt1 = 3.3;
	ui.flt2 = 4.4;
	ui.opec = '-';

	printf("please imput your 1st number:\n");
	scanf("%f", &ui.flt1);
	printf("please input your 2nd number:\n");
	scanf("%f", &ui.flt2);

	// input operator number
	printf("please input the operator as a charactor (+ - * /) ::\n");
	// getchar() gets a char from standard input, and returns its value. 
	// Here it is used for waste a line break code (\LF\CR or \CR)
	getchar();
	scanf("%c", &ui.opec);

	return ui;
}
// convert the user input operator from char to int
int convertInt (char opec) 
{
	int openum = 1;
	if (opec == '+') {
		openum = 1;
	} else if (opec == '-') {
		openum = 2;
	} else if (opec == '*') {
		openum = 3;
	} else if (opec == '/') {
		openum = 4;
	} else {
		printf("Please input a proper operator. This program uses '+' instead of yours");
	}

	return openum;
}	

// calculation and print to standari IO
float calc (float flt1, float flt2, int openum)
{
	// return value. Result value. 98.76 is a tmp num for debugging.
	float resf = 98.76;
	// Calculations and display
	switch (openum) {
		case 1:
			resf = flt1 + flt2;
			break;
		
		case 2:
			resf = flt1 - flt2;
			break;
			
		case 3:
			resf = flt1 * flt2;
			break;
			
		case 4:
			resf = flt1 / flt2;
			break;
			
		default:
			printf("switch syntax go into failed\n");
			// 88.99 is only for a marker in the case of switch logic fails and comes to default section.
			// Remove it later.
			resf = 88.99;
		
	}
	printf("The Calculation Result is::%f\n", resf);
	
	return resf;
}
// file handle. clean and initialize the file.
fileInit ()
{
	// File and data
	FILE *fp;
	fp = fopen ("result.txt", "w");
	
	// check the file existance
	if (fp == NULL) {
		perror("failed on file initialize. \n");
	}
	else {
		// operation to the file.
		fprintf(fp, "***Calculation Result List***\n");
		fclose(fp);
	}		
}

// file handle function. Add results to the file.
// TODO let the input values be a structure.
int fileWrt (float flt1, float flt2, char opec, float resf, int calCount)
{
	// file write success or not. Boolean
	int failed = 0;
	
	// File and data
	FILE *fp;
	fp = fopen ("result.txt", "a");

	// check the file existance
	if (fp == NULL) {
		failed = 1; 
	}
	else {
		// operation to the file.
		// count and result
		fprintf(fp, "### Record of %i th calculation.\n", calCount );
		// write file the users input
		fprintf(fp, "1st input: 2nd input:  operator in char:\n");
		fprintf(fp, "%f %f %c\n", flt1, flt2, opec );
		
		// write file the calc result
		fprintf(fp, "Calculation result in float:   \n" );
		fprintf(fp, "%f\n", resf );
		
		fclose(fp);
		
		failed = 0;
	}	
	
	return failed;
}

