// questao 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *usr = "200700";
  const int size = strlen(usr);

  int aux = size;
  for (int i = 0; i < size; i++) {
    if ()
      printf("%c", usr[i]);
    aux--;
  }
}

/*
// questao 14
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *usr = "Hello";
  const int size = strlen(usr);

  int aux = 0;
  for (int i = 0; i < size; i++) {
    printf("\n");
    for (int j = 0; j <= aux; j++) {
      printf("%c", usr[j]);
    }
    aux++;
  }
  printf("\n");
  return 0;
}
*/
