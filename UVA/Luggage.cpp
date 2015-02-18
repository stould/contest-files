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

int T, N, sum;
string S;
vector<int> P;

vector<int> split(string st) {
	vector<int> ans;
	istringstream ss(st);
	int tmp;

	for ( ; ss >> tmp; ) {
		ans.push_back(tmp);
	}

	return ans;
}

int dp[21][4040];

int func(int id, int s) {
	if (s == sum) {
		return 2;
	} else if (id >= N) {
		return 1;
	} else {
		int& ans = dp[id][s];

		if (ans == -1) {
			ans = func(id + 1, s);

			if (ans == 1) {
				ans = func(id + 1, s + P[id]);
			}
		}
		
		return ans;
	}
}


int main(void) {
	cin >> T;
	getline(cin, S);
	for ( ; T--; ) {
		getline(cin, S);
		
		P = split(S);
		N = (int) P.size();

		sum = accumulate(P.begin(), P.end(), 0);
		bool ok = false;

		if (sum % 2 == 0) {		
			memset(dp, -1, sizeof(dp));
			sum /= 2;
			ok = (func(0, 0) == 2);
		}
		
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}
