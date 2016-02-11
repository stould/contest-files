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

const int MAXN = 200005;
int N;
int P[MAXN];

int main(void) {
	cin >> N;

	int L = INT_MAX;
	vector<int> cnt;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];

		if (L > P[i]) {
			L = P[i];
			cnt.clear();
			cnt.push_back(i);
		} else if (L == P[i]) {
			cnt.push_back(i);
		}
	}

	Int ans = 0;
	
	for (int i = 1; i < (int) cnt.size(); i++) {
		chmax(ans, (Int) L * N + (cnt[i] - cnt[i - 1] - 1));
	}
	
	chmax(ans, (Int) L * N + (N - cnt.back() - 1) + cnt[0]);
	
	cout << ans << "\n";
	
	return 0;
}
