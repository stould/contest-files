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

int A, B;
string curr;
int dp[12][12][2][12];
int ans[12];

int func(int pos, int cnt, int prefix, int goal, int seen_non_zero, int last) {
	if (pos == (int) curr.size()) {
		return cnt;
	} else {
		int& ans = dp[pos][cnt][prefix][last];

		if (ans == -1) {
			ans = 0;

			int now = curr[pos] - '0';
			
			for (int i = 0; i < 10; i++) {
				if (prefix && i > now) {										
					continue;
				}
								
				int add = i == goal;
				
				if (i == 0 && goal == 0) {
					if (!seen_non_zero) {
						add = 0;
					}
				}
				ans += func(pos + 1, cnt + add, (prefix && i == now) ? 1 : 0, goal, (seen_non_zero || (i != 0)) ? 1 : 0, i);
			}
		}
		
		return ans;
	}
}

void buildAnswer() {
	curr = to_string(B);
	for (int i = 0; i < 10; i++) {
		memset(dp, -1, sizeof(dp));		
		ans[i] = func(0, 0, 1, i, 0, 10);
	}
	curr = to_string(A - 1);
	for (int i = 0; i < 10; i++) {
		memset(dp, -1, sizeof(dp));
		ans[i] -= func(0, 0, 1, i, 0, 10);
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	while (cin >> A >> B && !(A == 0 && B == 0)) {
		buildAnswer();
		for (int i = 0; i < 10; i++) {
			if (i > 0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}
