#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions.h"
#define LINE_MAX 28

// general table printing, only used at end
void printTable(int d, int p, int *dealerCards, int *playerCards){
    system("clear");
    printf("\n");
    printf("____________________________\n");
    printf("|                          |\n");
    printf("|  ");
    for (int i = 0; i < d; i++){
        if(dealerCards[i] == 11)      printf("J   ");
        else if(dealerCards[i] == 12) printf("Q   ");
        else if(dealerCards[i] == 13) printf("K   ");
        else if(dealerCards[i] == 1)  printf("A   ");
        else printf("%-2d  ", dealerCards[i]); 
    }
    for(int i = 0; i < LINE_MAX - 3 - (4 * d) - 1; i++){
        printf(" ");
    }

    printf("|\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|  ");
    
    for (int i = 0; i < p; i++){
        if(playerCards[i] == 11)      printf("J   ");
        else if(playerCards[i] == 12) printf("Q   ");
        else if(playerCards[i] == 13) printf("K   ");
        else if(playerCards[i] == 1)  printf("A   ");
        else printf("%-2d  ", playerCards[i]); 
    }
    for(int i = 0; i < LINE_MAX - 3 - (4 * p) - 1; i++){
        printf(" ");
    }
    printf("|\n");
    printf("|__________________________|\n");

    // can we clean this up
    // once cleaner, lets add a right edge to the table using strlen
}

void printHoleTable(int p, int *dealerCards, int *playerCards){
    system("clear");

    // top of table
    printf("Your turn\n");
    printf("____________________________\n");
    printf("|                          |\n");
    printf("|  ");

    // dealer card row
    if(*dealerCards == 11)      printf("J   ");
    else if(*dealerCards == 12) printf("Q   ");
    else if(*dealerCards == 13) printf("K   ");
    else if(*dealerCards == 1)  printf("A   ");
    else printf("%-2d  ", *dealerCards); 
    printf("?   "); // hole
    // spacing 
    for(int i = 0; i < LINE_MAX - 3 - (4 * 2) - 1; i++){
        printf(" ");
    }
    // middle of table
    printf("|\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|  ");

    // player card row
    for (int i = 0; i < p; i++){
        if(playerCards[i] == 11)      printf("J   ");
        else if(playerCards[i] == 12) printf("Q   ");
        else if(playerCards[i] == 13) printf("K   ");
        else if(playerCards[i] == 1)  printf("A   ");
        else printf("%-2d  ", playerCards[i]); 
    }
    for(int i = 0; i < LINE_MAX - 3 - (4 * p) - 1; i++){
        printf(" ");
    }
    printf("|\n");
    printf("|__________________________|\n");

    // can we clean this up
}

void printDealerTable(int d, int p, int *dealerCards, int *playerCards){
    system("clear");
    // vvv ONLY DIFFERENCE FROM NORMAL TABLE vvv
    printf("Dealer's Turn\n");
    printf("____________________________\n");
    printf("|                          |\n");
    printf("|  ");
    for (int i = 0; i < d; i++){
        if(dealerCards[i] == 11)      printf("J   ");
        else if(dealerCards[i] == 12) printf("Q   ");
        else if(dealerCards[i] == 13) printf("K   ");
        else if(dealerCards[i] == 1)  printf("A   ");
        else printf("%-2d  ", dealerCards[i]); 
    }
    // spacing 
    for(int i = 0; i < LINE_MAX - 3 - (4 * d) - 1; i++){
        printf(" ");
    }
    // middle of table
    printf("|\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|                          |\n");
    printf("|  ");

    // player card row
    for (int i = 0; i < p; i++){
        if(playerCards[i] == 11)      printf("J   ");
        else if(playerCards[i] == 12) printf("Q   ");
        else if(playerCards[i] == 13) printf("K   ");
        else if(playerCards[i] == 1)  printf("A   ");
        else printf("%-2d  ", playerCards[i]); 
    }
    for(int i = 0; i < LINE_MAX - 3 - (4 * p) - 1; i++){
        printf(" ");
    }
    printf("|\n");
    printf("|__________________________|\n");

    // can we clean this up
    // once cleaner, lets add a right edge to the table using strlen
}


////
/*
TITLE SCREEN
*/
///

void printTitle(){
    printf("\n\n");
    printf("////////////////////////////////////////////////////\n");
    printf("  ______               ____        ____              \n");
    printf("  |     \\   |         /    \\      /    \\    |  /  \n");
    printf("  |     |   |        /      \\    /      \\   | /    \n");
    printf("  |----<    |        |______|   |           |/       \n");
    printf("  |     \\   |        |      |   |           |\\     \n");
    printf("  |     |   |        |      |    \\      /   | \\    \n");
    printf("  |_____/   |______  |      |     \\____/    |  \\   \n");

    
    printf("     __________    ____        ____                 \n");
    printf("          |       /    \\      /    \\    |  /      \n");
    printf("          |      /      \\    /      \\   | /       \n");
    printf("          |      |______|   |           |/          \n");
    printf("          |      |      |   |           |\\         \n");
    printf("     |    |      |      |    \\      /   | \\       \n");
    printf("      \\___/      |      |     \\____/    |  \\     \n");
    printf("\n////////////////////////////////////////////////////\n\n");
    
    printf("Press ENTER to play... ");
}