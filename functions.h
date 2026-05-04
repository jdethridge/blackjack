#ifndef _FUNCTION_H_
#define _FUNCTION_H_

void printTitle();

void printHoleTable(int p, int *dealerCards, int *playerCards);
void printTable(int d, int p, int *dealerCards, int *playerCards);
void printDealerTable(int d, int p, int *dealerCards, int *playerCards);

int *dealCard(int *cards, int *currentCard);
void dealFirstHand(int *cards);

int totaling(int *cards, int *currentCard, int *total);

#endif