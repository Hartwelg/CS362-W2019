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

// /int gainCard(int supplyPos, struct gameState *state, int toFlag, int player)

  //added card for [whoseTurn] current player:
  // toFlag = 0 : add to discard
  // toFlag = 1 : add to deck
  // toFlag = 2 : add to hand
  //-----------------------------------------

    printf ("TESTING gainCard():\n");

    printf("Adding feast card to player's hand\n");
    gainCard(feast, &G, 2, thisPlayer);

    printf("Testing whether number of cards in hand was increased correctly\n");
    asserttrue(G.handCount[thisPlayer] == 1);
    asserttrue(G.hand[thisPlayer][0] == feast);

    printf("Adding steward and smithy cards to hand\n");
    gainCard(steward, &G, 2, thisPlayer);
    gainCard(smithy, &G, 2, thisPlayer);

    printf("Testing whether both cards were correctly added to hand\n");
    asserttrue(G.handCount[thisPlayer] == 3);

    printf("Adding adventurer card to player's deck\n");
    gainCard(adventurer, &G, 1, thisPlayer);
    asserttrue(G.deckCount[thisPlayer] == 1);

    printf("All tests complete!\n");

    return 0;
}
