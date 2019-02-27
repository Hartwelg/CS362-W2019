#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "remodel"

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);

int checkRemodel(int p, struct gameState *post, int choice1, int choice2, int choice3, int handpos, int currentPlayer)
 {
 	int r;
 	//new test gamestate
	struct gameState pre;
	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	//call Feast
	Feast(choice1, choice2, choice3, &post, handpos, currentPlayer);

	

	// //check all values (parameters) in passed in gamestate (post) against control gamestate (pre)
	// if (post.deckCount[p] > 0)
	// {
	//     post.handCount[p]++;
	//     post.hand[p][pre.handCount[p]-1] = post.deck[p][post.deckCount[p]-1];
	//     post.deckCount[p]--;
	// } 
	// else if (post.discardCount[p] > 0)
	// {
	//     memcpy(post.deck[p], post->deck[p], sizeof(int) * post.discardCount[p]);
	//     memcpy(post.discard[p], post->discard[p], sizeof(int)*post.discardCount[p]);
	//     post.hand[p][post->handCount[p]-1] = post->hand[p][post->handCount[p]-1];
	//     post.handCount[p]++;
	//     post.deckCount[p] = post.discardCount[p]-1;
	//     post.discardCount[p] = 0;
	// }

	//put assertions here
	return 0;
}

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos, currentPlayer, n, i, p;
	struct gameState pre;

	printf("Testing Feast Card\n");

	SelectStream(2);
	PutSeed(3);

	currentPlayer = whoseTurn(&pre);
	//randomize all values of parameters of Feast, then call checkFeast
	for (n = 0; n < 2000; n++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&pre)[i] = floor(Random() * 256);
		}
		// choice1 = floor(random() * 3);
		// choice2 = floor(random() * 3);
		// choice3 = floor(random() * 3);

		handpos = floor(random() * 5);
		p = floor(Random() * 2);
		currentPlayer = floor(random() * p);
		pre.deckCount[p] = floor(Random() * MAX_DECK);
    	pre.discardCount[p] = floor(Random() * MAX_DECK);
    	pre.handCount[p] = floor(Random() * MAX_HAND);

    	checkRemodel(p, &pre, choice1, choice2, choice3, handpos, currentPlayer);
	}
}