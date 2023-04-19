/*
*****************************************************************************
						Final Project
Participants:

1.
Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NGG

2.
Full Name  : Varun Chhabra
Student ID#: 170279210
Email      : vchhabra1@myseneca.ca
Section    : NGG

3.
Full Name  : KuldeepSinh SandipSinh Mahida
Student ID#: 167547215
Email      : kmahida1@myseneca.ca
Section    : NGG


Authenticity Declaration:
We declare this submission is the result of our own work and has not been
shared with any other student(s) or 3rd party content provider. This submitted
piece of work is entirely of our own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include"cosewic.h"

void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}


// OPTION MENUS
void menu(void)
{
	printf("=======================================================\n");
	printf("         Canada Species at Risk Analysis\n");
	printf("            (Data Years: 2010 - 2019)\n");
	printf("=======================================================\n");
	printf("1. View by year (sorted ASCENDING by year)\n");
	printf("2. View by province (sorted DESCENDING by totals)\n");
	printf("3. View by taxon (sorted ASCENDING by totals)\n");
	printf("4. View by province and taxon\n");
	printf("-------------------------------------------------------\n");
	printf("0. Exit\n");
	printf("-------------------------------------------------------\n");
	printf("Selection: ");
}

void provinceMenu(void)
{
	printf("Choose a Province\n"
		"----------------------------------\n"
		" 1) AB (Alberta)\n"
		" 2) BC (British Columbia)\n"
		" 3) MB (Manitoba)\n"
		" 4) NB (New Brunswick)\n"
		" 5) NL (Newfoundland)\n"
		" 6) NS (Nova Scotia)\n"
		" 7) NT (Northwest Territories)\n"
		" 8) NU (Nunavut)\n"
		" 9) ON (Ontario)\n"
		"10) PE (Prince Edward Island)\n"
		"11) QC (Quebec)\n"
		"12) SK (Saskatchewan)\n"
		"13) YT (Yukon Territory)\n"
		"Selection: ");
}

void TaxonMenu(void)
{
	printf("Choose a Taxon\n"
		"---------------\n"
		" 1) Mammals\n"
		" 2) Birds\n"
		" 3) Reptiles\n"
		" 4) Amphibians\n"
		" 5) Fishes\n"
		" 6) Arthropods\n"
		" 7) Molluscs\n"
		" 8) Vascular Plants\n"
		" 9) Mosses\n"
		"10) Lichens\n"
		"Selection: ");
}


// ENTRY POINT 
void mainLogic(struct FileData data[], int records)
{
	int selection;

	do {
		menu(); // Function call: executes the menu() function
		selection = inputIntRange(0, 4); // Validates if the entered value is within range and a value which is acceptable.
		putchar('\n');
		switch (selection) // SWITCH statement: Execute the block of statements as per the user entered selection
		{
		case 0: // If selection is 0, exit the application.
			printf("Application Terminated!\n\n");
			break;
		case 1: // If selection is 1, execute the viewDataByYear function.
			viewDatabyYear(data, records);
			break;
		case 2: // If selection is 2, execute the viewDataByProvince function.
			viewDatabyProvince(data, records);
			break;
		case 3: // If selection is 3, execute the viewDataByTaxon function.
			viewDatabyTaxon(data, records);
			break;
		case 4: // If selection is 4, execute the viewDataByProvinceAndTaxon function.
			viewDatabyProvinceAndTaxon(data, records);
			break;
		}
	} while (selection); // Looping Condition: Until selection is not zero, continue looping.
}

//MENU OPTION 1: View Data by Year: Takes Input of the data imported from the file and the maximum records. Prints the data in ascending order of years.
void viewDatabyYear(struct FileData data[], int max)
{
	int count = 0, i = 0;
	struct COSEWICDataByStatus InfoYear[10] = { 0 };
	struct statusTotalData totalForYear = { 0 };

	for (count = 2010; count < 2020; count++)
	{
		for (i = 0; i < max; i++)
		{
			if (data[i].year == count)
			{
				InfoYear[count - 2010].year = count;
				totalSpeciesByStatus(data, InfoYear, count - 2010, i);
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		InfoYear[i].total = InfoYear[i].extinct + InfoYear[i].extirpated + InfoYear[i].endangered + InfoYear[i].threatened + InfoYear[i].concern;
	}

	printf("YEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
	printf("---- ------- ---------- ---------- ---------- ------- ---------\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d    %d       %d       %d       %d    %d     %d\n", InfoYear[i].year, InfoYear[i].extinct, InfoYear[i].extirpated, InfoYear[i].endangered, InfoYear[i].threatened, InfoYear[i].concern, InfoYear[i].total);
	}
	printf("     ------- ---------- ---------- ---------- ------- ---------\n     ");
	calculateTotalData(totalForYear, InfoYear, i);
	
}

//MENU OPTION 2: View Data by Province: Takes Input of the data imported from the file and the maximum records. Prints the data sorted in descending order of the total count in each province.
void viewDatabyProvince(struct FileData data[], int max)
{
	int i = 0, j = 0, swap = 0;
	int sortTotal[13] = { 0 }; // An array declared to store the total count for sorting

	struct COSEWICDataByStatus provinceData[13] = { 0 };  // Creating an object of structure COSEWICDataByStatus and initialising it to zero.
	struct statusTotalData provinceTotal = { 0 };         // Creating an object of structure statusTotalData and initialising it to zero.

	for (i = 0; i < max; i++)
	{
		calculateDataByProvinceName(data, provinceData, i);  // Function call for calculating total count of all species for each province.
	}

	for (i = 0; i < 13; i++)
	{
		provinceData[i].total = provinceData[i].extinct + provinceData[i].extirpated + provinceData[i].endangered + provinceData[i].threatened + provinceData[i].concern; // Calculate the total count of animals of each species and store it in the total variable.
		sortTotal[i] = provinceData[i].total; // Store the total calculated in the sortTotal array for sorting
	}

	for (i = 12; i >= 0; i--) // Loop 1 decrementing from 12 to 0
	{
		for (j = 12; j >= 0; j--) // Loop 2 decrementing from 12 to 0
		{
			if (sortTotal[i] < sortTotal[j]) // If Condition: If the value of the sortTotal[i] is less than any other value in the array: swap the two variables. Runs 12 times to compare each value with the other.
			{
				// If Condition is true: If block entered
				swap = sortTotal[i]; // Set swap equal to the sortTotal[i]
				sortTotal[i] = sortTotal[j]; // Set sortTotal[i] equal to sortTotal[j]
				sortTotal[j] = swap; // Re-assign the swap to the sortTotal[j] number
				// Numbers swapped successfully
			}
		}
	}
	//Array is sorted
	
	// Header print statements
	printf("PROVINCE             EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
	printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
	for (i = 0; i < 13; i++) // Loop 1 incrementing from 0 to 12
	{
		for (int j = 0; j < 13; j++) // Loop 1 incrementing from 0 to 12
		{
			if (sortTotal[i] == provinceData[j].total) // If the value of the sortTotal[i] is equal to the value in the provinceData array: Execute the print statement.
			{
				printf("%s %7d %10d %10d %10d %7d %9d\n", provinceData[j].province_name, provinceData[j].extinct, provinceData[j].extirpated, provinceData[j].endangered, provinceData[j].threatened, provinceData[j].concern, provinceData[j].total); // Prints the required fields properly aligned with all the spacings.
			}
		}
	}

	printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n                     ");
	calculateTotalData(provinceTotal, provinceData, i);// Function Call: Calculates the total count of animals of all provinces having one particular status for all the status types.
}

//MENU OPTION 3: View Data by Taxon : Takes Input of the data imported from the file and the maximum records. Prints the data sorted in ascending order of the total count of each taxon.
void viewDatabyTaxon(struct FileData data[], int max)
{
	int i = 0, j = 0, swap = 0;
	int sortTotal[10];// An array declared to store the total count for sorting

	struct COSEWICDataByStatus TaxonData[10] = { 0 };// Creating an object of structure COSEWICDataByStatus and initialising it to zero.         
	struct statusTotalData TaxonTotal = { 0 };// Creating an object of structure statusTotalData and initialising it to zero.


	printf("TAXON           EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");//printing this as per required format.
	printf("--------------- ------- ---------- ---------- ---------- ------- ---------\n");//printing this as per required format.
	for (i = 0; i < max; i++)// Loop 1 incrementing from 0 to 6499
	{
		calculateDataByTaxonName(data, TaxonData, i);// Function call for calculating total count of all species for each taxon.
	}
	for (i = 0; i < 10; i++)// Loop 1 incrementing from 0 to 9
	{
		TaxonData[i].total = TaxonData[i].extinct + TaxonData[i].extirpated + TaxonData[i].endangered + TaxonData[i].threatened + TaxonData[i].concern;
		sortTotal[i] = TaxonData[i].total;
	}

	for (i = 0; i < 10; i++)// Loop 1 incrementing from 0 to 9
	{
		sortTotal[i] = TaxonData[i].total;
	}
	for (i = 0; i < 10; i++)// Loop 1 incrementing from 0 to 9
	{
		for (j = 0; j < 10; j++)// Loop 2 incrementing from 0 to 9
		{
			if (sortTotal[i] < sortTotal[j])//checking condition if we need to swap or not
			{
				swap = sortTotal[i];//swap is a temporary variable used to store sortTotal[i]
				sortTotal[i] = sortTotal[j];//here we change values of sortTotal[i] and sortTotal[j]
				sortTotal[j] = swap;//putting value in sortTotal[j]
			}
		}

	}
	for (i = 0; i < 10; i++)// Loop 1 incrementing from 0 to 9
	{
		for (j = 0; j < 10; j++)// Loop 2 incrementing from 0 to 9
		{
			if (sortTotal[i] == TaxonData[j].total)// conditions check if both values are equal or not
			{
				printf("%s %7d %10d %10d %10d %7d %9d\n", TaxonData[j].taxon_name, TaxonData[j].extinct, TaxonData[j].extirpated, TaxonData[j].endangered, TaxonData[j].threatened, TaxonData[j].concern, TaxonData[j].total);
			}
		}
	}

	printf("                ------- ---------- ---------- ---------- ------- ---------\n                ");
	calculateTotalData(TaxonTotal, TaxonData, i); //Function Call : Calculates the total count of animals of all taxons having one particular status for all the status types.
}

//MENU OPTION 4: View Data by Taxon : Takes Input of the data imported from the file and the maximum records. Prompts user to enter their choice of province and taxon. Prints the data as demanded by the user.
void viewDatabyProvinceAndTaxon(struct FileData data[], int max)
{
	int province_selection = 0; // Variable to store user's choice of province
	int taxonselection = 0; // Variable to store user's choice of taxon

	char abbreivated_province_name[PROVINCE_LENGTH + 1] = { {'\0'} }; // As per the users choice we will store short form of province name
	char province_full_name[NAME_LENGTH + 1] = { '\0' }; // As per the users choice we will store full name of the province 
	char taxon_name[NAME_LENGTH + 1] = { '\0' }; // As per the user's choice we will store taxon name

	struct COSEWICDataByStatus ProvinceAndTaxonData[1] = { 0 };

	do
	{
		provinceMenu();// List of provinces to choose from
		province_selection = inputIntRange(1, 13);// Calling function which will take user's choice
		putchar('\n');
	} while (province_selection == 0);

	switch (province_selection)//SWITCH statement: Executes statements according to the choice made by the user
	{
		// strcpy(abbreivated_province_name, ".."): copies the passed string to the abbreivated_province_name variable for further use
		// strcpy(province_full_name, "......"): copies the passed string to the province_full_name variable for further use
	case 1:
		strcpy(abbreivated_province_name, "AB");
		strcpy(province_full_name, "Alberta");
		break;
	case 2:
		strcpy(abbreivated_province_name, "BC");
		strcpy(province_full_name, "British Columbia");
		break;
	case 3:
		strcpy(abbreivated_province_name, "MB");
		strcpy(province_full_name, "Manitoba");
		break;
	case 4:
		strcpy(abbreivated_province_name, "NB");
		strcpy(province_full_name, "New Brunswick");
		break;
	case 5:
		strcpy(abbreivated_province_name, "NL");
		strcpy(province_full_name, "Newfoundland");
		break;
	case 6:
		strcpy(abbreivated_province_name, "NS");
		strcpy(province_full_name, "Nova Scotia");
		break;
	case 7:
		strcpy(abbreivated_province_name, "NT");
		strcpy(province_full_name, "Northwest Territory");
		break;
	case 8:
		strcpy(abbreivated_province_name, "NU");
		strcpy(province_full_name, "Nunavut");
		break;
	case 9:
		strcpy(abbreivated_province_name, "ON");
		strcpy(province_full_name, "Ontario");
		break;
	case 10:
		strcpy(abbreivated_province_name, "PE");
		strcpy(province_full_name, "Prince Edward Island");
		break;
	case 11:
		strcpy(abbreivated_province_name, "QC");
		strcpy(province_full_name, "Quebec");
		break;
	case 12:
		strcpy(abbreivated_province_name, "SK");
		strcpy(province_full_name, "Saskatchewan");
		break;
	case 13:
		strcpy(abbreivated_province_name, "YT");
		strcpy(province_full_name, "Yukon Territory");
		break;
	}

	do
	{
		TaxonMenu();// Giving users Taxon names to choose from
		taxonselection = inputIntRange(1, 10);// Calling function which will take users choice and validates if the value is in the specified range
		putchar('\n');
	} while (taxonselection == 0);

	switch (taxonselection) // Storing values as per users earlier made selection
	{
		// strcpy(taxon_name, "......"): copies the passed string to the taxon_name variable for further use
	case 1:
		strcpy(taxon_name, "Mammals");
		break;
	case 2:
		strcpy(taxon_name, "Birds");
		break;
	case 3:
		strcpy(taxon_name, "Reptiles");
		break;
	case 4:
		strcpy(taxon_name, "Amphibians");
		break;
	case 5:
		strcpy(taxon_name, "Fishes");
		break;
	case 6:
		strcpy(taxon_name, "Arthropods");
		break;
	case 7:
		strcpy(taxon_name, "Molluscs");
		break;
	case 8:
		strcpy(taxon_name, "Vascular Plants");
		break;
	case 9:
		strcpy(taxon_name, "Mosses");
		break;
	case 10:
		strcpy(taxon_name, "Lichens");
		break;
	}

	for (int i = 0; i < max; i++)// Loop 1 incrementing from 0(inclusive) to 'max'(exclusive)
	{
		if ((strcmp(data[i].province, abbreivated_province_name) == 0) && (strcmp(data[i].taxon, taxon_name) == 0)) //checking and comparing data and calling functions accordingly
		{
			totalSpeciesByStatus(data, ProvinceAndTaxonData, 0, i);// Function Call: calculate total count of species based on status
		}
	}

	ProvinceAndTaxonData[0].total = ProvinceAndTaxonData[0].extinct + ProvinceAndTaxonData[0].extirpated + ProvinceAndTaxonData[0].endangered + ProvinceAndTaxonData[0].threatened + ProvinceAndTaxonData[0].concern; // Calculate the total of all animals in all species

	//Header print statements
	printf("*** Data filtered by PROVINCE and TAXON ***\n\n");
	printf("    Province: %s\n", province_full_name);
	printf("    Taxon   : %s\n\n", taxon_name);
	printf("EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n");
	printf("------- ---------- ---------- ---------- ------- ---------\n");

	printf("    %d        %d        %d        %d     %d      %d\n\n", ProvinceAndTaxonData[0].extinct, ProvinceAndTaxonData[0].extirpated, ProvinceAndTaxonData[0].endangered, ProvinceAndTaxonData[0].threatened, ProvinceAndTaxonData[0].concern, ProvinceAndTaxonData[0].total); //Final print statement to print the calcuated data

}



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         UTILITY FUNCTIONS
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//1. Checks the value entered is within the range inputted.
int inputIntRange(int lower_limit, int upper_limit)
{
	int value = 0, flag = 0, scanf_return = 0;
	char after_character = 0;
	do
	{
		scanf_return = scanf(" %d%c", &value, &after_character);

		if (scanf_return == 0 || after_character != '\n')
		{
			printf("\nInvalid menu selection!\n\n");
			menu();
			clearInputBuffer();
		}
		else
		{
			if (value < lower_limit || value > upper_limit)
			{
				printf("\nInvalid menu selection!\n\n");
				if (upper_limit == 4)
				{
					menu();
				}
				if (upper_limit == 13)
				{
					provinceMenu();
				}
				if (upper_limit == 10)
				{
					TaxonMenu();
				}
			}
			else
			{
				flag = 1;
			}
		}
	} while (flag == 0);

	return value;
}

//2. Calculates the total species by status for different provinces, different taxons, and different years.
void totalSpeciesByStatus(struct FileData data[], struct COSEWICDataByStatus datacount[], int number, int count)
{
	// Compares the string at that index with EXTINCT, if strcmp returns zero, if block is entered
	if (strcmp(data[count].status, "EXTINCT") == 0) 
	{
		datacount[number].extinct += data[count].count; // Adds the count of species at that index to the array in the extinct variable 
	}
	// Compares the string at that index with EXTIRPATED, if strcmp returns zero, else if block is entered
	else if (strcmp(data[count].status, "EXTIRPATED") == 0)
	{
		datacount[number].extirpated += data[count].count; // Adds the count of species at that index to the array in the extirpated variable
	}
	// Compares the string at that index with ENDANGERED, if strcmp returns zero, else if block is entered
	else if (strcmp(data[count].status, "ENDANGERED") == 0)
	{
		datacount[number].endangered += data[count].count; // Adds the count of species at that index to the array in the endangered variable
	}
	// Compares the string at that index with THREATENED, if strcmp returns zero, else if block is entered
	else if (strcmp(data[count].status, "THREATENED") == 0)
	{
		datacount[number].threatened += data[count].count; // Adds the count of species at that index to the array in the threatened variable
	}
	// Compares the string at that index with SPECIAL CONCERN, if strcmp returns zero, else if block is entered
	else if (strcmp(data[count].status, "SPECIAL CONCERN") == 0)
	{
		datacount[number].concern += data[count].count; // Adds the count of species at that index to the array in the concern variable
	}
}

//3. Calculates the total count as in the status of each species for each province.
void calculateDataByProvinceName(struct FileData data[], struct COSEWICDataByStatus info[], int i)
{
	int province_num;

	// Compares the string at that index with ON, if strcmp returns zero, if block is entered
	if (strcmp(data[i].province, "ON") == 0)
	{
		province_num = 0; // Set province_num to 0.
		strcpy(info[province_num].province_name, "Ontario             "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with MB, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "MB") == 0)
	{
		province_num = 1; // Set province_num to 1.
		strcpy(info[province_num].province_name, "Manitoba            "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with NU, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "NU") == 0)
	{
		province_num = 2; // Set province_num to 2.
		strcpy(info[province_num].province_name, "Nunavut             "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with NL, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "NL") == 0)
	{
		province_num = 3; // Set province_num to 3.
		strcpy(info[province_num].province_name, "Newfoundland        "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with SK, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "SK") == 0)
	{
		province_num = 4; // Set province_num to 4.
		strcpy(info[province_num].province_name, "Saskatchewan        "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with NT, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "NT") == 0)
	{
		province_num = 5; // Set province_num to 5.
		strcpy(info[province_num].province_name, "Northwest Territory "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with NB, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "NB") == 0)
	{
		province_num = 6; // Set province_num to 6.
		strcpy(info[province_num].province_name, "New Brunswick       "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with QC, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "QC") == 0)
	{
		province_num = 7; // Set province_num to 7.
		strcpy(info[province_num].province_name, "Quebec              "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with BC, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "BC") == 0)
	{
		province_num = 8; // Set province_num to 8.
		strcpy(info[province_num].province_name, "British Columbia    "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with YT, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "YT") == 0)
	{
		province_num = 9; // Set province_num to 9.
		strcpy(info[province_num].province_name, "Yukon Territory     "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with NS, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "NS") == 0)
	{
		province_num = 10; // Set province_num to 10.
		strcpy(info[province_num].province_name, "Nova Scotia         "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with AB, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "AB") == 0)
	{
		province_num = 11; // Set province_num to 11.
		strcpy(info[province_num].province_name, "Alberta             "); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with PE, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].province, "PE") == 0)
	{
		province_num = 12; // Set province_num to 12.
		strcpy(info[province_num].province_name, "Prince Edward Island"); // Copy the passed string in the province_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, province_num, i); // Function Call: Calculate the total species at that index according to their status
	}

}

//4.Calculates the total count as in the status of each species for each taxon.
void calculateDataByTaxonName(struct FileData data[], struct COSEWICDataByStatus info[], int i)
{
	int taxonNumber;

	// Compares the string at that index with Amphibians, if strcmp returns zero, if block is entered
	if (strcmp(data[i].taxon, "Amphibians") == 0)
	{
		taxonNumber = 0; // Set taxonNumber to 0.
		strcpy(info[taxonNumber].taxon_name, "Amphibians     "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Arthropods, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Arthropods") == 0)
	{
		taxonNumber = 1; // Set taxonNumber to 1.
		strcpy(info[taxonNumber].taxon_name, "Arthropods     "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Birds, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Birds") == 0)
	{
		taxonNumber = 2; // Set taxonNumber to 2.
		strcpy(info[taxonNumber].taxon_name, "Birds          "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Fishes, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Fishes") == 0)
	{
		taxonNumber = 3; // Set taxonNumber to 3.
		strcpy(info[taxonNumber].taxon_name, "Fishes         "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Lichens, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Lichens") == 0)
	{
		taxonNumber = 4; // Set taxonNumber to 4. 
		strcpy(info[taxonNumber].taxon_name, "Lichens        "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Mammals, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Mammals") == 0)
	{
		taxonNumber = 5; // Set taxonNumber to 5.
		strcpy(info[taxonNumber].taxon_name, "Mammals        "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Molluscs, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Molluscs") == 0)
	{
		taxonNumber = 6; // Set taxonNumber to 6.
		strcpy(info[taxonNumber].taxon_name, "Molluscs       "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Mosses, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Mosses") == 0)
	{
		taxonNumber = 7; // Set taxonNumber to 7.
		strcpy(info[taxonNumber].taxon_name, "Mosses         "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Reptiles, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Reptiles") == 0)
	{
		taxonNumber = 8; // Set taxonNumber to 8.
		strcpy(info[taxonNumber].taxon_name, "Reptiles       "); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}
	// Compares the string at that index with Vascular Plants, if strcmp returns zero, if block is entered
	else if (strcmp(data[i].taxon, "Vascular Plants") == 0)
	{
		taxonNumber = 9; // Set taxonNumber to 9.
		strcpy(info[taxonNumber].taxon_name, "Vascular Plants"); // Copy the passed string in the taxon_name variable of the info (structure) array
		totalSpeciesByStatus(data, info, taxonNumber, i); // Function Call: Calculate the total species at that index according to their status
	}

}

//5. Calculates the total extinct, endangered, extirpated, threatened, and species of special concern and also the total count for all species.
void calculateTotalData(struct statusTotalData grandTotal, struct COSEWICDataByStatus data[], int max)
{
	int i = 0;
	for (i = 0; i < max; i++) // Loop that runs 'max' number of times
	{
		// Add the value of the count of species with a particular status to the respective variable in the grandTotal object.
		grandTotal.concern += data[i].concern;
		grandTotal.endangered += data[i].endangered;
		grandTotal.extinct += data[i].extinct;
		grandTotal.extirpated += data[i].extirpated;
		grandTotal.threatened += data[i].threatened;
		grandTotal.total += data[i].total;
	}
	//Print the total count with the formatting
	printf("%7d %10d %10d %10d %7d %9d\n\n", grandTotal.extinct, grandTotal.extirpated, grandTotal.endangered, grandTotal.threatened, grandTotal.concern, grandTotal.total);
}


//////////////////////////////////////
//          FILE FUNCTION
//////////////////////////////////////
int loadData(const char* datafile, struct FileData data[], int max)
{
	FILE* fp = NULL;
	int count = 0, flag = 0, scanf_return = 0;
	fp = fopen(datafile, "r"); // Opens file in read mode
	char firstline[100]; // Character string to set the output of the fscanf for discarding the first line

	if (fp != NULL)
	{
		scanf_return = fscanf(fp, "%[^\n]", firstline);  // Read and discard the first line
		do
		{
			scanf_return = fscanf(fp, "%d,%[^,],%[^,],%d,%[^\n]", &data[count].year, data[count].taxon, data[count].status, &data[count].count, data[count].province); // Get the file, read the line until end is reached and store them at the variables assigned.
			count++; // Increment count by 1
			if (count == max) // If condition: If count equals max, execute the if statement
			{
				flag = 1; // Set flag to 1 for terminating the loop
			}
		} while (scanf_return > 0 && flag == 0); // Looping Condition: Until scanf_return is greater than zero AND flag is equal to 0.
		fclose(fp); // Close the file
	}
	return count; // Return the count variable: representing the number of data records read. 
}
