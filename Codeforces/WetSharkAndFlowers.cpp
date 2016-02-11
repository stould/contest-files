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

const Int MAX_V = 1000000000LL;
const int MAXN = 100005;

int N, P;
int L[MAXN], R[MAXN];
bool seen[MAXN][2][2];
double dp[MAXN][2][2];

int valid(int i, int j) {
	return max(0, j / P - (i - 1) / P);
}

double func(int curr, int was_mult, int is_f_mult) {
	if (curr == N) {
		return 0;
	} else {
		double& ans = dp[curr][was_mult][is_f_mult];

		if (!seen[curr][was_mult][is_f_mult]) {
			ans = 0.0;

			int can = valid(L[curr], R[curr]);
			int len = R[curr] - L[curr] + 1;

			if (curr == 0) {
				if (can) {
					ans += (can / (double) len) * func(curr + 1, 1, 1);
				}
				if (len - can) {
					ans += (len - can) / (double) len * func(curr + 1, 0, 0);
				}
			} else if (curr == N - 1) {
				if (is_f_mult) {
					if (was_mult) {
						if (can) {
							ans += 2000 + (can / (double) len) * func(curr + 1, 1, is_f_mult);
						}
						if (len - can) {
							ans += 2000 + (len - can) / (double) len * func(curr + 1, 0, is_f_mult);
						}
					} else {
						if (can) {
							ans += 2000 + (can / (double) len) * func(curr + 1, 1, is_f_mult);
						}
						if (len - can) {
							ans += 1000 + (len - can) / (double) len * func(curr + 1, 0, is_f_mult);
						}
					}
				} else {
					if (was_mult) {
						if (can) {
							ans += 2000 + (can / (double) len) * func(curr + 1, 1, is_f_mult);
						}
						if (len - can) {
							ans += 1000 + (len - can) / (double) len * func(curr + 1, 0, is_f_mult);
						}
					} else {
						if (can) {
							ans += 2000 + (can / (double) len) * func(curr + 1, 1, is_f_mult);
						}
						if (len - can) {
							ans += (len - can) / (double) len * func(curr + 1, 0, is_f_mult);
						}
					}
				}
			} else {						
				if (was_mult) {
					if (can) {
						ans += 1000 + (can / (double) len) * func(curr + 1, 1, is_f_mult);
					}
					if (len - can) {
						ans += 1000 + (len - can) / (double) len * func(curr + 1, 0, is_f_mult);
					}
				} else {
					if (can) {
						ans += 1000 + (can / (double) len) * func(curr + 1, 1, is_f_mult);
					}
					if (len - can) {
						ans += (len - can) / (double) len * func(curr + 1, 0, is_f_mult);
					}
				}
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N >> P;

	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}
	
	double ans = func(0, 0, 1);
	
	cout << fixed << setprecision(6) << ans << endl;

	return 0;
}
