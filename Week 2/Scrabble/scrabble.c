#include <cs50.h>
#include <ctype.h> // checks the type of data
#include <stdio.h>
#include <string.h> // lets us include string library and specifically spring length or strlen

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(int argc, string argv[]) // allows us to use arguments for intergers and strings
{
    // Prompt players for word - no numbers
    string player1 = get_string("Player 1, what is your word? ");
    string player2 = get_string("Player 2, what is your word? ");

    // Compute the score of each word
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);
    // Print which player has the higher score "Player 1 Wins!" "Player 2 Wins!" OR "Tie!"
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for word
    int score = 0; // start with a score of 0 that we can add to

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i])) // specify between uppercase letters and lowercase letters because we
                              // are going to use ASCii to change letters to numbers which we can
                              // add to our score
        {
            score =
                score + POINTS[word[i] - 'A']; // subtract the first character in the word from A
                                               // (example bat - B is ASCii 66 minus A ASCii 65.
                                               // 66-65=1 therefore it gets POINTS 1 (Start from 0))
        }
        else if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 'a']; // same as before but with lowercase
        }
    }
    return score;
}
