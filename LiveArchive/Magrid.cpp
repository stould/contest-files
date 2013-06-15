#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 510;
int T, N, M, grid[MAXN][MAXN], dp[MAXN][MAXN], path[MAXN][MAXN][2];

//to avoid memset
int func(int x) {
    return x > 0 ? x : -10000000;
}

int do_dp(int source){
    dp[0][0] = source;
    for(int j = 1; j < M; j++) {
        dp[0][j] = func(dp[0][j-1]+grid[0][j]);
    }
    for(int i = 1; i < N; i++) {
        dp[i][0] = func(dp[i-1][0] + grid[i][0]);
        for(int j = 1; j < M; j++) {
            dp[i][j] = func(max(dp[i-1][j], dp[i][j-1]) + grid[i][j]);
        }
    }
    return dp[N-1][M-1];
}

int main(void) {
    scanf("%d", &T);
    for( ; T-- ; ) {
        scanf("%d%d", &N, &M);
        REP(i, N) REP(j, M) {
            scanf("%d", &grid[i][j]);
        }

        int low = 1, high = 1000000010, mid;

        while(low <= high) {
            mid = (low+high)/2;
            if(do_dp(mid) <= 0) low = mid + 1;
            else high = mid - 1;
        }
        printf("%d\n", low);
    }
    return 0;
}
