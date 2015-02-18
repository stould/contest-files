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

vector<pair<int, char > > P;
int G[MAXN], H[MAXN];

int main(void) {
	cin >> N;
	
	int pos;
	char type;

	for (int i = 0; i < N; i++) {
		cin >> pos >> type;

		P.push_back(make_pair(pos, type));
	}

	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++) {
		if (P[i].second == 'G') {
			G[i] += 1;
		} else {
			H[i] += 1;
		}
		if (i > 0) {
			G[i] += G[i - 1];
			H[i] += H[i - 1];
		}
		cout << H[i] << " " << G[i] << "\n";
	}

	int lo = 1, hi = N, mi;
	int ans = 0;

	for ( ; lo <= hi; ) {
		mi = (lo + hi) / 2;

		bool ok = false;

		cout << mi << "\n";

		for (int i = mi; !ok && i < N; i++) {
			int cg = G[i] - (i > 0) ? G[i - mi - 1] : 0;
			int ch = H[i] - (i > 0) ? H[i - mi - 1] : 0;		  

			if (cg == ch) {
				ans = max(ans, P[i].first - P[i - mi].first);
				ok = true;
			}
		}

		if (ok) {
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}
	cout << ans << "\n";
    return 0;
}
