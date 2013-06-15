#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110

int i, x, last, ok = 1, found = 0;
char str[MAXN], *mem = "hello";

int main(void) {
    scanf("%s", str);
    last = -1;
    for(x = 0; x < 5; x++) {
        int tmp = 0;
        for(i = 0; i < strlen(str); i++) {
            if(str[i] == mem[x] && i > last) {
                tmp = 1;
                last = i;
                found += 1;
                break;
            }
        }
        if(!tmp) {
            ok = 0;
            break;
        }
    }
    if(ok && found == 5) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
