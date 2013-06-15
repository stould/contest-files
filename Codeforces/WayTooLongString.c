#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, l;
char s[110];

int main(void) {
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s); l = strlen(s);
        if(l <= 10) {
            printf("%s\n", s);
        } else {
            printf("%c%d%c\n", s[0], (l - 2), s[l - 1]);
        }
    }
    return 0;
}
