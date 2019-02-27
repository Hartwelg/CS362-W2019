CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestcard1: dominion.o randomtestcard1.c rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	# echo "randomtestcard1" >> randomtestcard1.out
	# ./randomtestcard1 >> randomtestcard1.out
	# gcov dominion.c -b >> randomtestcard1.out
	# cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2: dominion.o randomtestcard2.c rngs.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	# echo "randomtestcard2" >> randomtestcard2.out
	# ./randomtestcard2 >> randomtestcard2.out
	# gcov dominion.c -b >> randomtestcard2.out
	# cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer: dominion.o randomtestadventurer.c rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	# echo "randomtestadventurer" >> randomtestadventurer.out
	# ./randomtestadventurer >> randomtestadventurer.out
	# gcov dominion.c -b >> randomtestadventurer.out
	# cat dominion.c.gcov >> randomtestadventurer.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
all: playdom player 

unittestresults: dominion.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	
clean:
	rm -f *.o playdom.exe playdom player randomtestcard1 randomtestcard2 randomtestadventurer player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
