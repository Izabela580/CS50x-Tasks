#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Prototypes of the functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: "); // Take text from the user

    // Use of the Coleman-Liau index to determine the grade
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Decide what to print
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text) // Count number of letters in the given text
{
    int number = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            number++;
        }
    }
    return number;
}

int count_words(string text) // Count number of words in the given text
{
    int number = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            number++;
        }
    }
    return number;
}

int count_sentences(string text) // Count number of sentences in the given text
{
    int number = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            number++;
        }
    }
    return number;
}
