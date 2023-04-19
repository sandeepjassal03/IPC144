/*
*****************************************************************************
						  Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;
	int year_of_log, month_of_log, day_of_log, flag = 0, morning_rating_flag = 0, evening_rating_flag = 0;
	
	double morning_rating[LOG_DAYS] = { 0 }, evening_rating[LOG_DAYS] = { 0 };
	double morning_rating_input = 0, evening_rating_input = 0;
	double total_morning_ratings = 0, total_evening_ratings = 0, total_overall_ratings = 0;
	double average_morning_ratings = 0, average_evening_ratings = 0, average_overall_ratings = 0;

	printf("General Well-being Log\n");
	printf("======================\n");

	while (flag == 0)
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf(" %d %d", &year_of_log, &month_of_log);

		if (year_of_log < MIN_YEAR || year_of_log > MAX_YEAR)
		{
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			if (month_of_log < JAN || month_of_log > DEC)
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
		}
		else if (month_of_log < JAN || month_of_log > DEC)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}

		else if ((year_of_log >= MIN_YEAR && year_of_log <= MAX_YEAR) && (month_of_log >= JAN || month_of_log <= DEC))
		{
			flag = 1;
			printf("\n*** Log date set! ***\n");
		}
	}

	for (day_of_log = 0; day_of_log < LOG_DAYS; day_of_log++)
	{
		if (flag == 1)
		{
			switch (month_of_log)
			{
			case 1:
				printf("\n%d-JAN-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 2:
				printf("\n%d-FEB-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 3:
				printf("\n%d-MAR-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 4:
				printf("\n%d-APR-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 5:
				printf("\n%d-MAY-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 6:
				printf("\n%d-JUN-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 7:
				printf("\n%d-JUL-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 8:
				printf("\n%d-AUG-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 9:
				printf("\n%d-SEP-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 10:
				printf("\n%d-OCT-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 11:
				printf("\n%d-NOV-0%d\n", year_of_log, day_of_log + 1);
				break;
			case 12:
				printf("\n%d-DEC-0%d\n", year_of_log, day_of_log + 1);
				break;
			}
			while (morning_rating_flag == 0)
			{
				printf("   Morning rating (0.0-5.0): ");
				scanf(" %lf", &morning_rating_input);
				if (morning_rating_input >= 0 && morning_rating_input <= 5)
				{
					morning_rating[day_of_log] = morning_rating_input;
					morning_rating_flag = 1;
				}
				else
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			}
			while (evening_rating_flag == 0)
			{
				printf("   Evening rating (0.0-5.0): ");
				scanf(" %lf", &evening_rating_input);
				if (evening_rating_input >= 0 && evening_rating_input <= 5)
				{
					evening_rating[day_of_log] = evening_rating_input;
					evening_rating_flag = 1;
				}
				else
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
			} 
			morning_rating_flag = 0, evening_rating_flag = 0;
		}
	}

	for (day_of_log = 0; day_of_log < LOG_DAYS; day_of_log++)
	{
		total_morning_ratings += morning_rating[day_of_log];
		total_evening_ratings += evening_rating[day_of_log];
	}

	total_overall_ratings = total_morning_ratings + total_evening_ratings;
	average_morning_ratings = total_morning_ratings / LOG_DAYS;
	average_evening_ratings = total_evening_ratings / LOG_DAYS;
	average_overall_ratings = (average_morning_ratings + average_evening_ratings) / 2;

	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating: %0.3lf\n", total_morning_ratings);
	printf("Evening total rating:  %0.3lf\n", total_evening_ratings);
	printf("----------------------------\n");
	printf("Overall total rating: %0.3lf\n\n", total_overall_ratings);

	printf("Average morning rating:  %0.1lf\n", average_morning_ratings);
	printf("Average evening rating:  %0.1lf\n", average_evening_ratings);
	printf("----------------------------\n");
	printf("Average overall rating:  %0.1lf\n", average_overall_ratings);

	return 0;
}