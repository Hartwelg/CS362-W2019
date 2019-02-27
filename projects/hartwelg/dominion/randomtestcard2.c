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

// int main () {

//   int i, n, r, p, deckCount, discardCount, handCount;

//   int k[10] = {adventurer, council_room, feast, gardens, mine,
// 	       remodel, smithy, village, baron, great_hall};

//   struct gameState G;

//   printf ("Testing Feast.\n");

//   printf ("RANDOM TESTS.\n");

//   SelectStream(2);
//   PutSeed(3);

//   for (n = 0; n < 2000; n++) {
//     for (i = 0; i < sizeof(struct gameState); i++) {
//       ((char*)&G)[i] = floor(Random() * 256);
//     }
//     p = floor(Random() * 2);
//     G.deckCount[p] = floor(Random() * MAX_DECK);
//     G.discardCount[p] = floor(Random() * MAX_DECK);
//     G.handCount[p] = floor(Random() * MAX_HAND);
//     checkFeast(p, &G);
//   }

//   printf ("ALL TESTS OK\n");

//   exit(0);

//   printf ("SIMPLE FIXED TESTS.\n");
//   for (p = 0; p < 2; p++) {
//     for (deckCount = 0; deckCount < 5; deckCount++) {
//       for (discardCount = 0; discardCount < 5; discardCount++) {
// 	for (handCount = 0; handCount < 5; handCount++) {
// 	  memset(&G, 23, sizeof(struct gameState)); 
// 	  r = initializeGame(2, k, 1, &G);
// 	  G.deckCount[p] = deckCount;
// 	  memset(G.deck[p], 0, sizeof(int) * deckCount);
// 	  G.discardCount[p] = discardCount;
// 	  memset(G.discard[p], 0, sizeof(int) * discardCount);
// 	  G.handCount[p] = handCount;
// 	  memset(G.hand[p], 0, sizeof(int) * handCount);
// 	  checkFeast(p, &G);
// 	}
//       }
//     }
//   }

//   return 0;
// }
int checkFeast(int p, struct gameState *post, int choice1, int choice2, int choice3, int handpos, int currentPlayer)
 {
 	int r;
 	//new test gamestate
	struct gameState pre;
	//copy passed in gamestate to new one
	memcpy (&pre, post, sizeof(struct gameState));
	//call Feast
	r = Feast(choice1, choice2, choice3, post, handpos, currentPlayer);

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
  asserttrue (r == 0);

//   asserttrue(memcmp(&pre, post, sizeof(struct gameState)) == 0);
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

		handpos = floor(Random() * 5);
		p = floor(Random() * 2);
		currentPlayer = floor(Random() * p);
		pre.deckCount[p] = floor(Random() * MAX_DECK);
    	pre.discardCount[p] = floor(Random() * MAX_DECK);
    	pre.handCount[p] = floor(Random() * MAX_HAND);

    	checkFeast(p, &pre, choice1, choice2, choice3, handpos, currentPlayer);
	}
}