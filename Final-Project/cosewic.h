#pragma once
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

#ifndef COSEWIC_H
#define COSEWIC_H

//MACRO DEFINITIONS
#define PROVINCE_LENGTH 2
#define MAX_RECORDS 6500
#define NAME_LENGTH 20

// STRUCTURES

struct FileData 
{
	int year;
	char taxon[NAME_LENGTH + 1];
	char status[NAME_LENGTH + 1];
	int count;
	char province[PROVINCE_LENGTH + 1];
};

struct statusTotalData
{
	int extinct;
	int extirpated;
	int endangered;
	int threatened;
	int concern;
	int total;
};

struct COSEWICDataByStatus
{
	char province_name[NAME_LENGTH + 1];
	char taxon_name[NAME_LENGTH + 1];
	int year;
	int extinct;
	int extirpated;
	int endangered;
	int threatened;
	int concern;
	int total;
};

// FILE FUNCTIONS
int loadData(const char* datafile,  struct FileData data[], int max);

// SELECTION MENU FUNCTIONS 
void menu(void);
void provinceMenu(void);
void TaxonMenu(void);


// ENTRY POINT 
void mainLogic(struct FileData data[], int records);

// MENU SELECTION ENTRY FUNCTIONS

//1. MENU OPTION 1: View Data by Year: Takes Input of the data imported from the file and the maximum records. Prints the data in ascending order of years.
void viewDatabyYear(struct FileData data[], int max);

//2. MENU OPTION 2: View Data by Province: Takes Input of the data imported from the file and the maximum records. Prints the data sorted in descending order of the total count in each province.
void viewDatabyProvince(struct FileData data[], int max);

//3. MENU OPTION 3: View Data by Taxon : Takes Input of the data imported from the file and the maximum records. Prints the data sorted in ascending order of the total count of each taxon.
void viewDatabyTaxon(struct FileData data[], int max);

//4. MENU OPTION 4: View Data by Taxon : Takes Input of the data imported from the file and the maximum records. Prompts user to enter their choice of province and taxon. Prints the data as demanded by the user.
void viewDatabyProvinceAndTaxon(struct FileData data[], int max);


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         UTILITY FUNCTIONS
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//1. Checks the value entered is within the range inputted.
int inputIntRange(int lower_limit, int upper_limit);

//2. Calculates the total species by status for different provinces, different taxons, and different years.
void totalSpeciesByStatus(struct FileData data[], struct COSEWICDataByStatus datacount[], int number, int count);

//3. Calculates the total count as in the status of each species for each province.
void calculateDataByProvinceName(struct FileData data[], struct COSEWICDataByStatus info[], int i);

//4.Calculates the total count as in the status of each species for each taxon.
void calculateDataByTaxonName(struct FileData data[], struct COSEWICDataByStatus info[], int i);

//5. Calculates the total extinct, endangered, extirpated, threatened, and species of special concern and also the total count for all species.
void calculateTotalData(struct statusTotalData grandTotal, struct COSEWICDataByStatus data[], int max);

#endif