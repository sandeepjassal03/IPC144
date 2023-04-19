/*
*****************************************************************************
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    //const char patSize = 'S';
    double small_shirt_price, medium_shirt_price, large_shirt_price;
    int TotalShirts;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("\n%lf", &small_shirt_price);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("\n%lf", &medium_shirt_price);
    printf("Enter the price for a LARGE shirt: $");
    scanf("\n%lf", &large_shirt_price);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%0.2lf\n", small_shirt_price);
    printf("MEDIUM : $%0.2lf\n", medium_shirt_price);
    printf("LARGE  : $%0.2lf\n\n", large_shirt_price);
    printf("Patty's shirt size is 'S'\n");
    
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &TotalShirts);
    printf("\nPatty's shopping cart...\n");

    int subtotal_in_cents, Taxes_in_100cents;

    subtotal_in_cents = small_shirt_price * TotalShirts * 100;
    Taxes_in_100cents = subtotal_in_cents * TAX + 0.5;

    printf("Contains : %d shirts", TotalShirts);
    printf("\nSub-total: $%8.4lf", (double)subtotal_in_cents / 100);
    printf("\nTaxes    : $%8.4f", (double)Taxes_in_100cents / 100);
    printf("\nTotal    : $%8.4lf\n", ((double)subtotal_in_cents / 100) + ((double)Taxes_in_100cents / 100));
     
    return 0;
}