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

const double PI  = acos(-1.0);
const double EPS = 1e-7;

int T, S, C, K;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S >> C >> K;

		int ans = 0;
		map<double, int> cnt;
		map<int, int> sum;
		map<double, int>::iterator it;

		//cnt[0] += S;

		for (int i = 1; i <= S; i++) {
			double add  = PI / (double) (pow(2.0, i - 1));
			double curr = PI / (double) (pow(2.0, i - 1));

			while (curr <= 2 * PI) {
				cnt[curr] += 1;
				curr += add;
			}

			cout << "S " << i << endl;
			for (it = cnt.begin(); it != cnt.end(); it++) {
				sum[it->second] += 1;
				//cout << it->second << endl;
			}
			for (map<int, int>::iterator it = sum.begin(); it != sum.end(); it++) {
				cout << it->first << " " << it->second << endl;
			}
			cout << endl;
		}

		for (int i = 1; i <= C; i++) {
			double add  = PI / (double) (pow(2.0, i));
			double curr = PI / (double) (pow(2.0, i));

			while (curr <= 2 * PI) {
				cnt[curr] += 1;
				curr += add;
			}
			cout << "C " << i << endl;
			for (it = cnt.begin(); it != cnt.end(); it++) {
				sum[it->second] += 1;
				//cout << it->second << endl;
			}
			for (map<int, int>::iterator it = sum.begin(); it != sum.end(); it++) {
				cout << it->first << " " << it->second << endl;
			}
			cout << endl;
		}
		
		for (it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second >= K) {
				ans += 1;
			}
		}

		cout << ans << endl;
	}
    return 0;
}
