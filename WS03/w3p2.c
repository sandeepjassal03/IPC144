/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee_1_type, coffee_1_grind_size, coffee_1_served_with_cream, coffee_2_type, coffee_2_grind_size, coffee_2_served_with_cream, coffee_3_type, coffee_3_grind_size, coffee_3_served_with_cream, coffee_strength, coffee_preferred_with_cream, coffee_making_equipment_used;
        
    int coffee_1_bag_weight_in_grams,  coffee_2_bag_weight_in_grams,  coffee_3_bag_weight_in_grams, number_of_daily_servings;
    
    double coffee_1_serving_temperature, coffee_2_serving_temperature, coffee_3_serving_temperature;
    
    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = (celsius * 1.8) + 32.0);

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
 
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffee_1_type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffee_1_grind_size);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee_1_bag_weight_in_grams);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_1_served_with_cream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &coffee_1_serving_temperature);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffee_2_type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffee_2_grind_size);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee_2_bag_weight_in_grams);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_2_served_with_cream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &coffee_2_serving_temperature);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffee_3_type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffee_3_grind_size);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee_3_bag_weight_in_grams);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_3_served_with_cream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &coffee_3_serving_temperature);
    
    //Table

    printf("\n---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffee_1_type == 'L' || coffee_1_type == 'l'), (coffee_1_type == 'B' || coffee_1_type == 'b'), (coffee_1_grind_size == 'C' || coffee_1_grind_size == 'c'), (coffee_1_grind_size == 'F' || coffee_1_grind_size == 'f'), coffee_1_bag_weight_in_grams, (coffee_1_bag_weight_in_grams / GRAMS_IN_LBS), (coffee_1_served_with_cream == 'Y' || coffee_1_served_with_cream == 'y'), coffee_1_serving_temperature, ((coffee_1_serving_temperature * 1.8) + 32.0));

    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffee_2_type == 'L' || coffee_2_type == 'l'), (coffee_2_type == 'B' || coffee_2_type == 'b'), (coffee_2_grind_size == 'C' || coffee_2_grind_size == 'c'), (coffee_2_grind_size == 'F' || coffee_2_grind_size == 'f'), coffee_2_bag_weight_in_grams, (coffee_2_bag_weight_in_grams / GRAMS_IN_LBS), (coffee_2_served_with_cream == 'Y' || coffee_2_served_with_cream == 'y'), coffee_2_serving_temperature, ((coffee_2_serving_temperature * 1.8) + 32.0));

    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n", (coffee_3_type == 'L' || coffee_3_type == 'l'), (coffee_3_type == 'B' || coffee_3_type == 'b'), (coffee_3_grind_size == 'C' || coffee_3_grind_size == 'c'), (coffee_3_grind_size == 'F' || coffee_3_grind_size == 'f'), coffee_3_bag_weight_in_grams, (coffee_3_bag_weight_in_grams / GRAMS_IN_LBS), (coffee_3_served_with_cream == 'Y' || coffee_3_served_with_cream == 'y'), coffee_3_serving_temperature, ((coffee_3_serving_temperature * 1.8) + 32.0));

    //Table Ends

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_preferred_with_cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &number_of_daily_servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffee_making_equipment_used);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");

    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_1_type == 'L' || coffee_1_type == 'l') && (coffee_strength == 'M' || coffee_strength == 'm')) || ((coffee_1_type == 'B' || coffee_1_type == 'b') && (coffee_strength == 'r' || coffee_strength == 'R')), ((coffee_1_grind_size == 'c' || coffee_1_grind_size == 'C') && (coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R')) || ((coffee_1_grind_size == 'F' || coffee_1_grind_size == 'f') && (coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C')), ((number_of_daily_servings >= 1 && number_of_daily_servings <= 4) && (coffee_1_bag_weight_in_grams >= 0 && coffee_1_bag_weight_in_grams <= 250)) || ((number_of_daily_servings > 4 && number_of_daily_servings <= 9) && (coffee_1_bag_weight_in_grams > 250 && coffee_1_bag_weight_in_grams <= 500)) || ((number_of_daily_servings >= 10) && (coffee_1_bag_weight_in_grams > 500 && coffee_1_bag_weight_in_grams <= 1000)), ((coffee_1_served_with_cream == 'y' || coffee_1_served_with_cream == 'Y') && (coffee_preferred_with_cream == 'Y' || coffee_preferred_with_cream == 'y')) || ((coffee_1_served_with_cream == 'n' || coffee_1_served_with_cream == 'N') && (coffee_preferred_with_cream == 'n' || coffee_preferred_with_cream == 'N')), ((coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R') && (coffee_1_serving_temperature >= 60.0 && coffee_1_serving_temperature <= 69.9)) || ((coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C') && (coffee_1_serving_temperature >= 70.0)));

    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_2_type == 'L' || coffee_2_type == 'l') && (coffee_strength == 'M' || coffee_strength == 'm')) || ((coffee_2_type == 'B' || coffee_2_type == 'b') && (coffee_strength == 'r' || coffee_strength == 'R')), ((coffee_2_grind_size == 'c' || coffee_2_grind_size == 'C') && (coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R')) || ((coffee_2_grind_size == 'F' || coffee_2_grind_size == 'f') && (coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C')), ((number_of_daily_servings >= 1 && number_of_daily_servings <= 4) && (coffee_2_bag_weight_in_grams >= 0 && coffee_2_bag_weight_in_grams <= 250)) || ((number_of_daily_servings > 4 && number_of_daily_servings <= 9) && (coffee_2_bag_weight_in_grams > 250 && coffee_2_bag_weight_in_grams <= 500)) || ((number_of_daily_servings >= 10) && (coffee_2_bag_weight_in_grams > 500 && coffee_2_bag_weight_in_grams <= 1000)), ((coffee_2_served_with_cream == 'y' || coffee_2_served_with_cream == 'Y') && (coffee_preferred_with_cream == 'Y' || coffee_preferred_with_cream == 'y')) || ((coffee_2_served_with_cream == 'n' || coffee_2_served_with_cream == 'N') && (coffee_preferred_with_cream == 'n' || coffee_preferred_with_cream == 'N')), ((coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R') && (coffee_2_serving_temperature >= 60.0 && coffee_2_serving_temperature <= 69.9)) || ((coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C') && (coffee_2_serving_temperature >= 70.0)));

    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", ((coffee_3_type == 'L' || coffee_3_type == 'l') && (coffee_strength == 'M' || coffee_strength == 'm')) || ((coffee_3_type == 'B' || coffee_3_type == 'b') && (coffee_strength == 'r' || coffee_strength == 'R')), ((coffee_3_grind_size == 'c' || coffee_3_grind_size == 'C') && (coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R')) || ((coffee_3_grind_size == 'F' || coffee_3_grind_size == 'f') && (coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C')), ((number_of_daily_servings >= 1 && number_of_daily_servings <= 4) && (coffee_3_bag_weight_in_grams >= 0 && coffee_3_bag_weight_in_grams <= 250)) || ((number_of_daily_servings > 4 && number_of_daily_servings <= 9) && (coffee_3_bag_weight_in_grams > 250 && coffee_3_bag_weight_in_grams <= 500)) || ((number_of_daily_servings >= 10) && (coffee_3_bag_weight_in_grams > 500 && coffee_3_bag_weight_in_grams <= 1000)), ((coffee_3_served_with_cream == 'y' || coffee_3_served_with_cream == 'Y') && (coffee_preferred_with_cream == 'Y' || coffee_preferred_with_cream == 'y')) || ((coffee_3_served_with_cream == 'n' || coffee_3_served_with_cream == 'N') && (coffee_preferred_with_cream == 'n' || coffee_preferred_with_cream == 'N')), ((coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R') && (coffee_3_serving_temperature >= 60.0 && coffee_3_serving_temperature <= 69.9)) || ((coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C') && (coffee_3_serving_temperature >= 70.0)));

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee_preferred_with_cream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &number_of_daily_servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffee_making_equipment_used);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");

    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_1_type == 'L' || coffee_1_type == 'l') && (coffee_strength == 'M' || coffee_strength == 'm')) || ((coffee_1_type == 'B' || coffee_1_type == 'b') && (coffee_strength == 'r' || coffee_strength == 'R')), ((coffee_1_grind_size == 'c' || coffee_1_grind_size == 'C') && (coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R')) || ((coffee_1_grind_size == 'F' || coffee_1_grind_size == 'f') && (coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C')), ((number_of_daily_servings >= 1 && number_of_daily_servings <= 4) && (coffee_1_bag_weight_in_grams >= 0 && coffee_1_bag_weight_in_grams <= 250)) || ((number_of_daily_servings > 4 && number_of_daily_servings <= 9) && (coffee_1_bag_weight_in_grams > 250 && coffee_1_bag_weight_in_grams <= 500)) || ((number_of_daily_servings >= 10) && (coffee_1_bag_weight_in_grams > 500 && coffee_1_bag_weight_in_grams <= 1000)), ((coffee_1_served_with_cream == 'y' || coffee_1_served_with_cream == 'Y') && (coffee_preferred_with_cream == 'Y' || coffee_preferred_with_cream == 'y')) || ((coffee_1_served_with_cream == 'n' || coffee_1_served_with_cream == 'N') && (coffee_preferred_with_cream == 'n' || coffee_preferred_with_cream == 'N')), ((coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R') && (coffee_1_serving_temperature >= 60.0 && coffee_1_serving_temperature <= 69.9)) || ((coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C') && (coffee_1_serving_temperature >= 70.0)));

    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_2_type == 'L' || coffee_2_type == 'l') && (coffee_strength == 'M' || coffee_strength == 'm')) || ((coffee_2_type == 'B' || coffee_2_type == 'b') && (coffee_strength == 'r' || coffee_strength == 'R')), ((coffee_2_grind_size == 'c' || coffee_2_grind_size == 'C') && (coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R')) || ((coffee_2_grind_size == 'F' || coffee_2_grind_size == 'f') && (coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C')), ((number_of_daily_servings >= 1 && number_of_daily_servings <= 4) && (coffee_2_bag_weight_in_grams >= 0 && coffee_2_bag_weight_in_grams <= 250)) || ((number_of_daily_servings > 4 && number_of_daily_servings <= 9) && (coffee_2_bag_weight_in_grams > 250 && coffee_2_bag_weight_in_grams <= 500)) || ((number_of_daily_servings >= 10) && (coffee_2_bag_weight_in_grams > 500 && coffee_2_bag_weight_in_grams <= 1000)), ((coffee_2_served_with_cream == 'y' || coffee_2_served_with_cream == 'Y') && (coffee_preferred_with_cream == 'Y' || coffee_preferred_with_cream == 'y')) || ((coffee_2_served_with_cream == 'n' || coffee_2_served_with_cream == 'N') && (coffee_preferred_with_cream == 'n' || coffee_preferred_with_cream == 'N')), ((coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R') && (coffee_2_serving_temperature >= 60.0 && coffee_2_serving_temperature <= 69.9)) || ((coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C') && (coffee_2_serving_temperature >= 70.0)));

    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_3_type == 'L' || coffee_3_type == 'l') && (coffee_strength == 'M' || coffee_strength == 'm')) || ((coffee_3_type == 'B' || coffee_3_type == 'b') && (coffee_strength == 'r' || coffee_strength == 'R')), ((coffee_3_grind_size == 'c' || coffee_3_grind_size == 'C') && (coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R')) || ((coffee_3_grind_size == 'F' || coffee_3_grind_size == 'f') && (coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C')), ((number_of_daily_servings >= 1 && number_of_daily_servings <= 4) && (coffee_3_bag_weight_in_grams >= 0 && coffee_3_bag_weight_in_grams <= 250)) || ((number_of_daily_servings > 4 && number_of_daily_servings <= 9) && (coffee_3_bag_weight_in_grams > 250 && coffee_3_bag_weight_in_grams <= 500)) || ((number_of_daily_servings >= 10) && (coffee_3_bag_weight_in_grams > 500 && coffee_3_bag_weight_in_grams <= 1000)), ((coffee_3_served_with_cream == 'y' || coffee_3_served_with_cream == 'Y') && (coffee_preferred_with_cream == 'Y' || coffee_preferred_with_cream == 'y')) || ((coffee_3_served_with_cream == 'n' || coffee_3_served_with_cream == 'N') && (coffee_preferred_with_cream == 'n' || coffee_preferred_with_cream == 'N')), ((coffee_making_equipment_used == 'r' || coffee_making_equipment_used == 'R') && (coffee_3_serving_temperature >= 60.0 && coffee_3_serving_temperature <= 69.9)) || ((coffee_making_equipment_used == 'c' || coffee_making_equipment_used == 'C') && (coffee_3_serving_temperature >= 70.0)));


    printf("\nHope you found a product that suits your likes!\n");
    return 0;
}