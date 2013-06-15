#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

long long prime[1000000];

int main(void) {
    int i, j, N;

    memset(prime, 1, sizeof(prime));

    prime[0] = prime[1] = 0;

    for(i = 2; i <= (int) sqrt(999999); i++) {
        if(prime[i]) {
            for(j = i * i; j <= 999999; j += i) {
                prime[j] = 0;
            }
        }
    }
    while(~scanf("%d", &N)) {
        int count = 0;
        for(i = 0; i <= N; i++) {
            if(prime[i]) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}



