#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // make sure program was run with just one command-line argument
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    // convert argv[1] from a 'string' to an 'int'
    int k = atoi(argv[1]);
    // prompt user for plaintext
    string pt = get_string("plaintext: ");
    // for each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0; i < strlen(pt); i++)
    {
        // rotate program
        char c = rotate(pt[i], k);
        printf("%c", c);
    }
    printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0; i < s[i]; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        (c = (((c - 65) + n) % 26) + 65);
    }
    if (islower(c))
    {
        (c = (((c - 97) + n) % 26) + 97);
    }
    return c;
}


