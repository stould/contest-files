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

const int MAXN = 1010;

int N, XA, YA;
int X[MAXN], Y[MAXN];

int main(void) {
	cin >> N >> XA >> YA;

	set<double> st;

	int hor = 0;
	int ver = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		
		int u = YA - Y[i];
		int v = XA - X[i];

		if (v == 0) {
			hor = 1;
		} else if (u == 0) {
			ver = 1;
		} else {
			st.insert(u / (double) v);
		}
	}

	int ans = hor + ver + st.size();

	cout << ans << "\n";
	
    return 0;
}
