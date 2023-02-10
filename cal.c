#include <stdio.h>
// Using structures
struct user_input {
	
	// User's inputs.(Float) 2 numerics.
	float flt1;
	float flt2;

	// operator, TODO make it string if I have enoug time.
	int openum;
	char opec;
};
// function declarations
int convertInt (char);
float calc (float, float, int);
int fileWrt (float , float , char , float );

// main function
int main (void)
{
	// structure
	// input tmp values as my book says 
	// "setting values to a structure at the time of initiation is a good manner "
	struct user_input ui = {1.1, 2.4, 1, '+'};
	
	// result of calculation
	float resf;
	
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
	
	// 4 int constants for each operators.
	// Currently not in use. Using those in the switch syntax below, gcc errors. (C accepts only int in as-is ?)
	const int plus_ope = 1;
	const int minus_ope = 2;
	const int multi_ope = 3;
	const int divide_ope = 4;
		
	// prepare some valuables to stock values in "ui" structure. 
	// Otherwise a duplicated structure declaration is mandatory inside the fileWrt function.
	// TODO ask Pranav san that which is the good manner. Prepare a temp storages or again declare in another function.
	float flt1 = ui.flt1;
	float flt2 = ui.flt2;
	int openum = ui.openum;
	char opec = ui.opec;
	
	// convert from char to int
	openum = convertInt (opec); 
	
	// calculate
	resf = calc(flt1, flt2, openum);
	
	// Boolean mentions file handle failed or not (0: not failed(success) 1: fail)
	int failed = 0;
	
	failed = fileWrt(flt1, flt2, opec, resf);
	if (failed == 1) {
			printf("failed on file handling. \n");
	}
	
	return 0;
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
		printf("Please input a paticular operator. This program uses '+' instead of yours");
	}

	return openum;
}	

// calculation
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
	
	return resf;
}	

// file handle function
// TODO let the input values be a structure.
int fileWrt (float flt1, float flt2, char opec, float resf)
{
	// file write success or not. Boolean
	int failed = 0;
	
	// File and data
	FILE *fp;
	fp = fopen ("result.txt", "w");

	// check the file existance
	if (fp == NULL) {
		failed = 1; 
	}
	else {
		// operation to the file.
		printf( "Calculation Result(float) is %f\n", resf);
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

