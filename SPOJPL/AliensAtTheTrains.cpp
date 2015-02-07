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

const int MAXN = 100010;

int T;
int N, M;
Int P[MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		P[0] = 0LL;
		
		for (int i = 1; i <= N; i++) {
			cin >> P[i];

			P[i] += P[i - 1];
		}

		int best = 0;
		Int seen = 0;

		for (int i = 1; i <= N; i++) {
			if (N - i + 1 < best) {
				break;
			}
			
			int l = i, h = N, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				Int curr = P[m] - P[i - 1];
				int len = m - i + 1;

				if (curr <= M) {
					if (len > best || (len == best && curr < seen)) {
						best = len;
						seen = curr;				   
					}
					l = m + 1;
				} else {
					h = m - 1;
				}
			}
		}
		cout << seen << " " << best << "\n";
	}
	
    return 0;
}
