#include "helpers.h"
#include <math.h>

int minint255(int a);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Create needed variables
    int average, r, g, b;

    // Go through the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Count the avarage of the color values and set these values to the average
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;
            average = round((r + g + b) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int r, g, b, sr, sg, sb;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Change the colours to sepia versions
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;
            sr = round(.393 * r + .769 * g + .189 * b);
            sg = round(.349 * r + .686 * g + .168 * b);
            sb = round(.272 * r + .534 * g + .131 * b);
            image[i][j].rgbtRed = minint255(sr);
            image[i][j].rgbtGreen = minint255(sg);
            image[i][j].rgbtBlue = minint255(sb);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int rgb[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap two pixels
            rgb[0] = image[i][j].rgbtRed;
            rgb[1] = image[i][j].rgbtGreen;
            rgb[2] = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
            image[i][(width - 1) - j].rgbtRed = rgb[0];
            image[i][(width - 1) - j].rgbtGreen = rgb[1];
            image[i][(width - 1) - j].rgbtBlue = rgb[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sr, sg, sb, squares, mini, minj, maxi, maxj;

    // Create a copy of the image array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Set the variables
            squares = 0;
            sr = 0;
            sg = 0;
            sb = 0;
            mini = i - 1;
            minj = j - 1;
            maxi = i + 1;
            maxj = j + 1;

            // Check if edge or corner
            if (i == 0)
            {
                mini = 0;
            }
            else if (i == height - 1)
            {
                maxi = height - 1;
            }
            if (j == 0)
            {
                minj = 0;
            }
            else if (j == width - 1)
            {
                maxj = width - 1;
            }

            // Calculate sum of the color values and number of pixels from which the values are taken
            for (int k = mini; k <= maxi; k++)
            {
                for (int l = minj; l <= maxj; l++)
                {
                    sr += copy[k][l].rgbtRed;
                    sg += copy[k][l].rgbtGreen;
                    sb += copy[k][l].rgbtBlue;
                    squares++;
                }
            }

            // Change the color values of a pixel
            image[i][j].rgbtRed = round(sr / (float) squares);
            image[i][j].rgbtGreen = round(sg / (float) squares);
            image[i][j].rgbtBlue = round(sb / (float) squares);
        }
    }
    return;
}

// Return the given number if it is smaller than 255, else return 255
int minint255(int a)
{
    int max = 255;
    if (a < max)
    {
        return a;
    }
    else
    {
        return max;
    }
}
