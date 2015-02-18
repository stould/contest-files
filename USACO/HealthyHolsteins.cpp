/*
ID: jeferso1
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

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

int N, M;
int P[30], Q[30][30];

int main(void) {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Q[i][j];
		}
	}

	int ans = INT_MAX / 3, cnt = 101010;

	for (int i = 0; i < (1 << M); i++) {
		vector<int> curr(N, 0);
		int used = __builtin_popcount(i);

		for (int j = 0; j < M; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < N; k++) {
					curr[k] += Q[j][k];
				}
			}
		}
		
		bool ok = true;
		
		for (int j = 0; j < N; j++) {
			if (curr[j] < P[j]) {
				ok = false;
			}
		}
		
		if (ok) {
			if (used < cnt) {
				cnt = used;
				ans = i;
			}
		}
	}
	
	cout << __builtin_popcount(ans) << " ";
	vector<int> vs;

	for (int i = 0; i < 32; i++) {
		if (ans & (1 << i)) {
			vs.push_back(i + 1);
		}
	}

	for (int i = 0; i < vs.size(); i++) {
		if (i > 0) cout << " ";
		cout << vs[i];
	}
	cout << endl;

    return 0;
}
