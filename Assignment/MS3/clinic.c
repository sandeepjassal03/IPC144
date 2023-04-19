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
#include<string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

// Macro Definitions
#define START_HOURS 10
#define END_HOURS 14
#define INTERVAL_2 30

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
int FLAG = 1;

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
	printf("Clinic Appointments for the Date: ");

	if (isAllRecords)
	{
		printf("<ALL>\n\n");
		printf("Date       Time  Pat.# Name            Phone#\n"
			"---------- ----- ----- --------------- --------------------\n");
	}
	else
	{
		printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
		printf("Time  Pat.# Name            Phone#\n"
			"----- ----- --------------- --------------------\n");
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
	const struct Appointment* appoint,
	int includeDateField)
{
	if (includeDateField)
	{
		printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
			appoint->date.day);
	}
	printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
		patient->patientNumber, patient->name);

	displayFormattedPhone(patient->phone.number);

	printf(" (%s)\n", patient->phone.description);
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
			menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
	int selection;

	do {
		printf("Appointment Management\n"
			"==============================\n"
			"1) VIEW   ALL Appointments\n"
			"2) VIEW   Appointments by DATE\n"
			"3) ADD    Appointment\n"
			"4) REMOVE Appointment\n"
			"------------------------------\n"
			"0) Previous menu\n"
			"------------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 1:
			viewAllAppointments(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 2:
			viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 3:
			addAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 4:
			removeAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		}
	} while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
			patient[patient_index].name[NAME_LEN - 1] = '\0';
			patient[patient_index].phone.description[PHONE_DESC_LEN] = '\0';
			patient[patient_index].phone.number[PHONE_LEN] = '\0';

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



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
	int patientIndex = 0, count = 0;

	displayScheduleTableHeader(&data->appointments->date, 1);
	for (count = 0; count < data->maxAppointments; count++)
	{
		if (data->appointments[count].patientNumber != 0)
		{
			patientIndex = findPatientIndexByPatientNum(data->appointments[count].patientNumber, data->patients, data->maxPatient);
			displayScheduleData(&data->patients[patientIndex], &data->appointments[count], 1);
		}
	}
	putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
	int input_year, input_month, input_day;
	int count = 0, patientIndex = 0, flag = 0;

	printf("Year        : ");
	input_year = inputIntPositive();
	if (input_year % 4 == 0)
	{
		printf("Month (1-12): ");
		input_month = inputIntRange(1, 12);
		printf("Day (1-29)  : ");
		input_day = inputIntRange(1, 29);
	}
	else
	{
		printf("Month (1-12): ");
		input_month = inputIntRange(1, 12);
		printf("Day (1-28)  : ");
		input_day = inputIntRange(1, 28);
	}

	putchar('\n');
	for (count = 0; count < data->maxAppointments && flag == 0; count++)
	{
		if (data->appointments[count].patientNumber != 0 && input_year == data->appointments[count].date.year && input_month == data->appointments[count].date.month && input_day == data->appointments[count].date.day)
		{
			patientIndex = findPatientIndexByPatientNum(data->appointments[count].patientNumber, data->patients, data->maxPatient);
			displayScheduleTableHeader(&data->appointments[count].date, 0);
			flag = 1;
		}
	}

	for (count = 0; count < data->maxAppointments; count++)
	{
		if (data->appointments[count].patientNumber != 0 && input_year == data->appointments[count].date.year && input_month == data->appointments[count].date.month && input_day == data->appointments[count].date.day)
		{
			patientIndex = findPatientIndexByPatientNum(data->appointments[count].patientNumber, data->patients, data->maxPatient);
			displayScheduleData(&data->patients[patientIndex], &data->appointments[count], 0);
		}
	}

	putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:20
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatients)
{
	int count = 0, patient_number = 0, patient_index =0;
	int flag = 0, slotNotAvailable = 0, appointment_added = 0;

	int input_year, input_month, input_day;
	int input_hour, input_minute;


	for (patient_index = 0; patient_index < maxAppointments && appointments[patient_index].patientNumber > 1 && flag == 0; patient_index++)
	{
		if (appointments[patient_index].patientNumber <1)
		{
			flag = 1;
		}
	}

	if (appointments[patient_index].patientNumber < 1 && patient_index < maxAppointments)
	{
		do
		{
			slotNotAvailable = 0;
			if (patient_number == 0)
			{
				printf("Patient Number: ");
				patient_number = inputIntPositive();
				appointments[patient_index].patientNumber = patient_number;
			}


			inputAppointmentDate(&input_year, &input_month, &input_day);
			inputAppointmentTime(&input_hour, &input_minute);
			putchar('\n');
			flag = 0;
			for (count = 0; count < maxAppointments && flag == 0; count++)
			{
				if (appointments[count].date.year == input_year && appointments[count].date.month == input_month && appointments[count].date.day == input_day && appointments[count].time.hour == input_hour && appointments[count].time.min == input_minute)
				{
					slotNotAvailable = 1;
					flag = 1;
					printf("ERROR: Appointment timeslot is not available!\n\n");
				}
			}
			count = patient_index;
			if (slotNotAvailable == 0)
			{
				appointments[count].date.year = input_year;
				appointments[count].date.month = input_month;
				appointments[count].date.day = input_day;
				appointments[count].time.hour = input_hour;
				appointments[count].time.min = input_minute;
				printf("*** Appointment scheduled! ***\n\n");
				appointment_added = 1;
				sortAppointmentData(appointments, maxAppointments);
			}
		} while (appointment_added == 0);
	}
}




// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatients)
{
	int patient_number = 0, count = 0, flag = 0, return_value;
	int year_of_appointment, month_of_appointment, day_of_appointment;
	char user_choice;

	printf("Patient Number: ");
	patient_number = inputIntPositive();
	return_value = findPatientIndexByPatientNum(patient_number, patients, maxPatients);

	if (return_value == -1)
	{
		printf("ERROR: Patient record not found!\n\n");
	}
	else
	{
		inputAppointmentDate(&year_of_appointment, &month_of_appointment, &day_of_appointment);
		putchar('\n');
		for (count = 0; count < maxAppointments && flag == 0; count++)
		{
			if (appointments[count].patientNumber == patient_number && appointments[count].date.year == year_of_appointment && appointments[count].date.month == month_of_appointment && appointments[count].date.day == day_of_appointment)
			{
				
				flag = 1;
			}
		}
		count--;

		displayPatientData(&patients[return_value], FMT_FORM);
		printf("Are you sure you want to remove this appointment (y,n): ");
		user_choice = inputCharOption("yn");
		if (user_choice == 'y')
		{
			appointments[count].patientNumber = 0;
			appointments[count].date.year = 0;
			appointments[count].date.month = 0;
			appointments[count].date.day = 0;
			appointments[count].time.hour = 0;
			appointments[count].time.min = 0;
			printf("\nAppointment record has been removed!\n\n");
			sortAppointmentData(appointments, maxAppointments);
		}
		else
		{
			printf("Operation Aborted.\n\n");
		}
	}
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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


// Gets the user input for the date and validates it
void inputAppointmentDate(int* inputYear, int* inputMonth, int* inputDay)
{
	int year, month, day;
	printf("Year        : ");
	year = inputIntPositive();
	printf("Month (1-12): ");
	month = inputIntRange(1, 12);

	if (month == 2)
	{
		if (year % 4 == 0)
		{
			printf("Day (1-29)  : ");
			day = inputIntRange(1, 29);
		}
		else
		{
			printf("Day (1-28)  : ");
			day = inputIntRange(1, 28);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		printf("Day (1-30)  : ");
		day = inputIntRange(1, 30);
	}
	else
	{
		printf("Day (1-31)  : ");
		day = inputIntRange(1, 31);
	}

	*inputYear = year;
	*inputMonth = month;
	*inputDay = day;
}

// Gets the user input for the appointment time and validates it
void inputAppointmentTime(int* inputHour, int* inputMinute)
{
	int hour, minutes;
	int flag = 0, hours_error_found = 0, minutes_error_found = 0;
	do
	{
		printf("Hour (0-23)  : ");
		hour = inputIntRange(0, 23);

		if (hour < START_HOURS || hour > END_HOURS)
		{
			hours_error_found = 1;
		}
		else
		{
			hours_error_found = 0;
		}
		printf("Minute (0-59): ");
		minutes = inputIntRange(0, 59);

		if (hour == END_HOURS && minutes > 0)
		{
			minutes_error_found = 1;
		}
		else if (minutes % INTERVAL_2 != 0)
		{
			minutes_error_found = 1;
		}
		else
		{
			minutes_error_found = 0;
		}

		if (hours_error_found == 0 && minutes_error_found == 0)
		{
			flag = 1;
		}
		else
		{
			printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOURS, END_HOURS, INTERVAL_2);
		}
	} while (flag == 0);

	*inputHour = hour;
	*inputMinute = minutes;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)

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




//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
	FILE* fp = NULL;
	int count = 0, flag = 0, scanf_return = 0;
	fp = fopen(datafile, "r");

	if (fp != NULL)
	{
		do
		{
			scanf_return = fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[count].patientNumber, patients[count].name, patients[count].phone.description, patients[count].phone.number);
			count++;
			if (count == max)
			{
				flag = 1;
			}
		} while (scanf_return > 0 && flag == 0);
		fclose(fp);
	}
	return count;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
	FILE* fp = NULL;
	int count = 0, flag = 0;
	fp = fopen(datafile, "r");

	if (fp != NULL)
	{
		while (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[count].patientNumber, &appoints[count].date.year, &appoints[count].date.month, &appoints[count].date.day, &appoints[count].time.hour, &appoints[count].time.min) == 6 && flag == 0)
		{
			count++;
		}
		fclose(fp);
	}

	sortAppointmentData(appoints, max);

	return count;
}

