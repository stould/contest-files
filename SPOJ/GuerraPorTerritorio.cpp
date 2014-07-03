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

const int MAXN = 100005;
int N, P[MAXN];

int main(void) {
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		sum += P[i];
	}
	sum /= 2;
	for (int i = 0; i < N; i++) {
		sum -= P[i];
		if (sum == 0) {
			cout << i + 1 << "\n";
			break;
		}
	}
    return 0;
}
