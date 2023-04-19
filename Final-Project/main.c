// IPC144 2022 Summer Final Assessment Coding Project
// --------------------------------------------------
// Project idea is based on COSEWIC reports for SAR
//
//      COSEWIC: Committee on the Status of Endangered Wildlife in Canada
//      SAR:     Species At Risk
// 
// Source: https://bit.ly/3AEgab9
// 
// Note: The data used for this assignment has been fictionalized with invalid counts

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

#include <stdio.h>
#include "cosewic.h"

#define DATA_FILE "data.txt"
#define MAX_RECORDS 6500





int main(void)
{
    int records = 0;
    struct FileData data[MAX_RECORDS] = { {0} }; //An object of structure FileData declared and initialised.

    printf("Loading data from file: %s\n", DATA_FILE);
    records = loadData(DATA_FILE, data, MAX_RECORDS); //Count of Total records loaded returned to records variable
    printf("%d data records read from file...\n\n", records);

    if (records > 0)
    {
        // Entry point to application logic
        mainLogic(data, records);
    }
    else
    {
        printf("Ooooops there seems to have been an error loading data!\n");
    }

    return 0;
}
/* Sample Inputs:
-1
5
1
2
3
4
-1
14
9
-1
11
4
4
7
8
*/