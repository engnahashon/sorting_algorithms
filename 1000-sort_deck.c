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
    if (value[0] >= '2' && value[0] <= '9')
        return value[0] - '0';
    switch (value[0])
    {
        case 'A': return 1;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        default: return 0;
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
    
