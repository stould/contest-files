#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int i;
char s[1010];

int main(void) {
    scanf("%s", s);
    for(i = 0; i < strlen(s); i++) if(s[i] == '.') break;

    if(s[i - 1] == '9') {
        printf("GOTO Vasilisa.");
    } else {
        if(s[i + 1] >= '5') {
            s[i - 1] += 1;
        }
        for(int tmp = 0; tmp < i; tmp++) {
            printf("%c", s[tmp]);
        }
        printf("\n");
    }
    return 0;
}
