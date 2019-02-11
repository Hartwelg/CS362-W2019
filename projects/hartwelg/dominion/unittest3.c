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

    printf ("TESTING numHandCards():\n");

         G.hand[thisPlayer][0] = steward;
         G.hand[thisPlayer][1] = copper;
         G.hand[thisPlayer][2] = duchy;
         G.hand[thisPlayer][3] = estate;
         G.hand[thisPlayer][4] = feast;

         printf("Testing that player has 5 cards in hand\n");
         asserttrue(G.handCount[thisPlayer] == 5);
         
         printf("Removing 2 cards from player's hand\n");
         discardCard(1, thisPlayer, &G, 1);
         discardCard(4, thisPlayer, &G, 1);

         printf("Testing that player has 3 cards in hand\n");
         asserttrue(G.handCount[thisPlayer] == 3);

         printf("Removing last 3 cards from player's hand\n");
         discardCard(0, thisPlayer, &G, 1);
         discardCard(2, thisPlayer, &G, 1);
         discardCard(3, thisPlayer, &G, 1);

         printf("Testing that player has 0 cards in hand\n");
         asserttrue(G.handCount[thisPlayer] == 0);

         printf("Removing card from empty hand\n");
         discardCard(5, thisPlayer, &G, 1);

         printf("Testing if player still has 0 cards in hand\n");
         asserttrue(G.handCount[thisPlayer] == 0);

    printf("All tests completed!\n");

    return 0;
}
