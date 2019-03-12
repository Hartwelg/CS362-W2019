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

int checkAdventurer(int p, struct gameState *post, int handpos, int temp[MAX_HAND])
 {
	int choice1, choice2, choice3;
 	int r;
 	//new test gamestate
	struct gameState pre;
	//struct gameState *pre = malloc(sizeof(struct gameState));	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	//call Adventurer
	printf("at adventurer function call\n");
	printf("handpos: %d, p: %d\n", handpos, p);

	r = Adventurer(adventurer, choice1, choice2, choice3, post, handpos, p);
	
	printf("after adventurer call\n");
	//check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
	asserttrue (r == 0);
    asserttrue(post->handCount[p] == pre.handCount[p]);
    asserttrue(post->deckCount[p] != pre.deckCount[p]);
    asserttrue(post->discardCount[p] == pre.discardCount[p]);
    asserttrue(post->playedCardCount == pre.playedCardCount);

    printf("returning from check\n");
	return 0;
}

int main()
{
	int handpos, n = 0, p, prob = 0, i, r;
	
	struct gameState pre;
	// struct gameState *pre = malloc(sizeof(struct gameState));

	printf("Testing Adventurer Card\n");

	SelectStream(2);
	PutSeed(3);

	//randomize all values of parameters of Adventurer, then call checkAdventurer
	for (n = 0; n < 2000; n++)
	{
		handpos = 1 + floor(Random() * 5);
		p = 1 + floor(Random() * 2);

		pre.deckCount[p] = MAX_DECK;
		// pre->deckCount[p] = 1 + floor(Random() * MAX_DECK + 1);
    	pre.discardCount[p] = 0 + floor(Random() * MAX_DECK + 1);
    	pre.handCount[p] = 0 + floor(Random() * MAX_HAND + 1);
		//printf("handCount: %d\n", pre->handCount[p]);

		//three phases in the game
		pre.phase = 0 + floor(Random() * 3);
		int *temp = malloc(sizeof(int) * pre.handCount[p]);
		//make sure at least 2 treasure cards are present at all times
    	pre.supplyCount[gold] = 2 + floor(Random() * MAX_DECK);
    	pre.supplyCount[silver] = 2 + floor(Random() * MAX_DECK);
    	pre.supplyCount[copper] = 2 + floor(Random() * MAX_DECK);

		//put treasure cards in random places in hand
		for (i = 0; i < 4; i++)
		{
			prob = floor(Random() * pre.handCount[p]);

			pre.hand[p][prob] = copper + floor(Random() * 2);
		}

		// printf("calling Adventurer\n");
		// printf("handpos: %d, p: %d\n", handpos, p);
		// Adventurer(pre, handpos, p, &temp[MAX_HAND]);

		// printf("calling checkAdventurer\n");
    	checkAdventurer(p, &pre, handpos, &temp[MAX_HAND]);
    	printf("End round %d\n", n);
	}
	printf("TESTS COMPLETED\n");
	exit(0);
}