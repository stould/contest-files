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

const int MAXN = 10005;

int L, G;
pair<int, int> P[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &L, &G) == 2 && !(L == 0 && G == 0); ) {
		int x, radius;
		for (int i = 0; i < G; i++) {
			scanf("%d%d", &x, &radius);
			P[i] = make_pair(max(0, x - radius), min(L, x + radius));			
		}
		sort(P, P + G);

		int l = 0, r = 0;
		int used = 0;
		
		for (int i = 0; i < G; i++) {
			if (r >= L) break;
			if (P[i].first <= l) {
				int pos = i;
				r = P[i].second;

				while (i < G && P[i].first <= l) {
					if (P[i].second > r) {
						r = P[i].second;
						pos = i;
					}		
					i++;
				}
				used += 1;
				l = r;
				i--;
			}
		}
		int ans = -1;

		if (r >= L) {
			ans = G - used;
		}

		cout << ans << endl;
	}
    return 0;
}
