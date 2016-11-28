#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
int key;
char *s, c, *p;
if (argc == 3) {
  key = atoi(argv[1]);
  s = argv[2];
} else {
  printf("Dwse ws parametro to kleidi kai to keimeno gia cryptografisi\n");
  printf("Gia apokryptografisi dwse arnitiko kleidi\n\n");
  printf("Usage: ceasar 3 TEXT\n");
  return -1;
}
p=s;
while (*(s++)) {
  *(s - 1)  = (((*(s - 1)) - 'A' + key) % 26) + 'A';
//  s++;
}

printf("%s\n", p);
return 0;
}
