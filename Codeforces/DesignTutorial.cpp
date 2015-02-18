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

int N;

bool isPrime(long long n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    long long m = (long long) sqrt(n);

    for (int i = 3L; i <= m; i += 2L) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}


int main(void) {
	cin >> N;

	for (int i = 4; i <= N; i++) {
		if (!isPrime(i) && !isPrime(N - i)) {
			cout << i << " " << (N - i) << "\n";
			break;
		}
	}
    return 0;
}
