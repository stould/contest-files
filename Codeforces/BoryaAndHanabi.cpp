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

int N;
string S, P = "12345RGBYW";
vector<string> vs;
bool app[300];

int main(void) {
	cin >> N;

	int ans = 101010;
	
	for (int i = 0; i < N; i++) {
		cin >> S;
		vs.push_back(S);
	}
	
	for (int i = 0; i < (1 << 10); i++) {		
		int p =  __builtin_popcount(i);
		if (p > ans) continue;

		memset(app, false, sizeof(app));
			   
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				app[P[j]] = true;
			}
		}
		bool ok = true;

		for (int j = 0; ok && j < N; j++) {
			for (int k = 0; ok && k < N; k++) {
				if (j != k) {
					if (vs[j][0] == vs[k][0]) {
						if (vs[j][1] == vs[k][1]) continue;
						if (!app[vs[j][1]] && !app[vs[k][1]]) {
							ok = false;
						}
					}
					if (vs[j][1] == vs[k][1]) {
						if (vs[j][0] == vs[k][0]) continue;
						if (!app[vs[j][0]] && !app[vs[k][0]]) {
							ok = false;
						}
					}
					if (!app[vs[j][0]] && !app[vs[k][0]] && !app[vs[j][1]] && !app[vs[k][1]]) {
						if (vs[j][0] != vs[k][0] && vs[j][1] != vs[k][1]) {
							ok = false;
						}
					}
				}
			}			
		}
		if (ok) {
			if (p < ans) {
				ans = p;
			}
		}
	}
	cout << ans << "\n";		 

    return 0;
}
