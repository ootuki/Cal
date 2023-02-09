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

int main (void)
{
	// structure
	// input tmp values as my book says 
	// "setting values to a structure at the time of initiation is a good manner "
	struct user_input ui = {1.1, 2.4, 1, '+'};
	
	// File and data
	FILE *fp;
	fp = fopen ("result.txt", "w");
	
	// result of calculation
	float resf;
		

	printf("please imput your 1st number:\n");
	scanf("%f", &ui.flt1);
	printf("please input your 2nd number:\n");
	scanf("%f", &ui.flt2);


	// input operator number
//	printf("please input the operator, plus:1 minus:2 multiple:3 divide:4 ::\n");
//	scanf("%d", &ui.openum);
	printf("please input the operator as a charactor (+ - * /) ::\n");
	// getchar() gets a char from standard input, and returns its value. 
	// Here it is used for waste a line break code (\LF\CR or \CR)
	getchar();
	scanf("%c", &ui.opec);
	
	// operator (plus)
	// Currently not in use. Using those in the switch syntax below, gcc errors. (C accepts only int in as-is ?)
	const int plus_ope = 1;
	const int minus_ope = 2;
	const int multi_ope = 3;
	const int divide_ope = 4;
	
	// convert the user input operator from char to int
	if (ui.opec == '+') {
		ui.openum = 1;
	} else if (ui.opec == '-') {
		ui.openum = 2;
	} else if (ui.opec == '*') {
		ui.openum = 3;
	} else if (ui.opec == '/') {
		ui.openum = 4;
	} else {
		printf("Please input a paticular operator. This program uses '+' instead of yours");
	}
	
	// Calculations and display
	switch (ui.openum) {
		case 1:
			resf = ui.flt1 + ui.flt2;
			
			break;
		
		case 2:
			resf = ui.flt1 - ui.flt2;
			
			break;
			
		case 3:
			resf = ui.flt1 * ui.flt2;
	
			
			break;
			
		case 4:
			resf = ui.flt1 / ui.flt2;
			
			break;
			
			
		default:
			printf("switch syntax go into failed\n");
			// 88.99 is only for a marker in the case of switch logic fails and comes to default section.
			// Remove it later.
			resf = 88.99;
		
	}
	
	if (fp == NULL) {
		printf("failed to open file . \n");
	}
	else {
		// operation to the file.
		printf( "Calculation Result(float) is %f\n", resf);
		// write file the users input
		fprintf(fp, "1st input: 2nd input:  operator in char:");		
		fprintf(fp, "%f %f %d\n", ui.flt1, ui.flt2, ui.opec );
	
	
		// write file the calc result
		fprintf(fp, "Calculation result in float:   \n" );		
		fprintf(fp, "%f\n", resf );
		
		fclose(fp);
	}	
	
    return 0;
}

