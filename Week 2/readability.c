#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Propmpt user for text input
    string text = get_string("Text: ");

    // Calculate # of Characters, Words & Sentances in text

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8); // Coleman-Liau index Calculation

    // Print out Grade level
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }

        else if (index > 16)
        {
            printf("Grade 16+\n");
        }

        else
        {
            printf("Grade %i\n", index);
        }
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
        if (isalpha(text[i])) // counting characters
        {
            letters++;
        }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == ' ') // counting words by counting spaces
        {
            words++;
        }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == '.' || text[i] == '?' ||
            text[i] == '!') // counting the number of sentances by counting . ? and !
        {
            sentences++;
        }
    return sentences;
}
