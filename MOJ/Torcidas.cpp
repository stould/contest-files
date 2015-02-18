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

const int MAXN = 1005;

int N, id;
int choose[MAXN];
bool vis[MAXN];
string S[MAXN];
bool ok;

void dfs(int x) {
	vis[x] = true;
	choose[x] = id;
	for (int i = 0; i < N; i++) {
		if (i != x) {
			if (S[x][i] == '1') {
				if (!vis[i]) {
					choose[i] = id;
					dfs(i);
				} else {
					if (choose[i] != id) {
						ok = false;
					}
				}
			} else {
				if (choose[i] != -1 && choose[i] == choose[x]) {
					ok = false;
				}
			}
		}
	}

}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		ok = true;
		id = 0;
		for (int i = 0; i < MAXN; i++) {
			choose[i] = -1;
			vis[i] = false;
		}
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				dfs(i);
				id++;
				ans += 1;
			}
		}
		if (ok) {
			printf("%d\n", ans);
		} else {
			puts("impossivel");
		}
	}
    return 0;
}
