#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "feast"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
    int newCards = 0;
    int discarded = 0;
    //int xtraCoins = 0;
    int shuffledCards = 0;

    //int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +0 cards --------------
	printf("TEST 1: choice1 = 1 = +0 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(feast, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 0;

	printf("Testing that current player's hand count has changed\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("Testing thatcurrent player's deck count has not changed\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("Testing that a card has been put in the current player's discard pile\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + 1);
	asserttrue(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + 1);

	printf("Testing that other player's hand count has not changed\n");
	printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer] + discarded - newCards);
	asserttrue(G.handCount[thisPlayer] == testG.handCount[thisPlayer] + discarded - newCards);

	printf("Testing that other player's deck count has not changed\n");
	printf("deck count = %d, expected = %d\n", G.deckCount[thisPlayer], testG.deckCount[thisPlayer] + shuffledCards - newCards);
	asserttrue(G.deckCount[thisPlayer] == testG.deckCount[thisPlayer] + shuffledCards - newCards);

	printf("Testing that a card has not been put in the other player's discard pile\n");
	printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer], testG.discardCount[thisPlayer] - 1);
	asserttrue(G.discardCount[thisPlayer] == testG.discardCount[thisPlayer] - 1);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}


