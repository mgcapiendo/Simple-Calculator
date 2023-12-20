
/*
Manuel Capiendo

Simple Calculator

*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h> //for fmod
#include <ctype.h> //for toupper


void Greeting();
char Menu();
void Input(double* num1, double* num2);
void Calculate(double num1, double num2, char choice); 
void New();
void Goodbye();

int main() {
	char choice; 
	double num1;
	double num2;
	int on = 1;

	Greeting();

	do {
		Input(&num1, &num2);
		choice = Menu();
		Calculate(num1, num2, choice);

		if (choice == 'E') {
			break;
		}

		char NChoice;
		do {
			printf("\nWould You Like To Start A New Calculation?\n(Y) Or (N): ");
			scanf(" %c", &NChoice);

			NChoice = toupper(NChoice);

			if (NChoice == 'Y') {
				printf("\nStarting New Calculation\n");
				break;
			}
			else if (NChoice == 'N') {
				break;
			}
			else {
				printf("\nInvalid Input\n");
			}
		} while (NChoice != 'Y' || NChoice != 'N');

		if (NChoice == 'N') {
			break;
		}

	} while (choice != 'E'); 

	Goodbye(); 
}

void Greeting() 
{ 
	printf("\n | ------------------------------------------------------- |\n");
	printf("\n | Calculate Two Numbers Using Any Operator Available In C |\n");
	printf("\n | ------------------------------------------------------- |\n");
}

void Input(double* num1, double* num2) { 
	do {
		printf("\nEnter First Number (No Longer Than 9 Digits): ");
		scanf(" %lf", num1);
		if (*num1 > 999999999 || *num1 < -999999999) {
			printf("\nLonger Than 9 Digits\n");
		}
		else {
			break;
		}
	} while (1);

	do {
		printf("\nEnter Second Number (No Longer Than 9 Digits): ");
		scanf(" %lf", num2); 
		if (*num2 > 999999999 || *num2 < -999999999)
		{
			printf("\nLonger Than 9 Digits\n"); 
		}
		else
		{
			break;
		}
	} while (1);
}

char Menu()
{
	char choice;
	char next = 'N';

	do {
		printf("\nWhat Would You Like To Do?");
		printf("\n---------------------------");
		printf("\nSelect (A) To Add");
		printf("\nSelect (S) To Substract");
		printf("\nSelect (M) To Multiply");
		printf("\nSelect (D) To Divide");
		printf("\nSelect (R) To Remainder");
		printf("\nSelect (E) To Exit");
		printf("\n---------------------------");

		printf("\nEnter Choice: ");
		scanf(" %c", &choice);

		choice = toupper(choice); 
		
		printf("\nYou Have Selected "); 
	
		switch (choice) {

		case 'A':
			printf("Addition");
			printf("\n---------------------------");
			break;

		case 'S':
			printf("Subtract");
			printf("\n---------------------------");
			break;

		case 'M':
			printf("Multiply");
			printf("\n---------------------------");
			break;

		case 'D':
			printf("Divide");
			printf("\n---------------------------");
			break;

		case 'R':
			printf("Remainder");
			printf("\n---------------------------");
			break;

		case 'E':
			printf("Exit");
			printf("\n---------------------------");
			break;

		default:
			printf("An Invalid Input\n");
			break;
		}

		printf("\nIs This Correct? ");

		printf("\n(Y) Or (N): ");
		scanf(" %c", &next);

		next = toupper(next);

		if (next == 'N') {
			printf("\n   | Pick Again |\n");
		}
		else if (next == 'Y') {
			break;
		}
		else {
			printf("\nInvalid Input\n");
		}
	} while (1);

	return choice; 
}

void Calculate(double num1, double num2, char choice)
{
	double answer;

	switch (choice) {
	case 'A':
		//Add
		answer = num1 + num2;
		printf("\n---------------------------\n");
		printf("\n%.2lf + %.2lf = %.2f\n", num1, num2, answer);
		printf("\n---------------------------\n");
		break;

	case 'S':
		//Subtract
		answer = num1 - num2;
		printf("\n---------------------------\n");
		printf("\n%.2lf - %.2lf = %.2f\n", num1, num2, answer);
		printf("\n---------------------------\n");
		break;

	case 'M':
		//Multiply
		answer = num1 * num2;
		printf("\n---------------------------\n");
		printf("\n%.2lf * %.2lf = %.2f\n", num1, num2, answer);
		printf("\n---------------------------\n");
		break;

	case 'D':
		//Divide
		if (num1 == 0 && num2 == 0) { 
			answer = 0;
			printf("\n---------------------------\n"); 
			printf("\n%.2lf / %.2lf = %.2f\n", num1, num2, answer); 
			printf("\n---------------------------\n"); 
			break;
		} 
		else if (num1 == 0 || num2 == 0) {
			printf("\nError. Cannot Divide By 0\n");
			break;
		}
		else {
			answer = num1 / num2; 
		}
		printf("\n---------------------------\n");
		printf("\n%.2lf / %.2lf = %.2f\n", num1, num2, answer);
		printf("\n---------------------------\n");
		break;

	case 'R':
		//Remainder
		answer = fmod(num1, num2);//Calculates the remainder of a double  
		printf("\n---------------------------\n");
		printf("\n%.2lf %% %.2lf = %.2f\n", num1, num2, answer);
		printf("\n---------------------------\n");
		break;

	case 'E':
			break;

	default:
		printf("\n\nInvalid Input");

	}
}

void Goodbye() 
{
	printf("\nClosing Calculator");
} 

