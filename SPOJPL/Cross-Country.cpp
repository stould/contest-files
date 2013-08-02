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

const int MAXN = 2007;
int T;
char str[2000007];
int dp[MAXN][MAXN];

vector<int> split(string str) {
    istringstream ss(str);
    int tmp;

    vector<int> ans;

    while (ss >> tmp) {
        ans.push_back(tmp);
    }

    return ans;
}

int lcs(int x, int y, vector<int>& a, vector<int>& b) {
    if (x >= a.size() || y >= b.size()) {
        return 1;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    if (a[x] == b[y]) {
        return dp[x][y] = 1 + lcs(x + 1, y + 1, a, b);
    } else {
        return dp[x][y] = max(lcs(x + 1, y, a, b), lcs(x, y + 1, a, b));
    }
}

int main(void) {
    T = in();

    cin.ignore();

    for ( ; T--; ) {
        gets(str);
        vector<int> a = split(string(str));

        int i, ans = 0;

        for ( ; ; ) {
            gets(str);
            vector<int> b = split(string(str));

            if (b.size() == 1) break;

            memset(dp, -1, sizeof(dp));

            ans = max(ans, lcs(0, 0, a, b)-1);
        }

        printf("%d\n", ans-1);
    }
    return 0;
}
