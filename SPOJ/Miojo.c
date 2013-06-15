#include <stdio.h>

int t, tmp, a, b, auxa, auxb, total, ca = 1, cb = 1;

int main(void) {
    scanf("%d %d %d", &t, &a, &b);
    if(a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    auxa = a;
    auxb = b;
    do {
        if(auxa == t || auxb == t) {
            if(auxa == t) {
                total = ca * a;
                break;
            }
            if(auxb == t) {
                total = cb * b;
                break;
            }
        }
        if(auxb > auxa) {
            ca++;
            auxb = auxb - auxa;
            auxa = a;
        } else {
            cb++;
            auxa = auxa - auxb;
            auxb = b;
        }
    } while(1);
    printf("%d\n", total);
    return 0;
}
