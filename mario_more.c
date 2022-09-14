#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");  // Letting user decide how tall the pyramids will be.
    }
    while (height < 1 || height > 8);  // Checking if they have given a right number.

    for (int i = 1; i <= height; i++)  // Drawing the pyramids.
    {
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
