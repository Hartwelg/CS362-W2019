#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  int random = rand();
  char character = 32 + (random % 94);
  return character;
}

char *inputString()
{
    int random = rand();
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    char randomString[5];
    char randChar;
    while (i <= 5)
    {
      do
      {
        random = rand();
        randChar = alpha[random % 26 - 1];
      }
      while (randChar == randomString[i]);
      randomString[i] = randChar;
      i++;
    }
    randomString[5] = '\0';
   return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int random = rand();

    // const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    // int i = 0;
    // char *randomString;
    // char randChar;
    // while (i <= 10)
    // {
    //   do
    //   {
    //     random = rand();
    //     randChar = alpha[random % 26 - 1];
    //   }
    //   while (randChar == randomString[i]);
    //   // randomString[i] = randChar;
    //   sprintf(randomString, "%s%c", randomString, randChar);
    //   i++;
    // }

    testme();
    return 0;
}
