#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions.h"

int *dealCard(int *cards, int *currentCard){
    (*currentCard) ++;
    cards = realloc(cards, (*currentCard) * sizeof(int));
    
    srand(time(NULL));
    *(cards + *currentCard - 1) = rand() % 13 + 1;

    return cards;
}

void dealFirstHand(int *cards){
    *(cards) = rand() % 13 + 1;
    *(cards + 1) = rand() % 13 + 1;
}

int totaling(int *cards, int *currentCard, int *total){
    *total = 0;

    for(int i = 0; i < *currentCard; i ++){
        if(cards[i] > 1 && cards[i] < 11) {
            (*total) += cards[i];
        } 
        else if(cards[i] > 10) {
            (*total) += 10;
        }
    }
    for(int i = 0; i < *currentCard; i ++){
        if((cards[i] == 1) && ((*total) + 11 <= 21)) {
            (*total) += 11;
        }
        else if((cards[i] == 1) && ((*total) + 11 > 21)){
            (*total) += 1;
        }
    }

    return *total;
}