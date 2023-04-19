#pragma once
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

// Clear the standard input buffer
void clearInputBuffer(void);
// Wait for user to input the "enter" key to continue
void suspend(void);

//1.
int inputInt(void);

//2.
int inputIntPositive(void);

//3.
int inputIntRange(int, int);

//4.
char inputCharOption(const char[]);

//5.
void inputCString(char[], int, int);

//6.
void displayFormattedPhone(const char[]);

