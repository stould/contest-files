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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 18;
int i, j, ans, N, M, vis[MAXN][MAXN];
char mp[MAXN][MAXN];

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool ok(int i, int j) {
    return i >= 0 && j >= 0 && i < N && j < M;
}

int func(int i, int j) {
    vis[i][j] = 1;
    int k, all = mp[i][j] - '0';
    REP(k, 8) {
        int ii = i + dx[k];
        int jj = j + dy[k];

        if(ok(ii, jj) && mp[ii][jj] == '*') {
            if(vis[ii][jj]) {
                all -= 1;
            } else {
                vis[ii][jj] = 1;
            }
        }
    }
    return all;
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(2 == scanf("%d%d", &N, &M) && N + M != 0) {
        REP(i, N) {
            scanf("%s", mp[i]);
        }
        memset(vis, 0, sizeof(vis));
        ans = 0;
        REP(i, N) REP(j, M) {
            if(mp[i][j] >= '0' && mp[i][j] <= '9') {
                ans += func(i, j);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

