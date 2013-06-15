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

void split(vector<int>& v, const string& s) {
    istringstream ss(s, istringstream::in);
    v.clear(); int t;
    while(ss >> t) {
        v.push_back(t);
    }
}

const int MAXN = 309;
ll dp[MAXN][MAXN];
string str;

void build(int N) {
    int i, j, k;

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            dp[i][j] = 0LL;
        }
    }

    dp[0][0] = 1LL;

    for (i = 1; i <= N; i++) dp[i][0] = 1LL;

    for (i = 1; i <= N; i++) {
        for (j = i; j <= N; j++) {
            for (k = 1; k <= N; k++) {
                dp[j][k] += dp[j-i][k-1];
            }
        }
    }
}

int main(void) {
    int i;

    build(300);

    for ( ; getline(cin, str); ) {
        vector<int> vs; split(vs, str);

        ll ans = 0LL;

        if (vs.size() == 1) {
            for (i = 0; i <= vs[0]; i++) {
                ans += dp[vs[0]][i];
                printf("%lld\n", dp[vs[0]][i]);
            }
        } else if (vs.size() == 2) {
            ans = dp[vs[0]][vs[1]];
        } else {
            ans = dp[vs[0]][vs[1]-1] - dp[vs[0]][vs[2]];
        }

        printf("%lld\n", ans);
    }
    return 0;
}
