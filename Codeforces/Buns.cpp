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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXM = 13;
const int MAXN = 1010;
int N, M;

int A[MAXM], B[MAXM], C[MAXM], D[MAXM];
int dp[MAXN];

int main(void) {
    N = in(), M = in();

    int i, j, x;

    C[0] = in(); D[0] = in();

    dp[0] = 0;

    for (i = C[0]; i <= N; i++) {
        dp[i] = dp[i - C[0]] + D[0];
    }

    for (i = 1; i <= M; i++) {
        A[i] = in();
        B[i] = in();
        C[i] = in();
        D[i] = in();


        for (x = 0; x < A[i] / B[i]; x++) {
            for (j = N; j >= C[i]; j--) {
                dp[j] = max(dp[j], dp[j - C[i]] + D[i]);
            }
        }
    }

    printf("%d\n", *max_element(dp, dp + N + 1));

    return 0;
}
