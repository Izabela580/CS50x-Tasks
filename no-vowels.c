#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Check if there is only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    // Print the argument with replaced vowels
    printf("%s\n", replace(argv[1]));

    return 0;
}

string replace(string word)
{
    // Go through the word
    for (int i = 0; i < strlen(word); i++)
    {
        // Decide whether to change the letter
        switch (tolower(word[i]))
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                break;
        }
    }
    return word;
}
