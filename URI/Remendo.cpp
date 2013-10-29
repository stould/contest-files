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

const int MAXN = 1010;
const int INF = 10101010;

int a[1000000];

int N, C, T1, T2;

int dp[MAXN];
int v[MAXN];

int func(int index) {
    if (index >= N) return 0;

    int& ans = dp[index];

    if (ans != -1) return ans;

    int i;

    ans = INF;

    i = index + 1;
    while (i < N && v[i] - v[index] <= T1) i++;
    chmin(ans, T1 + func(i));


    i = index + 1;
    while (i < N && v[i] - v[index] <= T2) i++;
    chmin(ans, T2 + func(i));

    return ans;
}

int main(void) {
    for ( ; cin >> N >> C >> T1 >> T2; ) {
        int i;

        for (i = 0; i < N; i++) cin >> v[i];

        memset(dp, -1, sizeof(dp));

        printf("%d\n", func(0));
    }
    return 0;
}
