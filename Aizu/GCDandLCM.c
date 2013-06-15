#include <stdio.h>

long long a, b;

long long gcd(long long a, long long b) {
   if(b == 0) return a;
   return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main(void) {
    while(~scanf("%I64d %I64d ", &a, &b)) {
        printf("%ld %ld\n", a, b);
        printf("%ld %ld\n", gcd(a, b), lcm(a, b));
    }
    return 0;
}
