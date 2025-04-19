#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) //allows us to use arguments for intergers and strings
{
    // Get user input
    // before using command line arguements string text = get_string("Input:\n");
    if (argc != 2) // if argument count is not equal to 2
    {
        printf("Please provide a word.\n"); // ask user to input another word.
        return 1;
    }

    string text = argv[1];

    for (int i = 0, len = strlen(text); i < len; i++) // going character by character to see if they are alphabetical | strlen means string length
    {
        if (!isalpha(text[i])) // if not a letter
        {
            printf("This is not a letter.\n"); // if it isn't a letter this will let them know
            return 2;
        }
    }

    for (int i = 0, len = strlen(text); i < len; i++) // Iterate through each element in the string
    {
        // printf("%c - %i\n ", text[i], text[i]); testing our work

        if (text[i] < text[i - 1])
        {
            printf("No\n");
            return 0;
        }
    }

    // Print out yes or no
    printf("Yes\n");
}
