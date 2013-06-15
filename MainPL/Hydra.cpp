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

const int MAXN = 200109;
int N, r, to, vis[MAXN];
ll cut[MAXN], kill[MAXN], dp[MAXN];
vector<int> graph[MAXN];

ll dfs(int now) {
    if(dp[now] != -1LL) return dp[now];
    if(vis[now] == 1) return INT_MAX;
    vis[now] = 1;

    ll to_kill = kill[now];
    ll to_cut = cut[now];

    REP(i, (int) graph[now].size())  {
        to_cut += dfs(graph[now][i]);
    }

    return dp[now] = min((ll)to_cut, (ll)to_kill);
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);

    memset(vis, 0, sizeof(vis));

    REP(i, N) {
        scanf("%lld%lld%d", &cut[i], &kill[i], &r);
        REP(j, r) {
            scanf("%d", &to);
            graph[j].push_back(to-1);
        }
    }

    memset(dp, -1LL, sizeof(dp));
    printf("%lld\n", dfs(0));

    return 0;
}
