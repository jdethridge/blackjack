#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "functions.h"

int main(){
    system("clear");

    // title screen
    printTitle();
    char c[20];
    fgets(c, 20, stdin); // click anything to continue?
    system("clear"); 

    // memory management, variable assignments
    int playerTotal = 0;
    int dealerTotal = 0;
    int playerCurrentCard = 2;
    int dealerCurrentCard = 2;
    int *playerCards = malloc(playerCurrentCard * sizeof(int));
    int *dealerCards = malloc(dealerCurrentCard * sizeof(int));
    
    // dealing
    srand(time(NULL));
    dealFirstHand(playerCards);
    playerTotal = totaling(playerCards, &playerCurrentCard, &playerTotal);
    dealFirstHand(dealerCards);
    dealerTotal = totaling(dealerCards, &dealerCurrentCard, &dealerTotal);
    
    printHoleTable(playerCurrentCard, dealerCards, playerCards);     // FIXME, i want the hole to be hidden

    // game play
    while(playerTotal < 21){
        char answer;
        printf("\nHit or stay? (h / s): ");
        scanf(" %c", &answer);
        if(answer == 's' || answer == 'l') break;

        playerCards = dealCard(playerCards, &playerCurrentCard);
        playerTotal = totaling(playerCards, &playerCurrentCard, &playerTotal);

        if(playerTotal > 21) {
            printTable(dealerCurrentCard, playerCurrentCard, dealerCards, playerCards);
            printf("\nBust!\n\n");
            // printf("player: %d\ndealer: %d\n", playerTotal, dealerTotal); // FOR TESTING
        return 0;
        }

        printHoleTable(playerCurrentCard, dealerCards, playerCards);
    }

    printDealerTable(dealerCurrentCard, playerCurrentCard, dealerCards, playerCards);
    sleep(1);

    // house rules, must hit below 17
    while(dealerTotal < 17) {
        dealerCards = dealCard(dealerCards, &dealerCurrentCard);
        dealerTotal = totaling(dealerCards, &dealerCurrentCard, &dealerTotal);

        printDealerTable(dealerCurrentCard, playerCurrentCard, dealerCards, playerCards);
        sleep(1);
    }

    // aggressive dealer, just want to beat player 1 out of 1
    while(dealerTotal < playerTotal) {
        dealerCards = dealCard(dealerCards, &dealerCurrentCard);
        dealerTotal = totaling(dealerCards, &dealerCurrentCard, &dealerTotal);

        printDealerTable(dealerCurrentCard, playerCurrentCard, dealerCards, playerCards);
        sleep(1);
    }

    // results
    printTable(dealerCurrentCard, playerCurrentCard, dealerCards, playerCards);
    if(dealerTotal > 21 || playerTotal > dealerTotal) printf("\nYou Win!\n\n");
    else printf("\nYou lose!\n\n");

    // printf("player: %d\ndealer: %d\n", playerTotal, dealerTotal);  // FOR TESTING

    free(playerCards);
    free(dealerCards);

    //hello , testing
    return 0;
}

