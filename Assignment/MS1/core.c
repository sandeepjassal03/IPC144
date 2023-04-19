/*
*****************************************************************************
						Assignment 1 - Milestone 1
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

#include<stdio.h>
#include<ctype.h>

#include "core.h"

// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
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

//1. 
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
//2.
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

//3.
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

//4.
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

//5.
void inputCString(char *input_string, int minimum_chars, int maximum_chars)
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
			}
			else
			{
				if (minimum_chars == maximum_chars)
				{
					printf("ERROR: String length must be exactly %d chars: ", maximum_chars);
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

//6.
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
	else if(flag_all_digit==0)
	{
		printf("(%c%c%c)%c%c%c-%c%c%c%c", input_number[0], input_number[1], input_number[2], input_number[3], input_number[4], input_number[5], input_number[6], input_number[7], input_number[8], input_number[9]);
	}
	return;
}

