#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Can not open the file.\n");
        return 1;
    }

    // Read header
    WAVHEADER *header = malloc(44);
    fread(header, 1, 44, input);

    // Use check_format to ensure WAV format
    if (!check_format(*header))
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Can not open the file.\n");
        return 1;
    }

    // Write header to file
    fwrite(header, 1, 44, output);

    // Use get_block_size to calculate size of block
    int size = get_block_size(*header);

    // Write reversed audio to file
    BYTE buffer[size];
    long headerEnd = ftell(input);
    fseek(input, -1 * size, SEEK_END);
    while (ftell(input) >= headerEnd)
    {
        fread(buffer, 1, size, input);
        fwrite(buffer, 1, size, output);
        fseek(input, -2 * size, SEEK_CUR);
    }

    fclose(input);
    fclose(output);
    free(header);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}
