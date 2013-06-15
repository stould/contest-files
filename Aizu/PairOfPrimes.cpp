#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

bool sieve[10001];

void s() {
    memset(sieve, 1, sizeof(sieve));
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i <= sqrt(10001); i++) {
        if(sieve[i]) {
            for(int j = i * i; j < 10000; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

int p, ct = 0;

int main(void) {
    s();
    while(~scanf("%d", &p)) {
        ct = 0;
        for(int i = 1; i <= p; i++) {
            if(sieve[i] && sieve[(p - i) + 1]) {
                ct++;
            }
        }
        printf("%d\n", ct);
    }
    return 0;
}

