#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int PDFLENGTH = 512;

int main(int argc, char *argv[])
{
    // only 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }
    // Create a Buffer for a block of data
    uint8_t buffer[PDFLENGTH];
    FILE *img = NULL;
    char filename[8];
    int filecount = 0;

    // While there is still data to read on the memory card
    while (fread(buffer, 1, PDFLENGTH, card) == PDFLENGTH)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            // Create JPEGs from the data
            sprintf(filename, "%03i.jpg", filecount++);
            img = fopen(filename, "w");
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, PDFLENGTH, img);
        }
    }
    // close everything/cleanup
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
