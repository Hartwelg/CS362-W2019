#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

#define TESTCARD "remodel"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int checkRemodel(int p, struct gameState *post, int choice1, int choice2, int choice3, int handpos)
 {
 	int r;
 	//new test gamestate
	struct gameState pre;
	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	printf("memcpy done\n");
	//call Feast
	r = Remodel(choice1, choice2, choice3, post, handpos, p);
	printf("function run\n");
	//check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
	asserttrue (r == 0);//check that function returns
	//check that correct changes were made to gameState
	asserttrue(post->hand[p][handpos] != pre.hand[p][handpos]); //card in handpos should be different between gamestates
    asserttrue(post->handCount[p] == pre.handCount[p]); //number of cards in hand should be the same between gamestates (one trashed, one gained)
    asserttrue(post->deckCount[p] == pre.deckCount[p]); //number of cards in deck should be the same between gamestates
    asserttrue(post->discardCount[p] == pre.discardCount[p] + 1); //number of discarded cards in post should be equal to # cards in pre + 1
    asserttrue(post->playedCardCount == pre.playedCardCount + 1); //number of played cards should be the same between gamestates
    
    asserttrue(memcmp(&pre, post, sizeof(struct gameState)) == 1);//check whether gamestates match
	return 0;
}

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos, n, i, p;
	struct gameState pre;

	printf("Testing Remodel Card\n");

	SelectStream(2);
	PutSeed(3);

	//randomize all values of parameters of Remodel, then call checkRemodel
	for (n = 0; n < 2000; n++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&pre)[i] = floor(Random() * 256);
		}
		//choice1 and choice2 are used for Remodel, according to dominion.h
		choice1 = 1 + floor(Random() * 5);
		choice2 = 1 + floor(Random() * 5);

		handpos = 1 + floor(Random() * 5);
		p = 1 + floor(Random() * 2);
		pre.deckCount[p] = floor(Random() * MAX_DECK);
    	pre.discardCount[p] = floor(Random() * MAX_DECK);
    	pre.handCount[p] = floor(Random() * MAX_HAND);

    	checkRemodel(p, &pre, choice1, choice2, choice3, handpos);
    	printf("end round %d\n", n);
	}
	printf("TESTS COMPLETED\n");
	exit(0);
}