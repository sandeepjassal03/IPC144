/*
*****************************************************************************
						  Workshop - #8 (P1)
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


// System Libraries
#include<stdio.h>

// User Libraries
#include"w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* testInt)
{
	int value = 0;
	do
	{
		scanf(" %d", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);
	if (testInt != NULL)
	{
		*testInt = value;
	}
	return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* testInt)
{
	double value = 0;
	do
	{
		scanf(" %lf", &value);
		if (value <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (value <= 0);
	if (testInt != NULL)
	{
		*testInt = value;
	}
	return value;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", GMS_PER_SERVE);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int product_number)
{
	struct CatFoodInfo Products[MAX_PRODUCTS];

	printf("Cat Food Product #%d\n", product_number+1);
	printf("--------------------\n");
	
		printf("SKU           : ");
		Products[product_number].product_sku = getIntPositive(NULL);
		printf("PRICE         : $");
		Products[product_number].product_price = getDoublePositive(NULL);
		printf("WEIGHT (LBS)  : ");
		Products[product_number].weight_of_product_lbs = getDoublePositive(NULL);
		printf("CALORIES/SERV.: ");
		Products[product_number].calories_per_serve = getIntPositive(NULL);
		printf("\n");
		return Products[product_number];
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int product_sku, const double* product_price, const double* weight_in_lbs, const int cal_per_serve)
{
	printf("%07d %10.2lf %10.1lf %8d\n", product_sku, *product_price, *weight_in_lbs, cal_per_serve);
}

// 7. Logic entry point
void start(void)
{
	int count = 0;
	struct CatFoodInfo CatFoodProducts[MAX_PRODUCTS];
	openingMessage();
	for (count = 0; count < MAX_PRODUCTS; count++)
	{
		CatFoodProducts[count] = getCatFoodInfo(count);
	}
	displayCatFoodHeader();
	for (count = 0; count < MAX_PRODUCTS; count++)
	{
		displayCatFoodData(CatFoodProducts[count].product_sku, &CatFoodProducts[count].product_price, &CatFoodProducts[count].weight_of_product_lbs, CatFoodProducts[count].calories_per_serve);
	}
}