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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1005;

int N;
int P[200005], Q[200005];
int M[MAXN][MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i] >> Q[i];
		M[P[i]][Q[i]] += 1;
	}

	Int ans = 0LL;

	for (int i = 1; i < MAXN; i++) {
		for (int j = 1; j < MAXN; j++) {
			if (M[i][j]) {
				for (int k = 1; k < MAXN; k++) {
					if (i + k < MAXN && j + k < MAXN && M[i + k][j + k]) {
						ans += 1;
					}
					if (i + k < MAXN && j - k >= 1 && M[i + k][j - k]) {
						ans += 1;
					}
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
