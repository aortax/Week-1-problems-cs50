#include <stdio.h>
#include <cs50.h>

void marioBlocks(int height);

int main(void)
{
    int input;
    do
    {
        input = get_int("What is the height of the blocks you want to create: ");
    }
    while(input < 1 || input > 8);
    marioBlocks(input);
}

void marioBlocks(int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int k = height -i-1; k>=1; k--)
        {
            printf(" ");
        }
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}