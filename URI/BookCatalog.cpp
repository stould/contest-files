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

int K, C[10], P[10][10];
vector<int> S;

void rec(int id, int val) {
	if (id == 5) {
		S.push_back(val);
	} else {
		for (int i = 0; i < C[id]; i++) {
			rec(id + 1, val + P[id][i]);
		}
	}
}

int main(void) {
	for (int i = 0; i < 5; i++) {
		cin >> C[i];
		for (int j = 0; j < C[i]; j++) {
			cin >> P[i][j];
		}
	}
	
	rec(0, 0);

	sort(S.rbegin(), S.rend());
	
	cin >> K;

	int ans = 0;
	
	for (int i = 0; i < K; i++) {
		ans += S[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
