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

    printf ("TESTING handCard():\n");
    
    printf("Adding 5 cards to player's hand\n");
        G.hand[thisPlayer][0] = copper;
        G.hand[thisPlayer][1] = remodel;
        G.hand[thisPlayer][2] = gold;
        G.hand[thisPlayer][3] = council_room;
        G.hand[thisPlayer][4] = gardens;

    printf("Testing that first card in hand is copper\n");
    asserttrue(G.hand[thisPlayer][0] == copper);

    printf("Testing that second card in hand is remodel\n");
    asserttrue(G.hand[thisPlayer][1] == remodel);

    printf("Testing that third card in hand is gold\n");
    asserttrue(G.hand[thisPlayer][2] == gold);

    printf("Testing that fourth card in hand is council room\n");
    asserttrue(G.hand[thisPlayer][3] == council_room);

    printf("Testing that fifth card in hand is gardens\n");
    asserttrue(G.hand[thisPlayer][4] == gardens);

    printf("Testing that there is no sixth card in hand\n");
    asserttrue(G.hand[thisPlayer][5] == copper);

    printf("All tests complete!\n");

    return 0;
}
