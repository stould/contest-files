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
Int P[MAXN];

int main(void) {
	cin >> N;

	Int bef = 0LL;
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	sort(P, P + N);

	swap(P[(N + 1) / 2], P[N - 1]);

	sort(P + (N + 1) / 2 + 2, P + N);
	
	for (int i = 0; i < N; i++) {
		if (P[i] >= bef) {
			ans += 1;			
			bef += P[i];
		}
	}	
	
	cout << ans << "\n";
	
	return 0;
}
