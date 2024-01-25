#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Counting of card suits.
 * @SPADE: a suit of Spades.
 * @HEART: a suit Hearts.
 * @CLUB: a suit of Clubs.
 * @DIAMOND: a suit Diamonds.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing cards
 *
 * @value: The value of a card
 * From "Ace" to "King"
 * @kind: The kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - The deck of card
 *
 * @card: The pointer to card of the node
 * @prev: A pointer to previous node on the list
 * @next: A pointer to the next node on the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
