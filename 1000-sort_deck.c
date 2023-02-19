#include <stdlib.h>
#include "deck.h"

int card_value_to_num(const char *value);

/* Compare function for qsort */
int card_cmp(const void *a, const void *b)
{
    const card_t *ca = (*(const deck_node_t **)a)->card;
    const card_t *cb = (*(const deck_node_t **)b)->card;

    if (ca->kind != cb->kind)
        return (ca->kind - cb->kind);
    return (card_value_to_num(ca->value) - card_value_to_num(cb->value));
}

/* Helper function to convert card value to numerical rank */
int card_value_to_num(const char *value)
{
    if (strcmp(value, "2") == 0)
        return 2;
    else if (strcmp(value, "3") == 0)
        return 3;
    else if (strcmp(value, "4") == 0)
        return 4;
    else if (strcmp(value, "5") == 0)
        return 5;
    else if (strcmp(value, "6") == 0)
        return 6;
    else if (strcmp(value, "7") == 0)
        return 7;
    else if (strcmp(value, "8") == 0)
        return 8;
    else if (strcmp(value, "9") == 0)
        return 9;
    else if (strcmp(value, "10") == 0)
        return 10;
    else if (strcmp(value, "Jack") == 0)
        return 11;
    else if (strcmp(value, "Queen") == 0)
        return 12;
    else if (strcmp(value, "King") == 0)
        return 13;
    else if (strcmp(value, "Ace") == 0)
        return 14;
    else {
        fprintf(stderr, "Error: invalid card value %s\n", value);
        exit(1);
    }
}

/* Sorts a deck of cards */
void sort_deck(deck_node_t **deck)
{
    size_t i;
    deck_node_t *node_array[52];

    /* Store nodes in an array */
    for (i = 0; i < 52; i++)
    {
        node_array[i] = *deck;
        *deck = (*deck)->next;
    }

    /* Sort nodes in array */
    qsort(node_array, 52, sizeof(deck_node_t *), card_cmp);

    /* Rebuild deck using sorted nodes */
    *deck = node_array[0];
    (*deck)->prev = NULL;
    for (i = 1; i < 52; i++)
    {
        node_array[i]->prev = node_array[i-1];
        node_array[i-1]->next = node_array[i];
    }
    node_array[51]->next = NULL;
}
    
