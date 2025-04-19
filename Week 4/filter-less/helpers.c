#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int average = 0;
            average =
                round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int RGBCAP = 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepia_red = 0;
            int sepia_green = 0;
            int sepia_blue = 0;
            sepia_red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                              0.189 * image[i][j].rgbtBlue);
            sepia_green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                                0.168 * image[i][j].rgbtBlue);
            sepia_blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                               0.131 * image[i][j].rgbtBlue);

            if (sepia_red > RGBCAP)
            {
                sepia_red = RGBCAP;
            }
            if (sepia_green > RGBCAP)
            {
                sepia_green = RGBCAP;
            }
            if (sepia_blue > RGBCAP)
            {
                sepia_blue = RGBCAP;
            }

            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap Pixels
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redcount = 0, greencount = 0, bluecount = 0;
            int count = 0;

            for (int mi = -1; mi <= 1; mi++)
            {
                for (int oj = -1; oj <= 1; oj++)
                {
                    int ni = i + mi;
                    int nj = j + oj;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redcount += image[ni][nj].rgbtRed;
                        greencount += image[ni][nj].rgbtGreen;
                        bluecount += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            copy[i][j].rgbtRed = round((float) redcount / count);
            copy[i][j].rgbtGreen = round((float) greencount / count);
            copy[i][j].rgbtBlue = round((float) bluecount / count);
        }
    }

    // Move the copy back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}
