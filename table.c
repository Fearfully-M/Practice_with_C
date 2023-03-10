#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *phrase;
    struct node *next;
}
node;

node *table[26];

int hash (char *phrase);

int main (void)
{
    char *phrase = NULL;
    size_t buffer = 0;

    for (int i = 0; i < 3; i++)
    {
        printf("Enter a new phrase: ");
        getline(&phrase, &buffer, stdin);
        int index = hash(phrase);
        printf("%s hashes to %i\n", phrase, index);
    }

    free(phrase);
}

//TODO: return an index, 0-25, for a given phrase
int hash(char *phrase)
{
    return toupper(phrase[0]) - 'A';
    //A = 65
    //A - A = 0
    //B - A = 1
    //Z - A = 25
}