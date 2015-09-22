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

const int INF = INT_MAX / 3;

string S;
int N;
int dp[1010][30];

int forward(char aa, char bb) {
	int a = aa - 'a';
	int b = bb - 'a';
	
	if (b >= a) {
		return b - a;
	} else {
		return ((26 - a) + b);
	}
}

int backward(char aa, char bb) {
	int a = aa - 'a';
	int b = bb - 'a';

	if (b <= a) {
		return a - b;
	} else {
		return (a + (26 - b));
	}
}

int func(int pos, int fm) {
	if (pos == N) {
		return 0;
	} else {
		int& ans = dp[pos][fm];

		if (ans == -1) {
			ans = INF;
			
			char curr = 'a' + fm;

			int f = forward(curr, S[pos]);
			int b = backward(curr, S[pos]);
			
			//cout << pos << " " << fm << " " << curr << " " << S[pos] << " " << f << " "  << b << "\n";
			
			chmin(ans, f + func(pos + 1, 0));
			chmin(ans, b + func(pos + 1, 0));
			
			int wf = ((fm + f) % 26) % 26;
			int wb = ((fm - b + 26) % 26) % 26;
			
			chmin(ans, f + func(pos + 1, wf));
			chmin(ans, b + func(pos + 1, wb));

			for (int i = 0; i < 26; i++) {
				char curr = 'a' + i;

				int f = forward(curr, S[pos]);
				int b = backward(curr, S[pos]);

				chmin(ans, f + func(pos + 1, b));
				chmin(ans, b + func(pos + 1, b));
			}
		}
		
		return ans;
	}
}

int main(void) {
	while (cin >> S && S != "*") {
		memset(dp, -1, sizeof(dp));
		N = (int) S.size();
		cout << func(0, 0) << "\n";
	}
	return 0;
}
