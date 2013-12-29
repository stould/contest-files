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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class BlackBoxDiv2 {
public:
	int count(string, string);
};

const int MOD = 1000000007;

int dp[60][60];
int N, M;

string front, side;

int func(int i, int j) {
	if (i == N && j == M) {
		return 1;
	} else {
		int& ans = dp[i][j];
		
		if (ans == -1) {
			ans = 0;
			
			if (front[i] == 'B') {
				ans = 1 + (ans + func(i + 1, j)) % MOD;
			}
			if (side[j] == 'B') {
				ans = 1 + (ans + func(i, j + 1)) % MOD;
			}
		}
		
		return ans;
	}
}

int BlackBoxDiv2::count(string ffront, string sside) {
	memset(dp, -1, sizeof(dp));
	
	N = (int) front.size();
	M = (int) side.size();
	
	front = ffront;
	side = sside;
	
	return func(0, 0);
}

//Powered by [KawigiEdit] 2.0!
