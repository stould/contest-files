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

const int MAXN = 110;

int T, N;
string S;
string dp[MAXN][MAXN];
int mark[MAXN][MAXN];

string func(int l, int r) {
	if (l == r) {		
		if (S[l] == '(' || S[l] == ')') {
			return "()";
		} else {
			return "[]";
		}
	} else {
		string& ans = dp[l][r];

		if (mark[l][r] == -1) {
			mark[l][r] = 1;

			/*
			  (..) => ..
			  [..] => ..
			  (..( => ()..
			  ))
			  )(
			*/

			if ((S[l] == '(' && S[r] == ')') || (S[l] == '[' && S[r] == ']')) {
				ans = S[l] + func(l + 1, r - 1) + S[r];
			} else {
				for (int i = l; i < r; i++) {
					
				}
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> S;
		N = (int) S.size();

		memset(mark, -1, sizeof(mark));

		cout << func(0, N - 1) << "\n";
	}
	return 0;
}
