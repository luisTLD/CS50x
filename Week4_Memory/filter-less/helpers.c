#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Update pixel values
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;

            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            // Swap pixels
            RGBTRIPLE tmp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = tmp;
        }
    }
}


// Auxiliar functions
int blurRedValue(int i, int j, int height, int width, RGBTRIPLE image[height][width]);
int blurGreenValue(int i, int j, int height, int width, RGBTRIPLE image[height][width]);
int blurBlueValue(int i, int j, int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
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
            image[i][j].rgbtRed = blurRedValue(i, j, height, width, copy);
            image[i][j].rgbtGreen = blurGreenValue(i, j, height, width, copy);
            image[i][j].rgbtBlue = blurBlueValue(i, j, height, width, copy);
        }
    }
}

int blurRedValue(int x, int y, int height, int width, RGBTRIPLE image[height][width]){
    float sum = 0;
    float using = 0;

    for (int i = x - 1; i < x + 2; i++)
    {
        for (int j = y - 1; j < y + 2; j++)
        {
            if (((i >= 0) && i < height) && ((j >= 0) && j < width))
            {
                sum += image[i][j].rgbtRed;
                using++;
            }
        }
    }

    int value = round(sum / using);
    return value;
}

int blurGreenValue(int x, int y, int height, int width, RGBTRIPLE image[height][width]){
    float sum = 0;
    float using = 0;

    for (int i = x - 1; i < x + 2; i++)
    {
        for (int j = y - 1; j < y + 2; j++)
        {
            if (((i >= 0) && i < height) && ((j >= 0) && j < width))
            {
                sum += image[i][j].rgbtGreen;
                using++;
            }
        }
    }

    int value = round(sum / using);
    return value;
}

int blurBlueValue(int x, int y, int height, int width, RGBTRIPLE image[height][width]){
    float sum = 0;
    float using = 0;

    for (int i = x - 1; i < x + 2; i++)
    {
        for (int j = y - 1; j < y + 2; j++)
        {
            if (((i >= 0) && i < height) && ((j >= 0) && j < width))
            {
                sum += image[i][j].rgbtBlue;
                using++;
            }
        }
    }

    int value = round(sum / using);
    return value;
}
