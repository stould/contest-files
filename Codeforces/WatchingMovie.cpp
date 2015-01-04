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

int N, X;
int A[MAXN], B[MAXN];

int main(void) {
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}

	int pos = 1;
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		int l = 0, h = 100000, m;
		int best_pos = -1;

		for ( ; l <= h; ) {
			m = (l + h) / 2;
			
			Int next_pos = pos + X * (Int) m;

			if (next_pos <= A[i]) {
				best_pos = next_pos;
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		ans += B[i] - best_pos + 1;		
		pos = B[i] + 1;
	}

	cout << ans << "\n";
	
    return 0;
}
