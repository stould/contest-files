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

const int INF = 1000000009;
const int MAXN = 10000100;
int T, N, h[MAXN], w[MAXN], dp[MAXN];

int lis(void) {
    for(int i = 0; i < N; i++) {
        dp[i] = w[i];
        for(int j = 0; j < i; j++) {
            if(h[i] > h[j]) {
                dp[i] = max(dp[i], dp[j] + w[i]);
            }
        }
    }
    return *max_element(dp, dp + N);
}

int test = 1;

int main(void) {
    scanf("%d", &T);

    for( ; T--; ) {
        scanf("%d", &N);

        REP(i, N) scanf("%d", &h[i]);
        REP(i, N) scanf("%d", &w[i]);


        int A = lis();
        reverse(h, h + N);
        reverse(w, w + N);
        int B = lis();

        if(A >= B) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", test++, A, B);
        } else {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", test++, B, A);
        }
    }
    return 0;
}
