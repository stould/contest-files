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

const int MAXN = 10004;

int T, N, C, M, P;
pair<int, int> CP[MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> C;

		for (int i = 0; i < C; i++) {
			cin >> CP[i].first >> CP[i].second;
		}

		sort(CP, CP + C);

		vector<pair<int, int> > real_int;
		
		int last = 0;

		for (int i = 0; i < C; i++) {
			int bi = i;
			last = CP[i].second;

			while (i < C && CP[i].first <= last) {
				last = max(last, CP[i].second);
				i++;
			}
			i--;
			real_int.push_back(make_pair(CP[bi].first, last));
		}

		cin >> M;
		
		int ans = 0;
		
		for (int i = 0; i < M; i++) {
			cin >> P;
			
			bool ok = false;
			int l = 0, h = (int) real_int.size() - 1, m;

			while (l <= h) {
				m = (l + h) / 2;

				if (real_int[m].first > P) {
					h = m - 1;
				} else {
					l = m + 1;
					if (real_int[m].first <= P && real_int[m].second >= P) {
						ok = true;
					}
				}
			}
			if (ok) ans += 1;
		}

		cout << "Caso #" << t << ": " << ans << "\n";
	}
    return 0;
}
