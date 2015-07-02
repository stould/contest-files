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

int N, T;
int P[MAXN];
int L[MAXN], R[MAXN];

int main(void) {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<pair<int, int> > vpos;

		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			L[i] = i - 1;
			R[i] = i + 1;

			vpos.push_back(make_pair(P[i], i));
		}
	
		sort(vpos.begin(), vpos.end());
	
		Int ans = 0;

		for (int i = 0; i < N - 1; i++) {
			int curr = vpos[i].second;
						
			if (L[curr] == 0) {
				ans += max(P[curr],  P[R[curr]]);
				L[R[curr]] = 0;
			} else if (R[curr] == N + 1) {
				ans += max(P[curr], P[L[curr]]);			   
				R[L[curr]] = N + 1;			
			} else {
				if (max(P[curr], P[L[curr]]) < max(P[curr], P[R[curr]])) {
					ans += max(P[curr], P[L[curr]]);
				} else {
					ans += max(P[curr], P[R[curr]]);
				}
				R[L[curr]] = R[curr];
				L[R[curr]] = L[curr];
			}
		}
	
		cout << ans << "\n";
	}
	
	return 0;
}
