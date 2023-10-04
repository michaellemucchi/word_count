#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void wordcount(char* filename);

int main(int argc, char** argv) {
  wordcount(argv[1]);
  return 0;
}


void wordcount(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("There are 0 word(s).");
    exit(0);
  }
  char a, newline = '\0';
  int counter = 0;
  fscanf(file, "%c", &a);
  while (!feof(file)) {
    if (isspace(a)) {
      if (newline != '\n') {
        counter++;
      }
    }
    newline = a;
    fscanf(file, "%c", &a);
  }
  fclose(file);
  printf("There are %d word(s).", counter);
}
