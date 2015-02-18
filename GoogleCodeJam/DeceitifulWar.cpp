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

int T, N;
double NA[1010], KE[1010];

int optimal(void) {
	int points = 0;

	int last = 0;

	for (int i = 0; i < N; i++) {
		for (int j = last; j < N; j++) {
			if (NA[j] > KE[i]) {
				points += 1;
				last = j + 1;
				break;
			}
		}
		if (last == N) break;
	}

	return points;
}

int normal(void) {
	int points = 0;

	vector<bool> used(N, false);

	for (int i = 0; i < N; i++) {
		bool win = true;
		for (int j = 0; j < N; j++) {
			if (!used[j] && KE[j] > NA[i]) {
				win = false;
				used[j] = true;
				break;
			}
		}
		if (win) {
			points += 1;			
			for (int j = 0; j < N; j++) {
				if (!used[j]) {
					used[j] = true;
					break;
				}
			}
		}		
	}

	return points;
}

int main(void) {
	//	freopen("o.ot", "w", stdout);
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> NA[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> KE[i];
		}

		sort(NA, NA + N);
		sort(KE, KE + N);

		printf("Case #%d: %d %d\n", t, optimal(), normal());

	}

    return 0;
}
