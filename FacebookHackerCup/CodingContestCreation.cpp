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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int T, N;
int P[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<bool> used(N, false);

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			if (used[i]) continue;

			int avail = 1;
			
			for (int j = P[i] + 1; j <= min(100, P[i] + 10); j++) {
				if (i + 1 < N && P[i + 1] == j && !used[i + 1]) {
					used[i + 1] = true;

					avail += 1;
					
					for (int k = j + 1; k <= min(100, j + 10); k++) {
						if (i + 2 < N && P[i + 2] == k && !used[i + 2]) {
							used[i + 2] = true;

							avail += 1;

							for (int l = k + 1; l <= min(100, k + 10); l++) {
								if (i + 3 < N && P[i + 3] == l && !used[i + 3]) {
									used[i + 1] = true;

									avail += 1;									
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}

			ans += max(0, 4 - avail);

			cout << P[i] << " " << avail << "\n";
			i += max(0, avail - 1);
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}


	return 0;
}
