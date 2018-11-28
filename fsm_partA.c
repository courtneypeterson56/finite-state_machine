#include <stdio.h>
#include <stdlib.h>

/*
Courtney Peterson
Computer Systems PART A

This program is a FSM recognizer to recognize the pattern:
"GCAG". Using FSM recognizer, this program will "recognize" (that is, determine if the pattern is in the text).
The text is read (one char at a time) and stored in a char array. If the pattern is recognized,
outputs a nice statement and indicates where in text the pattern starts.
*/

char * getCharBlock();
int findMatch(char * text, char *pattern, int size);
int sizeOf(char * ptr);
void printIt(char * ptr, int index, int size);


int main() {
  char *text, *pattern; //pointers for the charactersread
  char *p, *q, *r; // pointer variables
  int n, m, x, y;  // integers
  int size;
  int i;

  char patternarray[] = "GCAG";
  pattern = patternarray;

  printf("Input text : \t" );
  text = getCharBlock();
  size = sizeOf(text);
  i = findMatch(text, pattern, size);
  if (i != -1) {
    printf("There's a match!!\nAnd it starts at %d \n", i);
  }
  else {
    printf("There is no match. \n");
  }
  printIt(text, i, size);
  printf("\n");
  return 0;
}

char * getCharBlock() {
  //fills in the "string" of chars for the passed in char pointer
  int count = 0;
  char c, * a;
  a = (char *)malloc(80);
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

int findMatch(char *text, char *pattern, int size) {
  //looks for a match, returns -1 for failure or an int which is the index to the location where the match starts.
  //the return values can be used to determine IF a match was found, and where

  int i;
  for (i=0; i < 1000; i++) {
    if (*(text + i) ==  *(pattern)) {
      if (*(text + i + 1) == *(pattern + 1)) {
        if (*(text + i + 2) == *(pattern + 2)) {
          if (*(text + i +3) == *(pattern + 3)) {
            return i;
            }}}}}
    return -1;
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
