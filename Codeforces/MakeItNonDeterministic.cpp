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
int P[MAXN];
string H[MAXN][2];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> H[i][0] >> H[i][1];

		if (H[i][1] < H[i][0]) swap(H[i][0], H[i][1]);
	}

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		P[i] -= 1;
	}

	bool ok = true;
	string last = H[P[0]][0];

	for (int i = 1; i < N; i++) {
		int id = P[i];

		if (H[id][0] > last) {
			last = H[id][0];
		} else if (H[id][1] > last) {
			last = H[id][1];
		} else {
			ok = false;
		}
	}

	if (ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}
