#include <bits/stdc++.h>

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

const int MAXN = 210;
const Int INF = 1001000010010LL;

int N, M;

int A[5050];
int B[5050];

Int D, K, DD;
Int C[5050];

Int cap[MAXN][MAXN], cost[MAXN][MAXN], fnet[MAXN][MAXN], adj[MAXN][MAXN], deg[MAXN], par[MAXN], d[MAXN], pi[MAXN];

void add_edge(int f, int t, Int cst, Int flow) {
    cap[f][t] = flow;
    cost[f][t] = cst;
}

bool dijkstra(int n, int s, int t) {
    for(int i = 0; i < n; i++) d[i] = INF, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;

    while(1) {
        Int u = -1, bestD = INF;

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

Int flow(int n, int s, int t, Int &fcost) {
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

    Int flow = fcost = 0LL;

    while(dijkstra(n, s, t)) {
        Int bot = INF;
        for(int v = t, u = par[v]; v != s; u = par[v]) {
            bot = min(bot, (Int) (fnet[v][u] ? fnet[v][u] : (cap[u][v] - fnet[u][v])));
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


int main(void) {
    int i;
    int j;

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < MAXN; i++) {
            deg[i] = par[i] = d[i] = pi[i] = 0;
            for (j = 0; j < MAXN; j++) {
                cap[i][j] = cost[i][j] = fnet[i][j] = adj[i][j] = 0;
            }
        }

        for (i = 0; i < M; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        cin >> D >> K;

        DD = D;

        for (i = 0; i < M; i++) {
            add_edge(A[i], B[i], C[i], K);
            add_edge(B[i], A[i], C[i], K);
        }

        add_edge(0, 1, 0, D);

        Int fcost;
        Int max_flow = flow(MAXN, 0, N, fcost);

        if (max_flow == D) {
            printf("%lld\n", fcost);
        } else {
            puts("Impossible.");
        }
    }

    return 0;
}
