#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

#define MAXN 210
#define INF 100000

int i, j, test, n, m, next, capacity[MAXN][MAXN];
vector<int> graph[MAXN];

int max_flow(int source, int sink) {
    int residual[MAXN][MAXN];
    memset(residual, 0, sizeof(residual));

    while(1) {
        int prev[MAXN]; memset(prev, -1, sizeof(prev));
        int actual[MAXN]; memset(actual, 0, sizeof(actual));
        prev[source] = source;
        actual[source] = INF;

        queue<int> q; q.push(source);

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if(capacity[u][v] - residual[u][v] > 0 && prev[v] == -1) {
                    printf("%d %d\n", u, v);
                    prev[v] = u;
                    actual[v] = min(actual[u], capacity[u][v] - residual[u][v]);
                    if(v != sink) {
                        q.push(v);
                    } else {
                        while(prev[v] != v) {
                            u = prev[v];
                            residual[u][v] += actual[sink];
                            residual[v][u] -= actual[sink];
                            v = u;
                        }
                        goto end;
                    }
                }
            }
        }
        end:;
        if(prev[sink] == -1) {
            int ans = 0;
            for(int i = 1; i <= n; i++) {
                ans += residual[source][i];
            }
            return ans;
        }
    }
    return 0;
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &test);
    for(; test-- > 0; ) {
        scanf("%d", &n);
        REP(i, MAXN) {
            graph[i].clear();
        }
        memset(capacity, 0, sizeof(capacity));
        REP(i, n-1) {
            scanf("%d", &m);
            REP(j, m) {
                scanf("%d", &next);
                graph[i+1].push_back(next);
                graph[next].push_back(i+1);
                capacity[i+1][next] = INF;
                capacity[next][i+1] = INF;
            }
        }
        capacity[1][n] = capacity[n][1] = 1;
        printf("%d\n", max_flow(1, n));
    }
    return 0;
}

