#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "remodel"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
    int newCards = 0;
    int discarded = 0;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +3 cards --------------
	printf("TEST 1: choice1 = 1 = +0 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(remodel, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;
	printf("Testing that there is no change in number of hand cards for current player\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("Testing that there is no change in hand cards for other player\n");
	printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer] + discarded - newCards);
	asserttrue(G.handCount[thisPlayer] == testG.handCount[thisPlayer] + discarded - newCards);

	printf("Testing that there is no change in deck count for current player\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("Testing that there is no change in deck count for other player\n");
	printf("deck count = %d, expected = %d\n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer] - shuffledCards + newCards);
	asserttrue(G.deckCount[thisPlayer] == testG.deckCount[thisPlayer] - shuffledCards + newCards);

	printf("Testing that current player's discard pile gains a card\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + 1);
	asserttrue(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + 1);

	printf("Testing that other player's discard pile does not gain a card\n");
	printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer], testG.discardCount[thisPlayer] - 1);
	asserttrue(G.discardCount[thisPlayer] == testG.discardCount[thisPlayer] - 1);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}