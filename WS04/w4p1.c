/*
*****************************************************************************
                          Workshop - #4 (P1)
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

    int count, loop_iterations;
    char loop_type;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop_type, &loop_iterations);

        switch (loop_type)
        {
        case 'D':
            if (loop_iterations >= 3 && loop_iterations <= 20)
            {
                count = 1;

                printf("DO-WHILE: ");
                do {
                    printf("D");
                    count++;
                } while (count <= loop_iterations);
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            break;
        case 'W':
            if (loop_iterations >= 3 && loop_iterations <= 20)
            {
                count = 1;

                printf("WHILE   : ");
                while (count <= loop_iterations)
                {
                    printf("W");
                    count++;
                }
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            break;
        case 'F':
            if (loop_iterations >= 3 && loop_iterations <= 20)
            {
                printf("FOR     : ");
                for (count = 1; count <= loop_iterations; count++)
                {
                    printf("F");
                }
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
            break;
        case 'Q':
            if (loop_iterations != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
            break;
        default:
            printf("ERROR: Invalid entered value(s)!\n\n");
            break;
        }

    } while (loop_iterations != 0 || loop_type != 'Q');

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}