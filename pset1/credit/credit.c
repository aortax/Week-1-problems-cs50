#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // List out all the possible starting digits and their meanings.
    // Start with American Express.

    int ae1 = 34;
    int ae2 = 37;

    // Then we do mastercard.

    int m1 = 51;
    int m2 = 52;
    int m3 = 53;
    int m4 = 54;
    int m5 = 55;

    // Then we do visa.

    int v = 4;

    // Brand values for if statement chain later to get our brand printed out right.
    int brand = 0;

    //  Our counter

    int count = 0;

    // Place holder values for Luhn algorithim calculations.

    int tempx = 0;
    int last = 0;
    int seclast = 0;

    // Asks for the credit card #

    long card = get_long("Please enter your credit card number : ");

    // duplicate variable for the credit cards #, because we don't want to have any changes to the credit card number yet.

    long temp = card;

    // We will run this loop till we get temp / 10 = 0 , because we are using int we will have truncation to get number of digits.
    // count++ to keep track of number of digits.

    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }

    // If digits are equal to 13 and first digit is = 4 it's a visa brand candidate, through 10^13/10^13.

    if (count == 13)
    {
        // made a new variable,
        int temp13 = card / 1000000000000;
        if (temp13 == v)
        {
            brand = 1;
        }
    }

    // Now we do check if it is 15 digits, and for amex canidate.

    else if (count == 15)
    {
        // Checks the first two digits, because it gets the first 2 digits, and right length, through 10^15 / 10^14.

        int temp15 = card / 10000000000000;

        // We check if first two digits match up for card with digit length 15.

        if (temp15 == ae1 || temp15 == ae2)
        {
            brand = 2;
        }
    }

    // For 16 digits we have two candidates which are MasterCard & Visa, so we will have to checks inside.

    else if (count == 16)
    {
        // Checks if master card, and gets first 2 digits. 10^16 / 10^15, to get first two digits.

        int temp16mc = card / 100000000000000;

        // Checks if Visa because isolates first digit.

        int temp16v = card / 1000000000000000;

        // Check if Visa, if card with length 15 digits has

        if (temp16v == 4)
        {
            brand = 1;
        }

        // If it not a visa then check if its a mastercard

        else if (temp16mc == m1 || temp16mc == m2 || temp16mc == m3 || temp16mc == m4 || temp16mc == m5)
        {
            brand = 3;
        }
    }

    // Now if we have a valid card # based on digits, and starting #s,

    if (brand != 0)
    {

        // We are going to keep doing this till we have finished the entire card like we did for digit #s.

        while (card > 0)
        {
            // Get the value for the last integer.

            last += card % 10;

            // Now we divide the card by 10 to shave off the last integer

            card = card / 10;

            // Get the value of the second to last integer * 2.

            tempx = (card % 10) * 2;

            // Check if second too last value will be greater than nine and if it is we need to split up.

            if (tempx > 9)
            {
                seclast += tempx % 10 + tempx / 10;
            }

            // if it is not than we will just roll with the current value * 2.

            else
            {
                seclast += tempx;
            }

            // If we do not do this it will double count the second to last digit as the last digit, and hence forth, ruining the program.

            card = card / 10;
        }

        // Now check if the values added up work out to have last digit be 0.

        if ((seclast + last) % 10 == 0)
        {
            // Print out the card type.
            if (brand == 1)
            {
                printf("VISA\n");
            }
            if (brand == 2)
            {
                printf("AMEX\n");
            }
            if (brand == 3)
            {
                printf("MASTERCARD\n");
            }
        }

        // If not the card invalid

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}