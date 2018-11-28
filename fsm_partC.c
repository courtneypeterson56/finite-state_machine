#include <stdio.h>
#include <stdlib.h>

/*
Courtney Peterson
Computer Systems PART C

This program finds ALL instances of the pattern in the text. For example, if
the TEXT was: GCAGCAGCAG there are three matches.
This program prints out how many matches.
*/

char * getCharBlock();
int findMatch(char * text, char *pattern, int size);
int sizeOf(char * ptr);
void printIt(char * ptr, int index, int size);


int main() {
  char *text, *pattern; //pointers for the characters read
  char *p, *q, *r; //pointer variables
  int n, m, x, y;  //integers
  int size;
  int i;

  char patternarray[] = "GCAG";
  pattern = patternarray;

  printf("Input text : \t" );
  text = getCharBlock();
  size = sizeOf(text);
  i = findMatch(text, pattern, size);
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

int findMatch(char *text, char *pattern, int size) {
  //looks for a match, returns -1 for failure or an int which is the index to the location where the match starts.
  //the return values can be used to determine IF a match was found, and where
  int i=0;
  int count=0;
  int temp=0;

  while ((*(pattern + count) != '\0')) {
      if (*(text + i) ==  *(pattern + count)) {
        count ++;
        i++;
        if (count == 4) {
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
          if (count == 4) {
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
