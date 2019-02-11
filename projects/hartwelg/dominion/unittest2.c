#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf ("TESTING discardCard():\n");
    
        printf("Adding 5 cards to player's hand\n");
        G.hand[thisPlayer][0] = copper;
        G.hand[thisPlayer][1] = remodel;
        G.hand[thisPlayer][2] = gold;
        G.hand[thisPlayer][3] = council_room;
        G.hand[thisPlayer][4] = gardens;

        printf("Testing for player not having 6 cards\n");
        asserttrue(G.handCount[thisPlayer] != 6);

        printf("Player has 5 cards in hand\n");
        asserttrue(G.handCount[thisPlayer] == 5);

        printf("Removing 1 card\n");
        discardCard(0, thisPlayer, &G, 1);

        printf("Player has 4 cards in hand\n");
        asserttrue(G.handCount[thisPlayer] == 4);

        printf("Removing 1 card\n");
        discardCard(1, thisPlayer, &G, 1);

        printf("Player has 3 cards in hand\n");
        asserttrue(G.handCount[thisPlayer] == 3);

        printf("Removing 1 card\n");
        discardCard(2, thisPlayer, &G, 1);

        printf("Player has 2 cards in hand\n");
        asserttrue(G.handCount[thisPlayer] == 2);

        printf("Removing 1 card\n");
        discardCard(3, thisPlayer, &G, 1);

        printf("Player has 1 card in hand\n");
        asserttrue(G.handCount[thisPlayer] == 1);

        printf("Removing 1 card\n");
        discardCard(4, thisPlayer, &G, 1);

        printf("Player has 0 cards in hand\n");
        asserttrue(G.handCount[thisPlayer] == 0);

        printf("Removing 1 card, testing that hand does not have < 0 cards\n");
        discardCard(4, thisPlayer, &G, 1);
        asserttrue(G.handCount[thisPlayer] != -1);

    printf("All tests complete!\n");

    return 0;
}
