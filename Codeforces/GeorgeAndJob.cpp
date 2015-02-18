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

const int MAXN = 5050;
const Int INF = 1001010010001000LL;

int N, M, K, L;
int P[MAXN];
Int S[MAXN];

Int dp[MAXN][MAXN];

Int func(int id, int used) {
	if (used == K) {
		return 0LL;
	} else if (id > N) {
		return -INF;        
    } else {
        Int& ans = dp[id][used];

        if (ans == -1LL) {
            ans = func(id + 1, used);

            chmax(ans, S[id] - S[id - M] + func(id + M, used + 1));
        }

        return ans;
    }
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
		S[i] = S[i - 1] + P[i];		
    }

    memset(dp, -1LL, sizeof(dp));
    
    cout << func(M, 0) << "\n";

    return 0;
}
