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
#include <numeric>
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

int K, N;
double dp[109][11];

int main(void) {
    int i, j;
    for ( ; scanf("%d%d", &K, &N) == 2; ) {
        double pos = 0.0;

        memset(dp, 0, sizeof(dp));

        for (i = 0; i <= K; i++) dp[0][i] = 1.0;

        for (i = 1; i < N; i++) {
            for (j = 0; j <= K; j++) {
                dp[i][j] += dp[i - 1][j];

                if (j - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= K) {
                    dp[i][j] += dp[i - 1][j + 1];
                }
            }
        }

        for (i = 0; i <= K; i++) pos += (double) dp[N - 1][i];

        printf("%.5lf\n", (double) pos * 100.0 / pow(K + 1, N));
    }
    return 0;
}
