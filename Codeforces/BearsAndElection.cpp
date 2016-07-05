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
typedef unsigned uint;

const int MAXN = 110;

int N;
int P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int ans = 0;
	
	while (1) {
		int best = -1, id = -1;

		for (int i = 1; i < N; i++) {
			if (P[i] > best) {
				best = P[i];
				id = i;
			}
		}
		if (P[id] < P[0]) break;
		P[0] += 1;
		P[id] -= 1;
		ans += 1;
	}
	
	cout << ans << "\n";
	return 0;
}
