//Memoizing
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N1 = 50001, N2 = 5133;
bool isPrime[N1];
int prime[N2], nPrime, totient[N1];

void sieveAndTotient() {
    // reset
    for (int i = 0; i < N1; ++i)
        totient[i] = i;
    isPrime[0] = isPrime[1] = false;
    for (int i = 3; i < N1; i += 2)
        isPrime[i] = true;
    for (int i = 4; i < N1; i += 2)
        isPrime[i] = false;
    nPrime = 0;
    // 2
    // update for 2
    prime[nPrime++] = 2;
    for (int j = 2; j < N1; j += 2) {
        isPrime[j] = false;
        // totient for 2
        totient[j] -= totient[j] / 2;
    }
    isPrime[2] = true;
    // odds
    for (int i = 3; i < N1; i += 2)
        if (isPrime[i]) {
            // update for i
            prime[nPrime++] = i;
            if (i < INT_MAX)
                for (int j = i; j < N1; j += i) {
                    isPrime[j] = false;
                    // totient for i
                    totient[j] -= totient[j] / i;
                }
            isPrime[i] = true;
        }
}

//Direct
int fi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			result -= result / i;
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1) {
		result -= result / n;
	}
	return result;
}
