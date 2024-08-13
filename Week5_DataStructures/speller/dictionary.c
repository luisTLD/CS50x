// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

#define BUFFER_SIZE 4096

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100;
int totalHash = 0;

// Hash table
node *table[N];
void addHash(node *newNode, int index);
void unload_aux(node *aux);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    bool verify = false;
    unsigned int index = hash(word);
    node *aux = table[index];

    while (aux != NULL)
    {
        if (!strcasecmp(aux->word, word))
        {
            verify = true;
            aux = NULL;
        }
        else aux = aux->next;
    }

    return verify;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int index = 0;
    int sum = 0;
    while (word[index])
    {
        sum += toupper(word[index++]);
    }

    return sum % 100;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL) return false;

    char buffer[BUFFER_SIZE];
    int bytesRead = 0;

    // Read each word in the file with blocks
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        buffer[bytesRead] = '\0';

        char *line = strtok(buffer, "\n");
        while (line != NULL) {
            node *newNode = (node*)malloc(1 * sizeof(node));
            newNode->next = NULL;

            if (newNode == NULL)
            {
                fclose(source);
                return false;
            }

            strcpy(newNode->word, line);
            unsigned int index = hash(line);
            addHash(newNode, index);

            line = strtok(NULL, "\n");
        }
    }

    // Close the dictionary file
    fclose(source);

    return true;
}

void addHash(node *newNode, int index)
{
    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        newNode->next = table[index];
        table[index] = newNode;
    }

    totalHash++;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return totalHash;
}

// Unloads dictionary from memory, returning true if successful, else false
void unload_aux(node *aux)
{
    if (aux != NULL)
    {
        unload_aux(aux->next);
        free(aux);
        totalHash--;
    }
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        unload_aux(table[i]);
    }

    return true;
}

