/*
*****************************************************************************
						  Workshop - #6 (P1)
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
#define MAXIMUM_ITEMS 10

int main(void)
{

	const double MINIMUM_INCOME = 500;
	const double MAXIMUM_INCOME = 400000;
	const double MINIMUM_COST = 100;

	double net_income, item_cost_input = 0, items_cost[MAXIMUM_ITEMS] = { 0 }, total_cost_of_items = 0;
	int total_wish_list_items, item_number, item_priority_input, item_priority[MAXIMUM_ITEMS] = { 0 };
	char item_financeable_input, item_financeable[MAXIMUM_ITEMS] = { 0 };
	int flag = 0;


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	while (flag == 0)
	{
		printf("Enter your monthly NET income: $");
		scanf(" %lf", &net_income);
		if (net_income < MINIMUM_INCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (net_income > MAXIMUM_INCOME)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
		else
		{
			flag = 1;
		}
	}

	flag = 0;
	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf(" %d", &total_wish_list_items);

		if (total_wish_list_items <= 0 || total_wish_list_items > MAXIMUM_ITEMS)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		else if (total_wish_list_items > 0 || total_wish_list_items <= MAXIMUM_ITEMS)
		{
			flag = 1;
		}
	} while (flag == 0);

	for (item_number = 0; item_number < total_wish_list_items; item_number++)
	{
		printf("\nItem-%d Details:\n", item_number + 1);

		flag = 0;
		do
		{
			printf("   Item cost: $");
			scanf(" %lf", &item_cost_input);


			if (item_cost_input < MINIMUM_COST)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else if (item_cost_input >= MINIMUM_COST)
			{
				items_cost[item_number] = item_cost_input;
				flag = 1;
			}
		} while (flag == 0);

		flag = 0;
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &item_priority_input);

			if (item_priority_input <= 0 || item_priority_input > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else if (item_priority_input > 0 || item_priority_input < 4)
			{
				item_priority[item_number] = item_priority_input;
				flag = 1;
			}
		} while (flag == 0);

		flag = 0;
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &item_financeable_input);

			if (item_financeable_input == 'y' || item_financeable_input == 'n')
			{
				item_financeable[item_number] = item_financeable_input;
				flag = 1;
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (flag == 0);

		flag = 0;
	}

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (item_number = 0; item_number < total_wish_list_items; item_number++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", item_number + 1, item_priority[item_number], item_financeable[item_number], items_cost[item_number]);
		total_cost_of_items += items_cost[item_number];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost_of_items);
	printf("Best of luck in all your future endeavours!\n");
	return 0;
}