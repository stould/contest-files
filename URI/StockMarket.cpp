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

const int MAXN = 200005;

int N, C;
int P[MAXN];
Int dp[MAXN][2];
bool seen[MAXN][2];

Int func(int id, int has) {
    if (id == N - 1) {
        return has ? P[id] : 0;
    } else {
        Int& ans = dp[id][has];

        if (!seen[id][has]) {
            seen[id][has] = true;
			
            ans = 0;
			
            if (has) {
                chmax(ans, func(id + 1, 1));
                chmax(ans, P[id] + func(id + 1, 0));
            } else {
                chmax(ans, func(id + 1, 0));
                chmax(ans, -C - P[id] + func(id + 1, 1));
            }
        }
		
        return ans;
    }
}

int main(void) {
    while (cin >> N >> C) {
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        memset(seen, false, sizeof(seen));

        cout << max(0LL, func(0, 0)) << endl;
    }
    return 0;
}
