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

const int MAXN = 1010;
const int INF = INT_MAX / 3;

int C, N;
int caixa[15], entrada[15];
pair<int, int> P[MAXN];

int main(void) {
	cin >> C >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	int ans = 0, T = 0, ps = 0, enq = 0;

	memset(entrada, -1, sizeof(entrada));

	for ( ; ps < N; ) {
		for (int i = 0; i < C; i++) {
			if (entrada[i] == T) {
				entrada[i] = -1;
				enq--;
			}			
		}
		while (enq < C && ps < N) {
			if (P[ps].first > T) break;
			if (T - P[ps].first > 20) {
				ans += 1;
			}
			for (int i = 0; i < C; i++) {
				if (entrada[i] == -1) {				
					entrada[i] = T + P[ps].second;
					enq++;
					ps++;
					break;
				}
			}
		}
		T++;		
	}
	cout << ans << endl;
    return 0;
}
