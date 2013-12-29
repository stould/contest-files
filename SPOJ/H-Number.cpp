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

const int N1 = 100005;
bool isPrime[MAXN];
int prime[MAXN], nPrime, totient[MAXN];

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


int main(void) {
    return 0;
}
