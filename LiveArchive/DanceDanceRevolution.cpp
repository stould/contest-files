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

const int MAXN = 10010;

int N;

char str[10001];

vector<int> split (string str) {
    istringstream ss(str);
    int tmp;

    vector<int> ans;

    for ( ; ss >> tmp; ) {
        ans.push_back(tmp);
    }

    return ans;
}

Int dp[MAXN][5][5];
int V[MAXN];

int move(int f, int t) {
    if (f == 0) return 2;
    if (f == t) return 1;
    if (f == 2 && t == 4) return 4;
    if (f == 4 && t == 2) return 4;
    if (f == 1 && t == 3) return 4;
    if (f == 3 && t == 1) return 4;
    return 3;
}

Int func(int index, int left, int right) {
    if (index == N) return 0LL;

    Int& ans = dp[index][left][right];

    if (ans != -1) return ans;


    ans = 100101010010010LL;

    chmin(ans, move(left, V[index]) + func(index + 1, V[index], right));

    chmin(ans, move(right, V[index]) + func(index + 1, left, V[index]));

    return ans;
}

int main(void) {
    int a;

    while( scanf( "%d", &a ), a ) {
        V[0] = a;
        N = 0;
        while ( scanf( "%d", &V[++N]), V[N] );

        memset(dp, -1LL, sizeof(dp));

        printf("%lld\n", func(0, 0, 0));
    }
    return 0;
}
