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
typedef unsigned uint;


int T, N;
string S;

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N >> S;

		vector<int> ans;
		set<int> alive;
		
		for (int i = 0; i < N; i++) {
			if (S[i] == 'D') {
				alive.insert(i);
			}
		}

		for (int i = 0; i < N; i++) {
			if (alive.empty()) break;

			int now = (*alive.begin());
			alive.erase(now);

			ans.push_back(now);

			if (now - 1 >= 0) {
				if (S[now - 1] == 'B') {
					S[now - 1] = 'D';
				} else if (S[now - 1] == 'D') {
					alive.erase(now - 1);
					S[now - 1] = 'B';
				}
				if (S[now - 1] == 'D') {
					alive.insert(now - 1);
				}
			}
			if (now + 1 < N) {
				if (S[now + 1] == 'B') {
					S[now + 1] = 'D';
				} else if (S[now + 1] == 'D') {
					alive.erase(now + 1);
					S[now + 1] = 'B';
				}
				if (S[now + 1] == 'D') {
					alive.insert(now + 1);
				}
			}
			S[now] = 'X';
			//cout << S << "\n";
		}

		if (N == (int) ans.size()) {
			cout << "Y\n";

			for (int i = 0; i < N; i++) {
				if (i) cout << " ";
				cout << ans[i] + 1;
			}
			cout << "\n";
		} else {
			cout << "N\n";
		}
	}
	return 0;
}
