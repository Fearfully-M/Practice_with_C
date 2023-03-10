#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *phrase;
    struct node *next;
}
node;

#define LIST_SIZE 2

void unload(node *list);
void visualize(node *list);

int main (void)
{
    node *list = NULL;
    char *phrase = NULL;
    size_t buffer = 0;

    //Add items to the list
    for (int i = 0; i <LIST_SIZE; i++)
    {
        printf("Enter a new phrase: ");
        getline(&phrase, &buffer, stdin);

        //TODO: add a phrase to new node in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Couldn't allocate memory for node");
            return 1;
        }

        n->phrase = phrase;
        n->next = list;

        list = n;

        //visualize list after adding a node
        visualize(list);
    }

    unload(list);
    free(phrase);
}

void unload(node *list)
{
    //written as a while loop
    /* while (list != NULL)
    {
        node *ptr = list->next;
        free(list);
        list = ptr;
    } */

    //Free all allocated nodes
    //written recursively

    //base case
    if (list == NULL)
    {
        return;
    }
    else
    {
        node *ptr = list->next;
        free(list);
        list = ptr;
        unload(list);
    }
}

void visualize(node *list)
{
    //show to the console the nodes
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\n", list);
        printf("Phrase: \"%s\"\n", list->phrase);
        printf("Next: %p\n\n", list->next);
        list = list->next;
    }
    
    printf("+---------------------+\n\n");
}