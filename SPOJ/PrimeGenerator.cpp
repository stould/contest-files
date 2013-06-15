#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int n, first, last, primes[10000000], len = 0;

bool isPrime(int v) {
    if(v <= 1) return false;
    if(v == 2) return true;
    if(v % 2 == 0) return false;

    int m = (int) sqrt(v);

    for(int x = 3; x <= m; x++) {
        if(v % x == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
    	scanf("%d %d", &first, &last);

    	for(int j = first; j <= last; j++) {
    	    if(isPrime(j)) {
    	    	printf("%d\n", j);
    	    	primes[len++] = j;
    	    }
    	}
    	printf("\n");
    }
    return 0;
}
