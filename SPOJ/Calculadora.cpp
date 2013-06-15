#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

int i, s, n;
char c;
double ans = 1.0;

int main(void) {
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %c", &s, &c);
        if(c == '*') {
            ans = (double) (ans * s);
        } else {
            ans = (double) (ans / s);
        }
    }
    printf("%.0f\n", ans);
}
