#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check number of given arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate the Key
    string key = argv[1];
    int length = 26;
    char letters[length - 1];
    if (strlen(key) != length) // Check key length
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i])) // Check for non-alphabetic characters
        {
            printf("Key must contain only letters.\n");
            return 1;
        }
        for (int j = 0; j < i; j++) // Check for repeated characterss
        {
            if (toupper(key[i]) == letters[j])
            {
                printf("Letters in key must not repeat.\n");
                return 1;
            }
        }
        letters[i] = toupper(key[i]);
    }

    // Get plaintext from the user
    string plaintext = get_string("plaintext: ");
    int textlen = strlen(plaintext);
    char ciphertext[textlen];

    // Encipher
    for (int i = 0; i < textlen; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }
        else if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[plaintext[i] - 65]);
        }
        else
        {
            ciphertext[i] = tolower(key[plaintext[i] - 97]);
        }
    }

    // Print ciphertext
    printf("ciphertext: ");
    for (int i = 0 ; i < textlen; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
    return 0;
}
