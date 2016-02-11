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

<<<<<<< HEAD
int main(void) {
=======
const int MAXN = 110;
const int INF = 450 * 150;

int T, N;
int P[MAXN];
int dp[MAXN][MAXN];
bool memo[MAXN][MAXN];
int A, B;

int func(int pos, int in_a) {
	if (pos == N) {
		return abs(in_a - (N / 2)) <= 1 ? 0 : INF;
	} else {
		int& ans = dp[pos][in_a];

		if (!memo[pos][in_a]) {
			memo[pos][in_a] = true;
			
			int a = +P[pos] + func(pos + 1, in_a + 1);
			int b = -P[pos] + func(pos + 1, in_a);

			if (abs(a) <= abs(b)) {
				ans = a;
			} else {
				ans = b;
			}
		}

		return ans;
	}
}

void path(int pos, int in_a) {
	if (pos == N) {
		return;
	} else {
		int a = +P[pos] + func(pos + 1, in_a + 1);
		int b = -P[pos] + func(pos + 1, in_a);
		
		if (abs(a) <= abs(b)) {
			A += P[pos];
			path(pos + 1, in_a + 1);
		} else {
			B += P[pos];
			path(pos + 1, in_a);
		}	
	}
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		
		memset(memo, false, sizeof(memo));
		A = B = 0;
		
		path(0, 0);
		cout << func(0, 0) << "\n";
		cout << min(A, B) << " " << max(A, B) << "\n";
	}
>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c
	return 0;
}
