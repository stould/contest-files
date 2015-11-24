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

const int MAXN = 1000505;

int N;
int P[MAXN];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;

	int A;
	
	for (int i = 0; i < N; i++) {
		cin >> A;
		P[A] += 1;
	}

	int ans = 0;
	
	for (int i = 0; i < MAXN - 1; i++) {
		P[i + 1] += (P[i] / 2);
		P[i] %= 2;

		ans += P[i];
	}

	cout << ans << "\n";

	
	return 0;
}
