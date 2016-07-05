#include <stdio.h>

int i, t;
long int v[105];

int main(void) {
    v[1] = 1L;
    for(i = 2; i <= 100; i++) v[i] = (long long) i * (long long) v[i - 1];
    scanf("%ld", &t);
    while(t--) {
        scanf("%ld", &i);
        printf("%ld\n", v[i]);
    }
    return 0;
}
