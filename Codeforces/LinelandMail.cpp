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

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < N; i++) {
		vector<Int> vd;
		if (i != 0) {
			vd.push_back(abs(P[i] -P[0]));
		}
		if (i != N - 1) {
			vd.push_back(abs(P[i] -P[N - 1]));
		}

		if (i - 1 > 0) {
			vd.push_back(abs(P[i] - P[i - 1]));
		}
		if (i + 1 < N) {
			vd.push_back(abs(P[i] - P[i + 1]));
		}
		sort(vd.begin(), vd.end());
		cout << vd[0] << " " << vd.back() << "\n";
	}

	
	return 0;
}
