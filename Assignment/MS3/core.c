/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "core.h"
#include <ctype.h>

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
//1. Checks if the input value is an integer.
int inputInt(void)
{
	int value = 0, flag = 0, scanf_return = 0;
	char after_character = 0;
	do
	{
		scanf_return = scanf("%d%c", &value, &after_character);

		if (scanf_return == 0 || after_character != '\n')
		{
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}
		else
		{
			flag = 1;
		}
	} while (flag == 0);

	return value;
}

//2. Checks if the input value is a positive integer.
int inputIntPositive(void)
{
	int value = 0, flag = 0, scanf_return = 0;
	char after_character = 0;
	do
	{
		scanf_return = scanf(" %d%c", &value, &after_character);

		if (scanf_return == 0 || after_character != '\n')
		{
			printf("ERROR! Value must be > 0: ");
			clearInputBuffer();
		}
		else
		{
			if (value < 0)
			{
				printf("ERROR! Value must be > 0: ");
			}
			else
			{
				flag = 1;
			}
		}
	} while (flag == 0);

	return value;
}

//3. Checks if the input value is an positive integer lying in the specified range.
int inputIntRange(int lower_limit, int upper_limit)
{
	int value = 0, flag = 0, scanf_return = 0;
	char after_character = 0;
	do
	{
		scanf_return = scanf(" %d%c", &value, &after_character);

		if (scanf_return == 0 || after_character != '\n')
		{
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}
		else
		{
			if (value < lower_limit || value > upper_limit)
			{
				printf("ERROR! Value must be between %d and %d inclusive: ", lower_limit, upper_limit);
			}
			else
			{
				flag = 1;
			}
		}
	} while (flag == 0);

	return value;
	return 0;
}

//4. Checks if the character entered matches any character in the passed C string.
char inputCharOption(const char valid_chars[])
{
	char input_char, after_character = 0;
	int scanf_return = 0, count = 0, flag = 0;

	do
	{
		scanf_return = scanf(" %c%c", &input_char, &after_character);
		count = 0;
		if (scanf_return == 0 || after_character != '\n')
		{
			printf("ERROR: Character must be one of [%s]: ", valid_chars);
			clearInputBuffer();
		}
		else
		{
			while (valid_chars[count] != '\0' && flag == 0)
			{

				if (input_char == valid_chars[count])
				{
					flag = 1;
				}
				count++;
			}
			if (flag == 0)
			{
				printf("ERROR: Character must be one of [%s]: ", valid_chars);
			}
		}
	} while (flag == 0);


	return input_char;
}

//5. Helps to obtain a string in the specified range passed in the 2nd and 3rd arguments.
void inputCString(char* input_string, int minimum_chars, int maximum_chars)
{
	char string[100] = { '\0' };
	int length_of_string = 0, count = 0, flag = 0;
	do
	{
		scanf(" %[^\n]", string);

		length_of_string = 0;
		for (count = 0; string[count] != '\0'; count++)
		{
			length_of_string++;
		}

		if (length_of_string <= maximum_chars && length_of_string >= minimum_chars)
		{
			for (count = 0; string[count] != '\0'; count++)
			{
				input_string[count] = string[count];
			}
			flag = 1;
			input_string[count] = '\0';
		}
		else
		{
			if (minimum_chars == maximum_chars)
			{
				printf("Invalid %d-digit number! Number: ", maximum_chars);
			}
			else if (length_of_string <= minimum_chars)
			{
				printf("ERROR: String length must be between %d and %d chars: ", minimum_chars, maximum_chars);
			}
			else if (length_of_string >= maximum_chars)
			{
				printf("ERROR: String length must be no more than %d chars: ", maximum_chars);
			}
			clearInputBuffer();
		}

	} while (flag == 0);
}

//6. Used to display the phone number in a well formatted structure.
void displayFormattedPhone(const char* input_number)
{
	int count = 0, flag_all_digit = 0;
	if (input_number == NULL)
	{
	}
	else
	{
		for (count = 0; input_number[count] != '\0'; count++)
		{
			if (isdigit(input_number[count]) == 0)
			{
				printf("(___)___-____");
				flag_all_digit = 1;
			}
		}
	}
	if (count != 10 && flag_all_digit == 0)
	{
		printf("(___)___-____");
	}
	else if (flag_all_digit == 0)
	{
		printf("(%c%c%c)%c%c%c-%c%c%c%c", input_number[0], input_number[1], input_number[2], input_number[3], input_number[4], input_number[5], input_number[6], input_number[7], input_number[8], input_number[9]);
	}
	return;
}




//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

