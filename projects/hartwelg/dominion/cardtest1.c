#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int main() {
    int newCards = 0;
    int discarded = 0;
    int xtraCoins = 0;
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

	// ----------- TEST 1: choice1 = 1 = +3 cards --------------
	printf("TEST 1: choice1 = 1 = +3 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 3;
	xtraCoins = 0;
	printf("current player's hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	asserttrue(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("other player's hand count = %d, expected = %d\n", G.handCount[thisPlayer], testG.handCount[thisPlayer] + discarded - newCards);
	asserttrue(G.handCount[thisPlayer] == testG.handCount[thisPlayer] + discarded - newCards);

	// ----------- TEST 2: Cards come from current player's deck --------------
	printf("current player's deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	asserttrue(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("other player's deck count = %d, expected = %d\n", G.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	asserttrue(G.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

	// ----------- TEST 3: no state change for other players, state change for current player--------------
	printf("Testing that current player has played a card\n");
	asserttrue(testG.playedCardCount == 1);

	printf("Testing that other player has not played a card\n");
	asserttrue(G.playedCardCount == 0);

	// ----------- TEST 4: no coins gained for current or other player--------------
	printf("Testing that no coins are added for current player\n");
	asserttrue(testG.coins == G.coins + xtraCoins);

	printf("Testing that no coins are added for other player\n");
	asserttrue(G.coins == G.coins + xtraCoins);
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}