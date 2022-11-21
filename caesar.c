#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char change_letter(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2)  // Check if there is correct number of arguments.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)  // Check if key is a number.
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);  // Convert key to int.

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)  // Print encoded chars one by one.
    {
        printf("%c", change_letter(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

char change_letter(char c, int k)  // Function that rotates the letters by k positions.
{
    if (!isalpha(c))
    {
        return c;
    }
    else if (c >= 65 && c <= 90)
    {
        return (((c - 65) + k) % 26) + 65;
    }
    else
    {
        return (((c - 97) + k) % 26) + 97;
    }
}
