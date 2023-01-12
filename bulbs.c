#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Declare globals
const int BITS_IN_BYTE = 8;
int bits[BITS_IN_BYTE];

// Inform about created functions
void print_bulb(int bit);
void to_binary(int number);

int main(void)
{
    // Get a message from the user
    string message = get_string("Message: ");
    int length = strlen(message);

    int byte;

    // Print each character as a sequence of bulbs icons
    for (int i = 0; i < length; i++)
    {
        byte = (int)message[i];
        to_binary(byte);
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(bits[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

// Change decimal number to binary
void to_binary(int number)
{
    int power;
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        power = pow(2, 7 - i);
        if (power <= number)
        {
            number -= power;
            bits[i] = 1;
        }
        else
        {
            bits[i] = 0;
        }
    }
}
