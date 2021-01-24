#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Declare variable for change

    float money_owed;

    // Amount of each coins
    int coins = 0, quarters = 0, dimes = 0, nickles = 0, pennies = 0;

    //Prompt user for change owed
    do
    {
        money_owed = get_float("Please enter the amount of change you are owed: ");
    }
    while (money_owed < 0);

    //Money in cents.

    int cents = round(money_owed * 100);

    //First we try quarters.
    if (cents >= 25)
    {
        quarters = cents / 25;
        cents = cents % 25;

    }
    //Then we try dimes

    if (cents >= 10 && cents < 25)
    {
        dimes = cents / 10;
        cents = cents % 10;
    }

    //Then we try nickles and # of pennies left
    if (cents >= 5 && cents < 10)
    {
        nickles = cents / 5;
        cents = cents % 5;
    }

    //Then logic for pennies
    if (cents >= 1 && cents < 5)
    {
        pennies = cents;
    }


    coins = quarters + dimes + nickles + pennies;

    // Print out the number of coins
    printf("%i coins \n", coins);


}