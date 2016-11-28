#include <stdio.h>
#include <stdlib.h>

char alphabet[27]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cipher_ab[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void rotate_ab(int key) {
  char c;
  int i,j;
  for (i=0; i < key; i++) {
    c = cipher_ab[0];
    for (j=0; j<25; j++) {
      cipher_ab[j] = cipher_ab[j+1];
    }
    cipher_ab[25] = c;
  }
}

int main(int argc, char *argv[]) {
    int i;
    int key;
    char *s, c, *p;

    if (argc == 3) {
        key = atoi(argv[1]);
        s = argv[2];
    } 
    else {
        printf("Please supply KEY and message to encrypt\n");
        printf("To decrypt please supply negative value for KEY\n\n");
        printf("Encryption: ceasar 3 TEXT\n");
        printf("Decryption: ceasar -3 TEXT\n");
        return -1;
    }

    rotate_ab(key);

    p=s;
    while (*(s++)) {
    c = *(s - 1);
    for (i = 0; i < 26; i++) {
        if (c == alphabet[i]) {
            c = cipher_ab[i];
//      printf("%c -> %c\n", alphabet[i], cipher_ab[i]);
        break;
        }
    }
    *(s - 1)  = c;
    }

    printf("%s\n", p);
    return 0;
}
