#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string sub(string keys, string pts);
bool only_chars(string s);
bool no_repeats(string letters);
string ciphers;

int main(int argc, string argv[])
{
    // Only 1 command line argument that is 26 characters long
    if (argc != 2 || only_chars(argv[1]) == false || no_repeats(argv[1]) == false)
    {
        printf("Only 1 command argument that uses alphabet only and does not repeat, please\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("invalid, command argument must be 26 characters in length\n");
        return 1;
    }

    string key = argv[1];
    string pt = get_string("plaintext: ");
    sub(key, pt);
    printf("ciphertext: %s\n", ciphers);
}

string sub(string keys, string pts)
{
    char cipher[strlen(pts)];
    for (int i = 0; i < strlen(pts) + 1; i++)
        if (isupper(pts[i]))
        {
            int j = pts[i] - 'A';
            char newkey = keys[j];
            cipher[i] = toupper(newkey);
        }

        else if (islower(pts[i]))
        {
            int j = pts[i] - 'a';
            char newkey = keys[j];
            cipher[i] = tolower(newkey);
        }
        else
        {
            cipher[i] = pts[i];
        }
    ciphers = cipher;
    printf("%s\n", cipher);
    printf("%s\n", ciphers);
    return ciphers;
}

bool only_chars(string s)
{
    for (int i = 0; i < s[i]; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool no_repeats(string letters)
{

    for (int i = 0, j = strlen(letters); i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (toupper(letters[i]) == toupper(letters[k]))
            {
                return false;
            }
        }
    }
    return true;
}
