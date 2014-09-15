#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int T, N;

const int N1 = 1000005, N2 = 1000005;

bool isPrime[N1];
int prime[N2], nPrime, totient[N1];

void sieveAndTotient() {
    for (int i = 0; i < N1; ++i)
        totient[i] = i;
    isPrime[0] = isPrime[1] = false;
    for (int i = 3; i < N1; i += 2)
        isPrime[i] = true;
    for (int i = 4; i < N1; i += 2)
        isPrime[i] = false;
    nPrime = 0;
    prime[nPrime++] = 2;
    for (int j = 2; j < N1; j += 2) {
        isPrime[j] = false;
        totient[j] -= totient[j] / 2;
    }

    isPrime[2] = true;
    for (int i = 3; i < N1; i += 2)
        if (isPrime[i]) {
            prime[nPrime++] = i;
            if (i < INT_MAX)
                for (int j = i; j < N1; j += i) {
                    isPrime[j] = false;
                    totient[j] -= totient[j] / i;
                }
            isPrime[i] = true;
        }
}

int main(void) {
	T = in();
	
	sieveAndTotient();

	for ( ; T--; ) {
		N = in();
		printf("%d\n", totient[N]);
	}
    return 0;
}
