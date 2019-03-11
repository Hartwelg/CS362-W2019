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
	printf("choice1: %d, choice2: %d, choice3: %d, handpos: %d, p: %d\n", choice1, choice2, choice3, handpos, p);
	r = Feast(choice1, choice2, choice3, post, handpos, p);

	// check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
    asserttrue (r == 0);//make sure function returns

    //check that correct changes were made to gameState
    asserttrue(post->handCount[p] == pre.handCount[p]); //number of cards in hand should be same in both gamestates
    asserttrue(post->deckCount[p] == pre.deckCount[p]); //number of cards in deck should be same in both gamestates
    asserttrue(post->discardCount[p] != pre.discardCount[p]); //number of discarded cards should be different in both gamestates
    asserttrue(post->playedCardCount == pre.playedCardCount); //number of played cards should be different in both gamestates
    
	return 0;
}

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, i = 0, p = 0, q = 0;
	struct gameState pre;

	printf("Testing Feast Card\n");

	SelectStream(2);
	PutSeed(3);

	//randomize all values of parameters of Feast, then call checkFeast
	for (i = 0; i < 20000; i++)
	{
		
		//currentPlayer
		p = floor(Random() * 2);
		//randomize gameState
		pre.deckCount[p] = floor(Random() * MAX_DECK);
    	pre.discardCount[p] = floor(Random() * MAX_DECK);
    	pre.handCount[p] = floor(Random() * MAX_HAND);
		//three phases of the game
		pre.phase = 0 + floor(Random() * 3);
		pre.numActions = 0 + floor(Random() * MAX_DECK);

		//only choice1 is used for Feast, according to dominion.h
		choice1 = 0 + floor(Random() * 26);
		handpos = 1 + floor(Random() * 5);

		//making sure at least one of every card is available
		for (q = 0; q < 27; q++)
		{
			//using handpos just because it was a random value, didn't need to make another variable
			pre.supplyCount[q] = handpos;
		}

    	checkFeast(p, &pre, choice1, choice2, choice3, handpos);
    	printf("end round %d\n", i);
	}
	printf("TESTS COMPLETED\n");
	exit(0);
}