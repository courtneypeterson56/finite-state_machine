#include <stdio.h>
#include <stdlib.h>

/*
Courtney Peterson
Computer Systems PART D

This FSM has 2 states: in the pattern (IN) and out of the
pattern (OUT).
String-matching consists of finding at least one of the occurrences of
a string (more generally called a pattern) in a larger text. In this program, the text has n characters
in length (unknown before execution), while the pattern has length of m
characters (again unknown), where m is less than or equal to n. Both character
strings consist of a finite set of characters and will be limited to the standard
letters in the English alphabet.
*/

char * getCharBlock();
int findMatch(char * text, char *pattern, int patsize);
int sizeOf(char * ptr);
void printIt(char * ptr, int index, int size);


int main() {
  char *text, *pattern; //pointers for the characters you will read
  char *p, *q, *r; //pointer variables
  int n, m, x, y;  //integers
  int patsize;
  int textsize;
  int i;

  printf("Input text : \t" );
  text = getCharBlock();
  printf("Input pattern: \t");
  pattern = getCharBlock();
  textsize = sizeOf(text);
  patsize = sizeOf(pattern);
  if (patsize > textsize) {
    printf("Please re-enter. Your pattern is bigger than your text.\n"); }
  else {
    i = findMatch(text, pattern, patsize);
    if (i != 0) {
      printf("There's a match %d times!!\n", i);
    }
    else {
      printf("There is no match. \n");
    }
    //printIt(text, i, size); don't have to do
    printf("\n");
    return 0;
  }
}

char * getCharBlock() {
  //fills in the "string" of chars for the passed in char pointer

  int count = 0;
  char c, * a;
  a = (char *)malloc(180);
  c = getchar();
  while (c != '\n') {
    *(a + count) = c;
    count++;
    a = (char *)realloc(a, (count));
    c = getchar();
  }
  *(a + count) = '\0';
  return a;
}

int findMatch(char *text, char *pattern, int patsize) {
  //looks for a match, returns -1 for failure or an int which is the index to the location where the match starts.
  //the return values can be used to determine IF a match was found, and where
  int i=0;
  int count=0;
  int temp=0;

  while ((*(pattern + count) != '\0')) {
      if (*(text + i) ==  *(pattern + count)) {
        count ++;
        i++;
        if (count == patsize) {
          temp++;
          count= 0;
          i--;
        }
      }
      else {
        count = 0;
        if (*(text + i) == *(pattern + count)) {
          count++;
          i++;
          if (count == patsize) {
            temp++;
            count = 0;
          }
        }
        else {
          i++;
        }
    }
    if (*(text + i) == '\0') {
      break;
    }
  }
  return temp;
}


int sizeOf(char * ptr) {
  int size = 0;
  for(size = 0; (*(ptr + size) != '\0'); ++size);
  return size;
}

void printIt(char * ptr, int index, int size) {
  //prints a "string", starting from the pointer "index"
  int i;
  if (index != -1) {
  for (i = index + 4; i <= size; i++)
    printf("%c", *(ptr+i));
  }
}
