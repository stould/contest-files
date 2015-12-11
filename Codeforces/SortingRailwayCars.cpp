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

const int MAXN = 100005;
const int INF = INT_MAX / 4;

int N;
int P[MAXN];
int posA[MAXN];
int dp[MAXN][3];

int func(int pos, int is_after) {
	if (pos == N) {
		return is_after ? 0 : 1;
	} else {
		int& ans = dp[pos][is_after];

		if (ans == -1) {
			ans = INF;
			
			if (is_after) {
				ans = func(pos + 1, posA[pos + 1] > posA[pos]);
			} else {
				//move left
				chmin(ans, 1 + func(pos + 1, 0));
				//move right

				chmin(ans, pos + func(pos + 1, posA[pos + 1] > posA[pos]));
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		posA[P[i]] = i;
	}

	if (N == 1) {
		cout << "0\n";
	} else {
		memset(dp, -1, sizeof(dp));
		cout << func(2, posA[2] > posA[1]) << "\n";
	}
	
	return 0;
}
