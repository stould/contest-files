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

int N;
string S;

vector<pair<int, char> > vp;

int main(void) {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') {
			vp.push_back(make_pair(i, 'R'));
		} else if (S[i] == 'L') {
			vp.push_back(make_pair(i, 'L'));
		}
	}

	int ans = 0;

	if (!vp.empty()) {
		if (vp[0].second == 'R') {
			ans += vp[0].first;
		}
		if (vp[(int)vp.size()-1].second == 'L') {
			ans += (N - vp[(int)vp.size()-1].first) - 1;
		}
	} else {
		ans = N;
	}

	for (int i = 0; i < (int) vp.size(); i++) {
		if (i > 0 && vp[i - 1].second == 'R' && vp[i].second == 'L') {
			if ((vp[i].first - vp[i - 1].first) % 2 == 0) {
				ans += 1;
			}
		} else if (i > 0 && vp[i - 1].second == 'L' && vp[i].second == 'R') {
			ans += vp[i].first - vp[i - 1].first - 1;
		}
	}

	cout << ans << endl;

    return 0;
}
