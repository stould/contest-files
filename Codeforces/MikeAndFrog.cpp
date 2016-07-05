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

int M;
int A[2], H[2], X[2], Y[2];

int evolve(int h, int p) {
	return (((h * X[p] + Y[p]) % M) + M) % M;
}

int main(void) {
	cin >> M >> H[0] >> A[0] >> X[0] >> Y[0] >> H[1] >> A[1] >> X[1] >> Y[1];
	
	for (int i = 0; i < 3 * M; i++) {
		cout << H[0] << " " << H[1] << "\n";
		H[0] = evolve(H[0], 0);
		H[1] = evolve(H[1], 1);		
	}
	return 0;
}
