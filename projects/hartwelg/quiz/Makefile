testme.o: testme.c
	gcc -c testme.c -std=c99

testme: testme.o
	gcc -o testme testme.o
	testme
clean:
	rm -f *.gcno *.o