// Generates the earliest appointment date
int findLowestAppointmentDate(const struct Appointment Appts[], int max)
{
	int patientIndex = 0, count = 0;
	int lowestYear = 9999;
	int lowestMonth = 12;
	int lowestDay = 31;
	int lowestHour = 24;
	int lowestMinute = 60;

	for (count = 0; count < max; count++)
	{
		if (Appts[count].patientNumber != 0 && Appts[count].date.year < lowestYear)
		{
			lowestYear = Appts[count].date.year;
		}
	}
	for (count = 0; count < max; count++)
	{
		if (Appts[count].patientNumber != 0 && Appts[count].date.year == lowestYear && Appts[count].date.month < lowestMonth)
		{
			lowestMonth = Appts[count].date.month;
		}
	}

	for (count = 0; count < max; count++)
	{
		if (Appts[count].patientNumber != 0 && Appts[count].date.year == lowestYear && Appts[count].date.month == lowestMonth && Appts[count].date.day < lowestDay)
		{
			lowestDay = Appts[count].date.day;
		}
	}
	for (count = 0; count < max; count++)
	{
		if (Appts[count].patientNumber != 0 && Appts[count].date.year == lowestYear && Appts[count].date.month == lowestMonth && Appts[count].date.day == lowestDay && Appts[count].time.hour < lowestHour)
		{
			lowestHour = Appts[count].time.hour;
		}
	}
	for (count = 0; count < max; count++)
	{
		if (Appts[count].patientNumber != 0 && Appts[count].date.year == lowestYear && Appts[count].date.month == lowestMonth && Appts[count].date.day == lowestDay && Appts[count].time.hour == lowestHour && Appts[count].time.min < lowestMinute)
		{
			lowestMinute = Appts[count].time.min;
			patientIndex = count;
		}
	}

	return patientIndex;
}

// Sorts the array based on the lowest date 
int sortAppointmentData(struct Appointment Appts[], int max)
{
	int count = 0, index = 0;
	struct Appointment sortedApptData[50] = { {0} };

	for (count = 0; count < max; count++)
	{
		// Add the data to sortedApptData

		index = findLowestAppointmentDate(Appts, max);

		sortedApptData[count].patientNumber = Appts[index].patientNumber;
		sortedApptData[count].date.year = Appts[index].date.year;
		sortedApptData[count].date.month = Appts[index].date.month;
		sortedApptData[count].date.day = Appts[index].date.day;
		sortedApptData[count].time.hour = Appts[index].time.hour;
		sortedApptData[count].time.min = Appts[index].time.min;

		//  Remove the data

		Appts[index].patientNumber = 0;
	}

	for (count = 0; count < max; count++)
	{
		// Re put the data at the correct place to get a sorted array
		Appts[count].patientNumber = sortedApptData[count].patientNumber;
		Appts[count].date.year = sortedApptData[count].date.year;
		Appts[count].date.month = sortedApptData[count].date.month;
		Appts[count].date.day = sortedApptData[count].date.day;
		Appts[count].time.hour = sortedApptData[count].time.hour;
		Appts[count].time.min = sortedApptData[count].time.min;
	}
	return 0;
}
