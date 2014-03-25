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

const int MAXN = 10005;

int A, B, N;
vector<int> g[MAXN];
bool vis[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		g[A].push_back(B);
	}

	bool ans = 1;
	int curr = 1, visited = 0;

	for (int i = 0; i < N && ans; i++) {
		if (g[curr].size() > 1) {
			ans = 0;
		} else {
			vis[curr] = true;

			int next = g[curr][0];

			if (!vis[next]) {
				curr = next;
			} else {
				if (i != N - 1) {
					ans = 0;
				}
			}
		}
	}

	cout << (ans == 1 ? "S" : "N") << endl;

    return 0;
}
