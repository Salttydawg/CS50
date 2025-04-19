// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// counting the words inside of load function - Then having size output the correct word count
unsigned int count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash the word to obtain its hash value
    int index = hash(word);

    node *current = table[index];
    // Search the hash table at the location specified by the word's hash value
    while (current != NULL)
    {
        // if the word is found
        if (strcasecmp(current->word, word) == 0)
        {
            // return true
            return true;
        }
        current = current->next;
    }
    // Return false if no word is found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Getting the first letter and converting to lower for case insensitivity
    char first_char = tolower(word[0]);

    // Get length of word
    unsigned int length = strlen(word);

    return ((first_char - 'a') + length) % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    // read each word in the file one at a time loop through each word
    while ((fscanf(source, "%s", word)) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(source);
            return false;
        }
        // hash word to obtain a hash value (call on the unmade hash function)
        strcpy(n->word, word);
        // Add each word to the hash table (Hash table is an array of linked lists)
        int index = hash(word);
        n->next = table[index];
        table[index] = n;

        count++;
    }
    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];

        while (current != NULL)
        {
            node *tmp = current;
            current = current->next;
            free(tmp);
        }
    }

    return true;
}
