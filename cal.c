#include <stdio.h>
// Using structures
struct user_input {
	
	// Users choice, Int or Float
	int iorf;
	// User's inputs. 2 numerics.
	int inte1;
	int inte2;
	
	// User's inputs.(Float) 2 numerics.
        float flt1;
        float flt2;


	// operator, TODO make it string if I have enoug time.
	int openum;
};

int main (void)
{
	// structure
	// input tmp values as my book says 
	// "setting values to a structure at the time of initiation is a good manner "
	struct user_input ui = {1, 11, 22, 1.1, 2.4, 3};
	
	// File and data
	FILE *fp;
	fp = fopen ("result.txt", "w");
	
	// result of calculation
	int res;
	float resf;
		
	// Get the user's inputs
	//foat or Int
	printf("Please input Int or Float, int:1 , float:2 :");
	scanf("%d", &ui.iorf);

	if (ui.iorf == 1){
		printf("please input 1st numeric:");
		scanf("%d", &ui.inte1);
		printf("please input 2nd numeric:");
		scanf("%d", &ui.inte2);
	} else if (ui.iorf == 2) {
		printf("please imput 1st float:");
		scanf("%f", &ui.flt1);
		printf("please input 2nd float:");
		scanf("%f", &ui.flt2);
	}

	// input operator number
	printf("please input the operator, plus:1 minus:2 multiple:3 divide:4 ::");
	scanf("%d", &ui.openum);
	
	// operator (plus)
	// TODO make it const and use in the switch syntax.
	const int plus_ope = 1;
	int minus_ope = 2;
	int multi_ope = 3;
	int divide_ope = 4;
	
	// Calculations and display

	if (ui.iorf == 1){	
		switch (ui.openum) {
		case 1:
			res = ui.inte1 + ui.inte2;
			
			break;
		
		case 2:
			res = ui.inte1 - ui.inte2;
			
			break;
			
		case 3:
			res = ui.inte1 * ui.inte2;
			
			break;
			
		case 4:
			res = ui.inte1 / ui.inte2;
			
			break;
			
			
		default:
			printf("switch syntax go into failed\n");
			res = 999;
		}
	}
	else if(ui.iorf == 2){
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
			resf = 88.99;
		}
	}
	if (fp == NULL) {
		printf("failed to open file . \n");
	}
	else {
		// operation to the file.
		if (ui.iorf == 1){
			printf( "Calculation Result is %d\n", res);

			// write file the users input
			fprintf(fp, "1st input: 2nd input:  Calculation operand plus:1 minus:2 multiple:3 divide:4 \n");		
			fprintf(fp, "%d %d %d\n", ui.inte1, ui.inte2, ui.openum );
		
		
			// write file the calc result
			fprintf(fp, "Calculation result:   \n" );		
			fprintf(fp, "%d\n", res );
		} else if (ui.iorf == 2) {
			printf( "Calculation Result(float) is %f\n", resf);
			// write file the users input
			fprintf(fp, "1st input: 2nd input:  Calculation operand plus:1 minus:2 multiple:3 divide:4 \n");		
			fprintf(fp, "%f %f %d\n", ui.flt1, ui.flt2, ui.openum );
		
		
			// write file the calc result
			fprintf(fp, "Calculation result in float:   \n" );		
			fprintf(fp, "%f\n", resf );
		}
		
		
		
		fclose(fp);
	}
	

    return 0;
}

//TODO Float funcition
void fltCalc()
{
	
}
