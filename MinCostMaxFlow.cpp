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

const int MAXN = 110;
const ll INF = 901010100101010LL;
int A, B, C, N, M, D, K, DD;
vector<pair<int, int> > connections;

ll cap[MAXN][MAXN], cost[MAXN][MAXN], fnet[MAXN][MAXN], adj[MAXN][MAXN], deg[MAXN], par[MAXN], d[MAXN], pi[MAXN];

bool dijkstra(int n, int s, int t) {
    for(int i = 0; i < n; i++) d[i] = INF, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;

    while(1) {
        ll u = -1, bestD = INF;

        for(int i = 0; i < n; i++) if(par[i] < 0 && d[i] < bestD) bestD = d[u = i];

        if(bestD == INF) break;

        par[u] = -par[u] - 1;

        for(int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];

            if(par[v] >= 0LL) continue;

            if(fnet[v][u] && d[v] > (d[u] + pi[u] - pi[v]) - cost[v][u]) {
                d[v] = (d[u] + pi[u] - pi[v]) - cost[v][u], par[v] = -u - 1;
            }

            if(fnet[u][v] < cap[u][v] && d[v] > (d[u] + pi[u] - pi[v]) + cost[u][v]) {
                d[v] = (d[u] + pi[u] - pi[v]) + cost[u][v], par[v] = -u - 1;
            }
        }
    }

    for(int i = 0; i < n; i++) if(pi[i] < INF) pi[i] += d[i];

    return par[t] >= 0LL;
}

int mcmf3(int n, int s, int t, ll &fcost) {
    memset(deg, 0LL, sizeof(deg));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cap[i][j] || cap[j][i]) {
                adj[i][deg[i]++] = j;
            }
        }
    }

    memset(fnet, 0LL, sizeof(fnet));
    memset(pi, 0LL, sizeof(pi));

    ll flow = fcost = 0LL;

    while(dijkstra(n, s, t)) {
        ll bot = INF;
        for(int v = t, u = par[v]; v != s; u = par[v]) {
            bot = min(bot, (ll) (fnet[v][u] ? fnet[v][u] : (cap[u][v] - fnet[u][v])));
            v = u;
        }
        for(int v = t, u = par[v]; v != s; u = par[v = u]) {
            if(fnet[v][u]) {
                fnet[v][u] -= bot;
                fcost -= bot * cost[v][u];
            } else {
                fnet[u][v] += bot;
                fcost += bot * cost[u][v];
            }
        }
        flow += bot;
    }
    return flow;
}

int instances = 1;

int main(void) {
    return 0;
}

