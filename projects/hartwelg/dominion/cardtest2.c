#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
    int newCards = 0;
    int discarded = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = check that two cards were added to hand --------------
	printf("TEST 1: choice1 = 1 = dig through deck to reveal treasure\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 2;
	printf("Testing that current player's hand gains 2 cards\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("Testing that other player's hand does not gain 2 cards\n");
	printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer] + discarded - newCards);
	asserttrue(G.handCount[thisPlayer] == testG.handCount[thisPlayer] + discarded - newCards);

	// // ----------- TEST 2: check that revealed cards are trashed from deck --------------
	// printf("TEST2: Number of revealed cards trashed from deck\n");
	// printf("current player's deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	// asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	// ----------- TEST 3: choice1 = 3 = trash two cards --------------

	printf("TEST 3: choice1 = 3 = trash two cards\n");
	choice1 = 3;

	// cycle through deck to find 2 treasure cards
	for (i=1; i<G.deckCount[thisPlayer]; i++) {
		for (j=i+1; j<G.deckCount[thisPlayer]; j++) {

			G.deck[thisPlayer][0] = copper;
			G.deck[thisPlayer][1] = remodel;
			G.deck[thisPlayer][2] = gold;
			G.deck[thisPlayer][3] = council_room;
			G.deck[thisPlayer][4] = gardens;

			// copy the game state to a test case
			memcpy(&testG, &G, sizeof(struct gameState));

			printf("starting cards: ");
			for (m=0; m<testG.deckCount[thisPlayer]; m++) {
				printf("(%d)", testG.deck[thisPlayer][m]);
			}
			printf("; ");

			choice2 = j;
			choice3 = i;
			remove1 = testG.deck[thisPlayer][i];
			remove2 = testG.deck[thisPlayer][j];
			cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

			printf("removed: (%d)(%d); ", remove1, remove2);
			printf("ending cards: ");

			// tests that the removed cards are no longer in the player's deck
			for (m=0; m<testG.deckCount[thisPlayer]; m++) {
				printf("(%d)", testG.deck[thisPlayer][m]);

				asserttrue(testG.deck[thisPlayer][m] != remove1);
				asserttrue(testG.deck[thisPlayer][m] != remove2);
			}
			printf(", expected: ");
			for (m=1; m<G.deckCount[thisPlayer]; m++) {
				if (G.deck[thisPlayer][m] != G.deck[thisPlayer][i] && G.deck[thisPlayer][m] != G.deck[thisPlayer][j]) {
					printf("(%d)", G.deck[thisPlayer][m]);
				}
			}
			printf("\n");

			// tests for the appropriate number of remaining cards
			newCards = 0;
			xtraCoins = 0;
			//----------------------------------------------------------------------------------------
			discarded = 0;
			if (i==1 && j==2) {
				printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
				printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
			}

			asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
			asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
		}
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}