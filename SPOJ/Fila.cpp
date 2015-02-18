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

const int MAXN = 50005;

int N, M;
int P[MAXN];
set<int> s;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int p;
		cin >> p;
		s.insert(p);
	}
	for (int i = 0; i < N; i++) {
		if (!s.count(P[i])) {
			cout << P[i] << " ";
		}
	}
	cout << "\n";
    return 0;
}
