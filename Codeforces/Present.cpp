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

int N, M, W;
int P[MAXN];

int main(void) {
	cin >> N >> M >> W;

	int sm = INT_MAX;

	vector<int> pos;
	int span = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];

		if (P[i] < sm) {
			sm = P[i];
			pos.clear();
			pos.push_back(i);
		} else if (P[i] == sm) {
			pos.push_back(i);
		}
	}

	for (int i = 0; i < (int) pos.size(); i++) {
		int j = i + 1;

		while (j < (int) pos.size()) {
			if (pos[j] - pos[i] + 1 > M) {
				break;
			}
			j += 1;
		}
		span += 1;
		i = j;
	}

	cout << sm + M / span << "\n";
	
	return 0;
}
