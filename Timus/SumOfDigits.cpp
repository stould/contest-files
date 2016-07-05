#include <iostream>
#include <map>
#include <string.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int dp[901][8110];
int T, N, M;
string ans;

int func(int pos, int sum, int s_pow) {
	if (sum > N || s_pow > M || pos >= 100) {
		return 0;
	} else if (sum == N && s_pow == M) {
		return 1;
	} else {
		int& ans = dp[sum][s_pow];
		
		if (ans == -1)  {
			ans = 0;
			
			for (int i = 9; ans == 0 && i >= 1; i--) {
				ans |= func(pos + 1, sum + i, s_pow + i * i);
			}
		}
		
		return ans;
	}
}

void rec(int pos, int sum, int s_pow) {
	if (sum > N || s_pow > M || pos >= 100) {
		return;
	} else if (sum == N && s_pow == M) {
		return;
	} else {
		for (int i = 9; i >= 1; i--) {
			if (func(pos + 1, sum + i, s_pow + i * i)) {
				ans = char('0' + i) + ans;
				rec(pos + 1, sum + i, s_pow + i * i);
				break;
			}
		}		
	}
}


int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		memset(dp, -1, sizeof(dp));
		
		int can = func(0, 0, 0);

		if (can) {
			ans = "";
			rec(0, 0, 0);
			cout << ans << "\n";
		} else {
			cout << "No solution\n";
		}
	}
	
	return 0;
}
