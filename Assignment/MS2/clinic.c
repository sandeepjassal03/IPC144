/*
*****************************************************************************
						Assignment 1 - Milestone 2
Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh124@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
	printf("Pat.# Name            Phone#\n"
		"----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
	if (fmt == FMT_FORM)
	{
		printf("Name  : %s\n"
			"Number: %05d\n"
			"Phone : ", patient->name, patient->patientNumber);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
	else
	{
		printf("%05d %-15s ", patient->patientNumber,
			patient->name);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
	int selection;

	do {
		printf("Veterinary Clinic System\n"
			"=========================\n"
			"1) PATIENT     Management\n"
			"2) APPOINTMENT Management\n"
			"-------------------------\n"
			"0) Exit System\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');
		switch (selection)
		{
		case 0:
			printf("Are you sure you want to exit? (y|n): ");
			selection = !(inputCharOption("yn") == 'y');
			putchar('\n');
			if (!selection)
			{
				printf("Exiting system... Goodbye.\n\n");
			}
			break;
		case 1:
			menuPatient(data->patients, data->maxPatient);
			break;
		case 2:
			printf("<<< Feature not yet available >>>\n\n");
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
	int selection;

	do {
		printf("Patient Management\n"
			"=========================\n"
			"1) VIEW   Patient Data\n"
			"2) SEARCH Patients\n"
			"3) ADD    Patient\n"
			"4) EDIT   Patient\n"
			"5) REMOVE Patient\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 5);
		putchar('\n');
		switch (selection)
		{
		case 1:
			displayAllPatients(patient, max, FMT_TABLE);
			suspend();
			break;
		case 2:
			searchPatientData(patient, max);
			break;
		case 3:
			addPatient(patient, max);
			suspend();
			break;
		case 4:
			editPatient(patient, max);
			break;
		case 5:
			removePatient(patient, max);
			suspend();
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
	int selection;

	do {
		printf("Edit Patient (%05d)\n"
			"=========================\n"
			"1) NAME : %s\n"
			"2) PHONE: ", patient->patientNumber, patient->name);

		displayFormattedPhone(patient->phone.number);

		printf("\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');

		if (selection == 1)
		{
			printf("Name  : ");
			inputCString(patient->name, 1, NAME_LEN);
			putchar('\n');
			printf("Patient record updated!\n\n");
		}
		else if (selection == 2)
		{
			inputPhoneData(&patient->phone);
			printf("Patient record updated!\n\n");
		}

	} while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
	int count, records_found = 0;

	displayPatientTableHeader();

	for (count = 0; count < max; count++)
	{
		// if there is no data at that index, it should not be displayed
		if (patient[count].patientNumber != 0)
		{
			//record found and displayed
			displayPatientData(&patient[count], fmt);
			records_found = 1;
		}
	}
	putchar('\n');

	if (records_found == 0)
	{
		printf("*** No records found ***\n");
		putchar('\n');
	}

}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
	int selection = 0;

	do
	{
		printf("Search Options\n");
		printf("==========================\n");
		printf("1) By patient number\n");
		printf("2) By phone number\n");
		printf("..........................\n");
		printf("0) Previous menu\n");
		printf("..........................\n");
		printf("Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');

		if (selection == 1)
		{
			searchPatientByPatientNumber(patient, max);
			suspend();
		}
		else if (selection == 2)
		{
			searchPatientByPhoneNumber(patient, max);
		}
	} while (selection != 0);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
	int count = 0, new_patient_index = 0, new_space = 0, next_number = 0;

	for (count = 0; count < max && new_space == 0; count++)
	{
		if (patient[count].patientNumber == 0)
		{
			new_patient_index = count;
			new_space = 1;
		}
	}
	if (new_space == 0)
	{
		printf("ERROR: Patient listing is FULL!\n");
	}
	else
	{
		next_number = nextPatientNumber(patient, max);
		patient[new_patient_index].patientNumber = next_number;

		inputPatient(&patient[new_patient_index]);
		printf("*** New patient record added ***\n");
	}
	putchar('\n');
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
	int patient_num, patient_index;
	printf("Enter the patient number: ");
	patient_num = inputIntPositive();
	putchar('\n');

	patient_index = findPatientIndexByPatientNum(patient_num, patient, max);
	if (patient_index == -1)
	{
		printf("ERROR: Patient record not found!");
	}
	else
	{
		menuPatientEdit(&patient[patient_index]);
	}
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
	int choice, patient_number, patient_index = 0;

	printf("Enter the patient number: ");
	patient_number = inputIntPositive();
	putchar('\n');

	patient_index = findPatientIndexByPatientNum(patient_number, patient, max);
	if (patient_index == -1)
	{
		printf("ERROR: Patient record not found!\n");
		putchar('\n');
	}
	else
	{
		displayPatientData(&patient[patient_index], FMT_FORM);

		printf("\nAre you sure you want to remove this patient record? (y/n): ");
		choice = inputCharOption("yn");
		if (choice == 'y')
		{
			patient[patient_index].patientNumber = 0;
			patient[patient_index].name[NAME_LEN] = '\0';
			patient[patient_index].phone.description[PHONE_DESC_LEN+1] = '\0';
			patient[patient_index].phone.number[PHONE_LEN + 1] = '\0';

			printf("Patient record has been removed!\n");
			putchar('\n');
		}
		else
		{
			printf("Operation aborted.\n");
			putchar('\n');
		}
	}
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
	int patient_number, patient_index;
	printf("Search by patient number: ");
	patient_number = inputIntPositive();
	putchar('\n');

	patient_index = findPatientIndexByPatientNum(patient_number, patient, max);

	if (patient_index == -1)
	{
		printf("*** No records found ***\n");
		putchar('\n');
	}
	else
	{
		displayPatientData(&patient[patient_index], FMT_FORM);
		putchar('\n');
	}
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
	char patient_phone_number[PHONE_LEN + 1] = { '\0' };
	int count = 0, found = 0;

	printf("Search by phone number: ");
	inputCString(patient_phone_number, PHONE_LEN, PHONE_LEN);
	putchar('\n');
	displayPatientTableHeader();

	for (count = 0; count < max; count++)
	{
		if (strcmp(patient_phone_number, patient[count].phone.number) == 0)
		{
			displayPatientData(&patient[count], FMT_TABLE);
			found = 1;
		}
	}
	printf("\n");
	if (!found)
	{
		printf("*** No records found ***\n\n");
	}
	clearInputBuffer();
	suspend();
	
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
	int count = 0, largest_patient_num = 0;

	for (count = 0; count < max; count++)
	{
		if (patient[count].patientNumber > largest_patient_num)
		{
			largest_patient_num = patient[count].patientNumber;
		}
	}
	largest_patient_num++;
	return largest_patient_num;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
	int count = 0, record_found = 0;

	do
	{
		if (patientNumber == patient[count].patientNumber)
		{
			record_found = 1;
		}
		count++;
	} while (count < max && record_found == 0);

	if (!record_found)
	{
		count = -1;
	}
	else
	{
		count--;
	}

	return count;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
	printf("Patient Data Input\n");
	printf("------------------\n");
	printf("Number: 0%d\n", patient->patientNumber);
	printf("Name  : ");
	inputCString(patient->name, 1, NAME_LEN);
	putchar('\n');
	inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
	int patient_contact_option;

	printf("Phone Information\n");
	printf("-----------------\n");
	printf("How will the patient like to be contacted?\n");
	printf("1. Cell\n");
	printf("2. Home\n");
	printf("3. Work\n");
	printf("4. TBD\n");
	printf("Selection: ");

	patient_contact_option = inputIntRange(1, 4);
	putchar('\n');
	switch (patient_contact_option)
	{
	case 1:
		printf("Contact:");
		strcpy((*phone).description, "CELL");
		printf(" %s\n", (*phone).description);
		printf("Number : ");
		inputCString((*phone).number, PHONE_LEN, PHONE_LEN);
		putchar('\n');
		clearInputBuffer();
		break;
	case 2:
		printf("Contact:");
		strcpy((*phone).description, "HOME");
		printf(" %s\n", (*phone).description);
		printf("Number : ");
		inputCString((*phone).number, PHONE_LEN, PHONE_LEN);
		putchar('\n');
		clearInputBuffer();
		break;
	case 3:
		printf("Contact:");
		strcpy((*phone).description, "WORK");
		printf(" %s\n", (*phone).description);
		printf("Number : ");
		inputCString((*phone).number, PHONE_LEN, PHONE_LEN);
		putchar('\n');
		clearInputBuffer();
		break;
	case 4:
		strcpy((*phone).description, "TBD");
		break;
	}
}