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

const int MAXN = 600005;

Int C, N, M;
Int P[MAXN];

int main(void) {
	cin >> C >> M >> N;

	P[0] = 0;
	P[1] = C;

	vector<pair<Int, Int> > V;
	
	for (int i = 2; i < 2 * N + 2; i++) {
		P[i] = (P[i - 1] + P[i - 2]) % M;
	}
	
	for (int i = 2; i + 1 < 2 * N + 2; i += 2) {
		V.push_back(make_pair(P[i], P[i + 1]));
	}

	map<Int, bool> seen;

	int ans = 0;
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			Int val = (((V[i].first * V[j].first) % M) + ((V[i].second * V[j].second) % M)) % M;

			if (!seen[val]) {
				ans += 1;
				seen[val] = true;
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}
