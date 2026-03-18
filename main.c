#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display card name
void printCard(int card) {
    if (card == 11) printf("Jack");
    else if (card == 12) printf("Queen");
    else if (card == 13) printf("King");
    else if (card == 14) printf("Ace");
    else printf("%d", card);
}

int main() {
    int money = 100;
    int bet;
    int card1, card2, card3;

    srand(time(NULL)); // initialize random

    printf("\n\tACEY DUCEY CARD GAME\n");
    printf("====================================\n");

    while (money > 0) {
        printf("\nYou have %d dollars\n", money);

        // Generate two different cards
        do {
            card1 = (rand() % 13) + 2;
            card2 = (rand() % 13) + 2;
        } while (card1 >= card2);

        printf("\nHere are your two cards:\n");
        printCard(card1);
        printf("  ");
        printCard(card2);
        printf("\n");

        // Ask for bet
        printf("Enter your bet (0 to skip): ");
        scanf("%d", &bet);

        if (bet == 0) {
            printf("You chose not to bet.\n");
            continue;
        }

        if (bet < 0 || bet > money) {
            printf("Invalid bet!\n");
            continue;
        }

        // Draw third card
        card3 = (rand() % 13) + 2;

        printf("Third card is: ");
        printCard(card3);
        printf("\n");

        // Check win or lose
        if (card3 > card1 && card3 < card2) {
            printf("You WIN!\n");
            money += bet;
        } else {
            printf("You LOSE!\n");
            money -= bet;
        }
    }

    printf("\nGame over! You are out of money.\n");

    return 0;
}