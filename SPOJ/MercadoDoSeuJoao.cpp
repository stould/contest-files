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
int V;
char T;

int fix(int x) {
	int base = x;
	
	while (!(base % 5 == 0)) {
		base -= 1;
	}

	if (abs(base - x) <= 2) {
		return base;
	} else {
		return base + 5;
	}
}

int main(void) {
	cin >> N;

	int sumA = 0, sumB = 0;

	for (int i = 0; i < N; i++) {
		cin >> V >> T;

		sumA += V;
		
		if (T == 'C') {
			sumB += V;
		} else {
			sumB += fix(V);
		}
	}
	
	cout << sumA << " " << sumB - sumA << "\n";

    return 0;
}
