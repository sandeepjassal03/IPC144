/*
*****************************************************************************
                          Workshop - #4 (P2)
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

int main(void)
{
    int number_of_apples, number_of_oranges, number_of_pears, number_of_tomatoes, number_of_cabbages;
    int apples_picked, oranges_picked, pears_picked, tomatoes_picked, cabbages_picked;
    int flag = 0, another_shop = 1;

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &number_of_apples);
            if (number_of_apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (number_of_apples < 0);
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &number_of_oranges);
            if (number_of_oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (number_of_oranges < 0);
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &number_of_pears);
            if (number_of_pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (number_of_pears < 0);
        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &number_of_tomatoes);
            if (number_of_tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (number_of_tomatoes < 0);
        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &number_of_cabbages);
            if (number_of_cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (number_of_cabbages < 0);

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        if (number_of_apples != 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &apples_picked);

                if (apples_picked > 0)
                {
                    if (apples_picked > number_of_apples)
                    {
                        printf("You picked too many... only %d more APPLE(S) are needed.\n", number_of_apples);
                    }
                    else if (apples_picked < number_of_apples)
                    {
                        number_of_apples -= apples_picked;
                        printf("Looks like we still need some APPLES...\n");
                    }
                    else if (apples_picked == number_of_apples)
                    {
                        printf("Great, that's the apples done!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (flag == 0);
        }

        flag = 0;

        if (number_of_oranges != 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &oranges_picked);
                if (oranges_picked > 0)
                {
                    if (oranges_picked > number_of_oranges)
                    {
                        printf("You picked too many... only %d more ORANGE(S) are needed.\n", number_of_oranges);
                    }
                    else if (oranges_picked < number_of_oranges)
                    {
                        number_of_oranges -= oranges_picked;
                        printf("Looks like we still need some ORANGES...\n");
                    }
                    else if (oranges_picked == number_of_oranges)
                    {
                        printf("Great, that's the oranges done!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (flag == 0);
        }
        flag = 0;

        if (number_of_pears != 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &pears_picked);

                if (pears_picked > 0)
                {
                    if (pears_picked > number_of_pears)
                    {
                        printf("You picked too many... only %d more PEAR(S) are needed.\n", number_of_pears);
                    }
                    else if (pears_picked < number_of_pears)
                    {
                        number_of_pears -= pears_picked;
                        printf("Looks like we still need some PEARS...\n");
                    }
                    else if (pears_picked == number_of_pears)
                    {
                        printf("Great, that's the pears done!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (flag == 0);
        }
        flag = 0;

        if (number_of_tomatoes != 0)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &tomatoes_picked);
                
                if (tomatoes_picked > 0)
                {
                    if (tomatoes_picked > number_of_tomatoes)
                    {
                        printf("You picked too many... only %d more TOMATO(ES) are needed.\n", number_of_tomatoes);
                    }
                    else if (tomatoes_picked < number_of_tomatoes)
                    {
                        number_of_tomatoes -= tomatoes_picked;
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                    else if (tomatoes_picked == number_of_tomatoes)
                    {
                        printf("Great, that's the tomatoes done!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (flag == 0);
        }
        flag = 0;

        if (number_of_cabbages != 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &cabbages_picked);
                if (cabbages_picked > 0)
                {
                    if (cabbages_picked > number_of_cabbages)
                    {
                        printf("You picked too many... only %d more CABBAGE(S) are needed.\n", number_of_cabbages);
                    }
                    else if (cabbages_picked < number_of_cabbages)
                    {
                        number_of_cabbages -= cabbages_picked;
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                    else if (cabbages_picked == number_of_cabbages)
                    {
                        printf("Great, that's the cabbages done!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (flag == 0);
        }

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf(" %d", &another_shop);
        printf("\n");

    } while (another_shop != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

 return 0;
}