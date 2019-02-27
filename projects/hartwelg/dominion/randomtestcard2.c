#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define DEBUG 0
#define NOISY_TEST 1

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int checkFeast(int p, struct gameState *post, int choice1, int choice2, int choice3, int handpos)
 {
 	int r;
 	//new test gamestate
	struct gameState pre;
	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	//call Feast
	r = Feast(choice1, choice2, choice3, post, handpos, p);

	// check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
    asserttrue (r == 0);
    asserttrue(post->hand[p][handpos] != pre.hand[p][handpos]);
    asserttrue(post->handCount[p] == pre.handCount[p]);
    asserttrue(post->deckCount[p] == pre.deckCount[p]);
    asserttrue(post->discardCount[p] == pre.discardCount[p]);
    asserttrue(post->playedCardCount == pre.playedCardCount);

    asserttrue(memcmp(&pre, post, sizeof(struct gameState)) == 1);
	return 0;
}

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos, n, i, p;
	struct gameState pre;

	printf("Testing Feast Card\n");

	SelectStream(2);
	PutSeed(3);

	//randomize all values of parameters of Feast, then call checkFeast
	for (n = 0; n < 2000; n++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&pre)[i] = floor(Random() * 256);
		}
		choice1 = floor(Random() * 2);
		choice2 = floor(Random() * 2);
		choice3 = floor(Random() * 2);

		handpos = floor(Random() * 5);
		//currentPlayer
		p = floor(Random() * 2);
		//randomize gameState
		pre.deckCount[p] = floor(Random() * MAX_DECK);
    	pre.discardCount[p] = floor(Random() * MAX_DECK);
    	pre.handCount[p] = floor(Random() * MAX_HAND);

    	checkFeast(p, &pre, choice1, choice2, choice3, handpos);
	}
	printf("TESTS COMPLETED\n");
	exit(0);
}