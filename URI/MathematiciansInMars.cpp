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
int P[MAXN], bit[MAXN];

int sum(int id) {
	int ans = 0;

	while (id > 0) {
		ans += bit[id];
		id -= (id & -id);
	}
	
	return ans;
}

void inc(int id, int val) {
	while (id <= N) {
		bit[id] += val;
		id += (id & -id);
	}
}

int main(void) {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		inc(i, P[i]);
	}

	string S;
	int I;

	while (cin >> S >> I) {
		if (S == "a") {
			inc(I, -P[I]);
		} else {
			cout << sum(I-1) << endl;
		}
	}
	return 0;
}
