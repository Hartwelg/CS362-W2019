#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define TESTCARD "adventurer"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int checkAdventurer(int p, struct gameState *post, int handpos)
 {
 	// int r, temp[MAX_HAND];
 	//new test gamestate
	struct gameState pre;
	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	//call Adventurer
	printf("at adventurer function call\n");
	printf("handpos: %d, p: %d\n", handpos, p);
	//r = Adventurer(post, handpos, p, &temp[MAX_HAND]);
	printf("after adventurer call\n");
	//check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
	// asserttrue (r == 0);
    asserttrue(post->handCount[p] == pre.handCount[p]);
    asserttrue(post->deckCount[p] != pre.deckCount[p]);
    asserttrue(post->discardCount[p] == pre.discardCount[p]);
    asserttrue(post->playedCardCount == pre.playedCardCount);

    printf("returning from check\n");
	return 0;
}

int main()
{
	int handpos, n = 0, p, temp[1000000];
	struct gameState pre;

	printf("Testing Adventurer Card\n");

	SelectStream(2);
	PutSeed(3);

	//randomize all values of parameters of Adventurer, then call checkAdventurer
	for (n = 0; n < 2000; n++)
	{
		handpos = 1 + floor(Random() * 5);
		p = 1 + floor(Random() * 2);
		pre.deckCount[p] = floor(Random() * MAX_DECK + 1);
    	pre.discardCount[p] = floor(Random() * MAX_DECK + 1);
    	pre.handCount[p] = floor(Random() * MAX_HAND + 1);

		// pre.discardCount[p] = pre.deckCount[p];
		// pre.handCount[p] = pre.deckCount[p];

		pre.phase = 0 + floor(Random() * 3);
		pre.numActions = 0 + floor(Random() * MAX_DECK);

		//make sure at least 2 treasure cards are present at all times
    	pre.supplyCount[gold] = 2 + floor(Random() * MAX_DECK);
    	pre.supplyCount[silver] = 2 + floor(Random() * MAX_DECK);
    	pre.supplyCount[copper] = 2 + floor(Random() * MAX_DECK);
		// pre.supplyCount[gold] = 2;
		// pre.supplyCount[silver] = 2;
		// pre.supplyCount[copper] = 2;

		// // //making sure at least one of every card is available
		// // for (q = 0; q < 27; q++)
		// // {
		// // 	//using handpos just because it was a random value, didn't need to make another variable
		// // 	pre.supplyCount[q] = handpos;
		// // }

		printf("calling Adventurer\n");
		printf("handpos: %d, p: %d\n", handpos, p);
		Adventurer(&pre, handpos, p, &temp[MAX_HAND]);

		// printf("calling checkAdventurer\n");
    	// checkAdventurer(p, &pre, choice1, choice2, choice3, handpos);
    	printf("End round %d\n", n);
	}
	printf("TESTS COMPLETED\n");
	exit(0);
}