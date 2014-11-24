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

int N[3], M;
int H[3][MAXN];

void func(int rec) {
	int x = rec, fx = rec;
	int p = 0;
	
	for ( ; ; ) {
		fx = (x % N[p]); 
		if (H[p][fx] == -1) {
			H[p][fx] = x;
			break;
		} else {
			int tmp = H[p][fx];
			H[p][fx] = x;
			x = tmp;
		}
		p ^= 1;
	}
}

int main(void) {
	int test = 1;
	for ( ; cin >> N[0] >> N[1] >> M && N[0] + N[1] + M != 0; ) {
		memset(H, -1, sizeof(H));

		int P;

		for (int i = 0; i < M; i++) {
			cin >> P;
			func(P);
		}

		cout << "Case " << test++ << ":\n";

		vector<pair<int, int> > ans1, ans2;

		for (int i = 0; i < N[0]; i++) {
			if (H[0][i] != -1) {
				ans1.push_back(make_pair(i, H[0][i]));
			}
		}
		for (int i = 0; i < N[1]; i++) {
			if (H[1][i] != -1) {
				ans2.push_back(make_pair(i, H[1][i]));
			}
		}
		
		if (!ans1.empty()) {
			cout << "Table 1\n";

			for (int i = 0; i < ans1.size(); i++) {
				cout << ans1[i].first << ":" << ans1[i].second << "\n";
			}
		}
		if (!ans2.empty()) {
			cout << "Table 2\n";

			for (int i = 0; i < ans2.size(); i++) {
				cout << ans2[i].first << ":" << ans2[i].second << "\n";
			}
		}
	}
    return 0;
}
