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

const int MAXN = 2000004;

int N;
int A[MAXN];
set<int> U;
int cnt[MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	int p = 0;
	int max_value = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];

		max_value = max(A[i], max_value);

		U.insert(A[i]);
		
		cnt[A[i]] += 1;
	}

	N = p;

	Int ans = 0LL;

	for (set<int>::iterator it = U.begin(); it != U.end(); it++) {
		int init = *it;
		for (int j = init; j <= max_value; j += init) {
			Int mul = cnt[init];

			if (init == j) {
				mul -= 1;
			}
			
			ans += mul * cnt[j];
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}
