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

int N;
string A;

int dp[100005][5][2][2];

char inv(int s) {
	if (s == 0) return 1;
	else if (s == 1) return 0;
	return 3;
}


int func(int pos, int last, int in_use, int used) {
	if (pos == N) {
		return 0;		
	} else {
		int& ans = dp[pos][last][in_use][used];

		if (ans == -1) {
			ans = 0;
			
			int curr = A[pos] - '0';
			
			if (used) {
				if (curr == inv(last)) {
					chmax(ans, 1 + func(pos + 1, curr, 0, 1));
				} else {
					chmax(ans, func(pos + 1, last, 0, 1));
				}
			} else {
				if (in_use) {
					curr = inv(curr);

					if (curr == inv(last)) {
						chmax(ans, 1 + func(pos + 1, curr, 1, 0));
						chmax(ans, 1 + func(pos + 1, curr, 0, 1));
					} else {
						chmax(ans, func(pos + 1, last, 1, 0));
						chmax(ans, func(pos + 1, last, 0, 1));
					}					
				} else {
					if (curr == inv(last)) {
						chmax(ans, 1 + func(pos + 1, curr, 0, 0));
						chmax(ans, 1 + func(pos + 1, curr, 1, 0));
					} else {
						chmax(ans, func(pos + 1, last, 0, 0));
						chmax(ans, func(pos + 1, last, 1, 0));
					}
				}
			}
		}
		
		return ans;
	}
}

int check(string& S, int s) {
	int ans = 1;
	char last = S[s];

	for (int i = s + 1; i < N; i++) {
		if (S[i] != last) {
			ans += 1;
			last = S[i];
		}
	}
	
	
	return ans;
}

char inv(char s) {
	if (s == '0') return '1';
	return '0';
}

int ansA(string S) {
	for (int i = 1; i < N; i++) {
		if (S[i - 1] == S[i]) {
			S[i] = inv(S[i]);
			break;
		}
	}

	int ans = check(S, 0);
	
	for (int i = 1; i < N; i++) {
		if (S[i] != S[0]) {
			chmax(ans, check(S, i));
			break;
		}
	}
	return ans;	
}

int ansB(string S) {
	int s = 0, e = 0;
	
	for (int i = 1; i < N; i++) {
		int bs = i - 1;
		bool ok = false;
		int be;
		
		int len = 1;
		
		int j = i;

		while (j < N && S[j] != S[j - 1]) {
			be = j;
			j += 1;
			len += 1;
			ok = true;
		}

		if (ok) {
			if (be - bs + 1 > e - s + 1) {
				s = bs;
				e = be;
			}
		}
	}

	int ans = check(S, 0);
	
	for (int i = 1; i < N; i++) {
		if (S[i] != S[0]) {
			chmax(ans, check(S, i));
			break;
		}
	}

	for (int i = s; i <= e; i++) {
		S[i] = inv(S[i]);
	}

	chmax(ans, check(S, 0));
	
	for (int i = 1; i < N; i++) {
		if (S[i] != S[0]) {
			chmax(ans, check(S, i));
			break;
		}
	}
	return ans;
}



int main(void) {
	cin >> N >> A;

	memset(dp, -1, sizeof(dp));

	cout << max(func(0, 0, 0, 0), func(0, 1, 0, 0)) << "\n";
	
	return 0;
}
