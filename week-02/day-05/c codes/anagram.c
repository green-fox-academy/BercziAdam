#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strnorm(char s[]) {
    int i = 0, j = 0;
    while (s[i] != 0) {
        if (!ispunct(s[i]) && !isspace(s[i])) { s[j++] = tolower(s[i]); }
        i++;
    }
    s[j] = 0;
}

int charcmp(const void *a1, const void *a2) {
    char c1 = *((char *) a1), c2 = *((char *) a2);
    return c1 < c2 ? -1 : (c1 > c2 ? 1 : 0);
}

int main() {
    char s1[100], s2[100];
    while (1) {
        printf("> ");
        fgets(s1, 100, stdin);
        s1[strlen(s1) - 1] = 0;

        if (!strcmp(s1, "kilep")) { return 0; }

        printf("> ");
        fgets(s2, 100, stdin);
        s2[strlen(s2) - 1] = 0;


        strnorm(s1);
        strnorm(s2);


        qsort(s1, strlen(s1), 1, charcmp);
        qsort(s2, strlen(s2), 1, charcmp);

        if (!strcmp(s1, s2)) { printf("Anagramma!\n"); }
        else { printf("Nem anagramma.\n"); }
    }
}
