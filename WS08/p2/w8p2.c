/*
*****************************************************************************
						  Workshop - #8 (P2)
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

// User-Defined Libraries
#include"w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
void openingMessage(int number_of_products)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", number_of_products);
	printf("NOTE: A 'serving' is %dg\n\n", GMS_PER_SERVE);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int product_number)
{
	struct CatFoodInfo Products[MAX_PRODUCTS];

	printf("Cat Food Product #%d\n", product_number + 1);
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* weight_in_lbs, double* converted_value_in_kg)
{
	double value = 0;
	value = (*weight_in_lbs) / LBS_TO_KGS;
	if (converted_value_in_kg != NULL)
	{
		*converted_value_in_kg = value;
	}
	return value;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs_convert, int* converted_value_in_gms)
{
	double value = 0;
	convertLbsKg(lbs_convert, &value);
	value = value * 1000;
	if (converted_value_in_gms != NULL)
	{
		*converted_value_in_gms =(int) value;
	}
	return (int)value;
}

// 10. convert lbs: kg and g
void convertLbs(const double* weight_in_lbs, double* value_in_kgs, int* value_in_gms)
{
	convertLbsKg(weight_in_lbs, value_in_kgs);
	convertLbsG(weight_in_lbs, value_in_gms);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size_gms, const int total_gms_in_product, double* number_of_servings)
{
	double value = 0;
	value = (double)total_gms_in_product / (double)serving_size_gms;
	if (number_of_servings != NULL)
	{
		*number_of_servings = value;
	}
	return value;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* product_price, const double* number_of_servings, double* cost_per_serving)
{
	double value = 0;
	value = (*product_price) / (*number_of_servings);
	if (cost_per_serving != NULL)
	{
		*cost_per_serving = value;
	}
	return value;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price_per_serve, const double* total_calories, double* cost_per_calorie)
{
	double value = 0;
	value = (*price_per_serve) / (*total_calories);
	if (cost_per_calorie != NULL)
	{
		*cost_per_calorie = value;
	}
	return value;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo cat_food_products)
{
	struct ReportData Report_of_Products = { 0 };
	double totalCal;

	Report_of_Products.sku = cat_food_products.product_sku;
	Report_of_Products.price = cat_food_products.product_price;
	Report_of_Products.calories_per_serving = cat_food_products.calories_per_serve;
	Report_of_Products.weight_in_lbs = cat_food_products.weight_of_product_lbs;
	convertLbsKg(&Report_of_Products.weight_in_lbs, &Report_of_Products.weight_of_product_kgs);
	convertLbsG(&Report_of_Products.weight_in_lbs, &Report_of_Products.weight_of_product_gms);
	calculateServings(GMS_PER_SERVE, Report_of_Products.weight_of_product_gms, &Report_of_Products.total_servings);
	calculateCostPerServing(&Report_of_Products.price, &Report_of_Products.total_servings, &Report_of_Products.cost_per_serving);
	totalCal = cat_food_products.calories_per_serve * Report_of_Products.total_servings;
	calculateCostPerCal(&Report_of_Products.price, &totalCal, &Report_of_Products.cost_of_calories_per_serve);

	return Report_of_Products;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GMS_PER_SERVE);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData( struct ReportData Analysis_Report, const int cheapest_product_index)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", Analysis_Report.sku, Analysis_Report.price, Analysis_Report.weight_in_lbs, Analysis_Report.weight_of_product_kgs, Analysis_Report.weight_of_product_gms, Analysis_Report.calories_per_serving, Analysis_Report.total_servings,Analysis_Report.cost_per_serving, Analysis_Report.cost_of_calories_per_serve);
	
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest_product)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%0.2lf\n\n", cheapest_product.product_sku, cheapest_product.product_price);
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int count = 0, cheapest_product_index = 0;
	double least_cost = 0;
	struct CatFoodInfo CatFoodProducts[MAX_PRODUCTS];
	struct ReportData CatFoodProductReport[MAX_PRODUCTS];
	openingMessage(MAX_PRODUCTS);
	for (count = 0; count < MAX_PRODUCTS; count++)
	{
		CatFoodProducts[count] = getCatFoodInfo(count);
		CatFoodProductReport[count] = calculateReportData(CatFoodProducts[count]);
	}
	least_cost = CatFoodProductReport[0].cost_per_serving;
	
		
	displayCatFoodHeader();
	for (count = 0; count < MAX_PRODUCTS; count++)
	{
		displayCatFoodData(CatFoodProducts[count].product_sku, &CatFoodProducts[count].product_price, &CatFoodProducts[count].weight_of_product_lbs, CatFoodProducts[count].calories_per_serve);
		if (CatFoodProductReport[count].cost_per_serving < least_cost)
		{
			least_cost = CatFoodProductReport[count].cost_per_serving;
			cheapest_product_index = count;
		}
	}
	printf("\n");
	displayReportHeader();
	for (count = 0; count < MAX_PRODUCTS; count++)
	{
		displayReportData(CatFoodProductReport[count], cheapest_product_index);
		if (cheapest_product_index == count)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
		
	}
	displayFinalAnalysis(CatFoodProducts[cheapest_product_index]);
}
