#include <iostream>
#include <stdio.h>

using namespace std;

int n, fib[100000001];

int main(void) {
    scanf("%d", &n);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= 100000000; i++) fib[i] = fib[i - 1] + fib[i - 2];
    return 0;
}
