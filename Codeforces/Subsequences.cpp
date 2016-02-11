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
const int MAXM = 15;

int N, K;
int P[MAXN];
uInt values[MAXM][MAXN];
uInt dp[MAXN][MAXM];

void increase(int index_i, int index_j, Int add) {	
	for (int i = index_i; i <= N; i += (i & -i)) {
		values[index_j][i] += add;		
	}
}
uInt read(int index_i, int index_j) {
	uInt sum = 0;

	for (int i = index_i; i > 0; i -= (i & -i)) {
		sum += values[index_j][i];		
	}
	
	return sum;
}

int main(void) {
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	for (int i = 0; i < N; i++) {
		increase(P[i], 1, 1);

		for (int k = 2; k <= K + 1; k++) {
			uInt sm = read(P[i] - 1, k - 1);
			increase(P[i], k, sm);
		}
	}
	
	uInt ans = read(N, K + 1);
	
	cout << ans << "\n";
	
	return 0;
}
