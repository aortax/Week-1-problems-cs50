#include <stdio.h>
#include <cs50.h>

// Function made to generate the blocks
void marioBlocksGenerator(int height);

int main(void)
{
    int input;

    //Asking user for input
    do
    {
        input = get_int("What is the height of the blocks you want to create: ");
    }
    while (input < 1 || input > 8); // Will continue to prompt if less than 1 or greater than 8
    marioBlocksGenerator(input);
}

void marioBlocksGenerator(int height)
{
    // Vertical line going down

    // First Pyramid, which goes toward left
    for (int i = 0; i < height; i++)
    {
        // Making Spaces

        for (int k = height - i - 1; k >= 1; k--)
        {
            printf(" ");
        }

        //  Making the Mario Block

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // For Space in between the two pryamids

        for (int s = 0; s < 2; s++)
        {
            printf(" ");
        }

        // Second pyramid which goes towards the right.
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}


