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

int checkAdventurer(int p, struct gameState *post, int choice1, int choice2, int choice3, int handpos)
 {
 	int r, temp[MAX_HAND];
 	//new test gamestate
	struct gameState pre;
	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	//call Adventurer
	printf("at adventurer function call\n");
	printf("choice1: %d, choice2: %d, choice3: %d, handpos: %d, p: %d\n", choice1, choice2, choice3, handpos, p);
	r = Adventurer(choice1, choice2, choice3, post, handpos, p, &temp[MAX_HAND]);
	printf("after adventurer call\n");
	//check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
	asserttrue (r == 0);
    asserttrue(post->handCount[p] == pre.handCount[p]);
    asserttrue(post->deckCount[p] != pre.deckCount[p]);
    asserttrue(post->discardCount[p] == pre.discardCount[p]);
    asserttrue(post->playedCardCount == pre.playedCardCount);
    asserttrue(memcmp(&pre, post, sizeof(struct gameState)) != 0);
    printf("returning from check\n");
	return 0;
}

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos, n, i, j, p, numTreasureCards, prob;
	struct gameState pre;

	printf("Testing Adventurer Card\n");

	SelectStream(2);
	PutSeed(3);

	//randomize all values of parameters of Adventurer, then call checkAdventurer
	for (n = 0; n < 2000; n++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&pre)[i] = floor(Random() * 256);
		}
		//make sure at least 2 treasure cards are present at all times
		numTreasureCards = 2 + floor(Random() * MAX_HAND);
		
		prob = floor(Random() * MAX_DECK); //3 different treasure cards
		handpos = 1 + floor(Random() * 4);
		p = 1 + floor(Random() * 2);
		pre.deckCount[p] = floor(Random() * MAX_DECK);
    	pre.discardCount[p] = floor(Random() * MAX_DECK);
    	pre.handCount[p] = floor(Random() * MAX_HAND);
		for (j = 0; j < pre.handCount[p]; j++)
		{
			do
			{
				//random supply of treasure cards
				//checking for 1, 2, or 3 for 3 different treasure cards
				if (prob == 1)
				{
					pre.hand[p][j] = copper;
					--numTreasureCards;
				}
				else if (prob == 2)
				{
					pre.hand[p][j] = silver;
					--numTreasureCards;
				}
				else
				{
					pre.hand[p][j] = gold;
					--numTreasureCards;
				}
			}
			while (numTreasureCards > 0);

		}
		printf("calling checkAdventurer\n");
    	checkAdventurer(p, &pre, choice1, choice2, choice3, handpos);
    	printf("End round %d\n", n);
	}
	printf("TESTS COMPLETED\n");
	exit(0);
}