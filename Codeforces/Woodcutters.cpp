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

int N;
int P[MAXN], Len[MAXN];


int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i] >> Len[i];
	}

	int ans = 0, last = -INT_MAX;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			ans += 1;
			last = P[i];
			continue;
		}
		if (P[i] - Len[i] > last && P[i] - Len[i] > P[i - 1]) {
			ans += 1;
			last = P[i];
		} else {
			if (last > P[i] && i != 0 && P[i] - Len[i] > P[i - 1]) {
				last = P[i];
			} else {
				if (i < N - 1) {
					if (P[i] + Len[i] < P[i + 1]) {
						ans += 1;
						last = P[i] + Len[i];
					}
				} else {
					ans += 1;
				}
			}
		}	
	}
	
	cout << ans << "\n";
	
	return 0;
}
