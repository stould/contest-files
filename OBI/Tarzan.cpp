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

const int MAXN = 1010;
int N, D, vis[MAXN];
vector<int> graph[MAXN];
pair<int, int> vp[MAXN];

void dfs(int x) {
    vis[x] = 1;

    REP(i, graph[x].size()) {
        int next = graph[x][i];

        if(!vis[next]) {
            dfs(next);
        }
    }
}

int main(void) {
    for( ; scanf("%d%d", &N, &D) == 2; ) {
        REP(i, N) {
            scanf("%d%d", &vp[i].first, &vp[i].second);
            REP(j, i) {
                double dist = (double) hypot(vp[i].first - vp[j].first, vp[i].second - vp[j].second);
                if(dist <= D) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        bool check = true;

        dfs(0);

        REP(i, N) check &= vis[i];

        if(check) {
            puts("S");
        } else {
            puts("N");
        }
    }
    return 0;
}
