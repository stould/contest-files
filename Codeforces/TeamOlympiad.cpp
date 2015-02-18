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

int N, X;
vector<int> P[5];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X;
		P[X].push_back(i + 1);
	}
	
	int L = min(P[1].size(), min(P[2].size(), P[3].size()));

	cout << L << "\n";

	for (int i = 0; i < L; i++) {
		cout << P[1][i] << " " << P[2][i] << " " << P[3][i] << "\n";
	}

    return 0;
}
