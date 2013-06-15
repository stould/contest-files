#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[15];
int i, n;
char base = (char) 'a' - 10;

int main(void) {
    scanf("%s", s);
    n = strlen(s);

    for(i = 0; i < n; i++) {
        if(s[i] > base) base = s[i];
    }
    for(i = 0; i < n; i++) {
        if(s[i] == base) {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
