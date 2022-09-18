#include <cs50.h>
#include <stdio.h>

long power(int number, int power);

int main(void)
{
    long cardNumber = get_long("Number: "); // Taking credit card number from the user.

    int checksum = 0;

    long cardNumber2 = cardNumber; // Assigning value of cardNumber to another variable.

    int length = 0;
    while (cardNumber2 > 0) // Checking the algorithm and getting the number's length.
    {
        if (length % 2 != 0) // Part of algorithm for every other digit.
        {
            int number = 2 * (cardNumber2 % 10);
            checksum += number % 10;
            checksum += number / 10;
        }
        else
        {
            checksum += cardNumber2 % 10; // Part of algorithm for not multiplied by 2 digits.
        }
        cardNumber2 /= 10;
        length++;
    }

    if (checksum % 10 != 0) // Checking if the checksum is ok.
    {
        printf("INVALID\n");
    }
    else
    {
        if (length == 15 && (cardNumber / power(10, 13) == 34 || cardNumber / power(10, 13) == 37)) // checking American Express
        {
            printf("AMEX\n");
        }
        else if (length == 13 && cardNumber / power(10, 12) == 4) // checking Visa
        {
            printf("VISA\n");
        }
        else if (length == 16)
        {
            if (cardNumber / power(10, 15) == 4) // checking Visa for different length
            {
                printf("VISA\n");
            }
            else if (cardNumber / power(10, 14) >= 51 && cardNumber / power(10, 14) <= 55) // checking MasterCard
            {
                printf("MASTERCARD\n");
            }
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
}

long power(int number, int power)
{
    // A function that raises given number to the given power.
    long result = 1;
    for (int i = 1; i <= power; i++)
    {
        result *= number;
    }
    return result;
}
