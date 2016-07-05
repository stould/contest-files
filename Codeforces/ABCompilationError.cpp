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

int N;
int S[4][MAXN];

int main(void) {
	cin >> N;

	vector<int> ans;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N - i; j++) {
			cin >> S[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		map<int, int> cnt, oth;
		
		for (int j = 0; j < N - i; j++) {
			cnt[S[i][j]] += 1;
			if (j != N - i - 1) {
				oth[S[i + 1][j]] += 1;
			}
		}
		for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second != oth[it->first]) {
				ans.push_back(it->first);
				break;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	
    return 0;
}
