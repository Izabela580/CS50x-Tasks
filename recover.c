#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define a new data type.
typedef uint8_t BYTE;

int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check if there is exactly one command-line argument.
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the file given as a command-line argument.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int n = 0;
    char *filename = malloc(8);
    sprintf(filename, "%03i.jpg", n);
    FILE *outfile = fopen(filename, "w");;

    // Repeat until end of the file.
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If first JPEG
            if (n == 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, outfile);
                n++;
            }
            else
            {
                fclose(outfile);
                sprintf(filename, "%03i.jpg", n);
                outfile = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, outfile);
                n++;
            }

        }
        else
        {
            // If already found JPEG
            if (n != 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, outfile);
            }
        }
    }

    // Close remaining files and free memory.
    fclose(outfile);
    fclose(file);
    free(filename);
}
