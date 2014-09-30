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

const int MAXN = 2020;

int N;
vector<int> P[MAXN];
int Q[MAXN];
int ans[MAXN][3];

int main(void) {
	cin >> N;
	int t;

	for (int i = 0; i < N; i++) {
		cin >> t;
		P[t].push_back(i);
		Q[i] = t;
	}
	
	bool ok = true;
	
	int pos = 0;

	for (int i = 1; i <= 2000; i++) {
		if (!P[i].empty()) {
			for (int j = 0; j < P[i].size(); j++) {
				ans[pos][0] = ans[pos][1] = ans[pos][2] = P[i][j];
				pos++;
			}
		}
	}

	int s = 0;

	for (int i = 0; i < N - 1; i++) {
		if (Q[ans[i][0]] == Q[ans[i + 1][0]]) {
			if (s == 0) {
				s++;
				swap(ans[i][1], ans[i + 1][1]);
			} else if (s == 1) {
				s++;
				swap(ans[i][2], ans[i + 1][2]);
			}
		}
	}

	if (s >= 2) {
		cout << "YES\n";

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", ans[j][i] + 1);
			}
			printf("\n");
		}
	} else {
		cout << "NO\n";
	}
	
    return 0;
}
