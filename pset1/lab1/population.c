#include <cs50.h>
#include <stdio.h>

void year_taken();
int main(void)
{
    // Variables we will need. The start population,  the end, the gained at x year, the lost at x year,  the current population
    // population that changed at y year.

    int start_population;
    int end_population;
    int population_gained;
    int population_lost;
    int population_change;
    int years = 0;
    int population;

    // TODO: Prompt for start size
    do
    {
        start_population = get_int("Please enter the initial population of the group: ");
    }
    while (start_population < 9);

    // TODO: Prompt for end size

    do
    {
        end_population = get_int("Please enter the ending population of the group: ");
    }
    while (end_population < start_population);

    // TODO: Calculate number of years until we reach threshold

    // Create a duplicate value, just to make it easier to read.

    population = start_population;

    // We use a while loop, because if it is the same start and end,
    // we don't want to run the loop and we don't know how long it will take so can't use a for loop.

    while (population < end_population)
    {
        // Calculate the gained population.

        population_gained = population * 1 / 3;

        // Calculate the lost population.

        population_lost = population * 1 / 4;

        // Calculate the change in population with delta of gain & loss.

        population_change = population_gained - population_lost;

        // Now add on the change in population.
        population += population_change;

        years++;
    }
    // TODO: Print number of years
    printf("Years: %i", years);

}
