#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;

char str[10];
int i, h, m, s, c, dh, dm, ds, dc;

int main(void) {
    while(scanf("%s", str) == 1) {
        h = ((str[0] - '0') * 10) + (str[1] - '0');
        m = ((str[2] - '0') * 10) + (str[3] - '0');
        s = ((str[4] - '0') * 10) + (str[5] - '0');
        c = ((str[6] - '0') * 10) + (str[7] - '0');
        double dec = (double) (10*100*100*100) / (double) (24*60*60*100);
        ll hora = (h * 60);
        ll min = (hora + m) * 60;
        ll sec = (min + s) * 100;
        ll total = (sec + c) * dec;
        if(total == 0) {
            printf("0000000\n");
        } else {
            ll len = 0, tmpx = total;
            while(total) { total /= 10; len++; }
            for(i = 0; i < 7 - len; i++) {
                printf("0");
            }
            printf("%lld\n", tmpx);
        }
    }
    return 0;
}
