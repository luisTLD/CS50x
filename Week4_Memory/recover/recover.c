#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Exemple: ./recover card.raw

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // File name
    char fileName[8];
    int total = 0;
    FILE *output = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(fileName, "%03i.jpg", total++);

            output = fopen(fileName, "w");
            if (output != NULL)
            {
                fwrite(buffer, 1, 512, output);
            }
        }
        else if (output != NULL)
        {
            fwrite(buffer, 1, 512, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(card);

    return 0;
}
