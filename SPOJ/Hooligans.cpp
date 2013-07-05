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
    if (!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1700;
const int INF = 10010100;

//flow
vector<int> graph[MAXN];
int capacity[MAXN][MAXN];
int residual[MAXN][MAXN];

int max_flow(int source, int sink) {
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
            for(int i = 2; i < MAXN; i++) {
                if (residual[source][i] != capacity[source][i]) return false;
            }
            return true;
        }
    }
}
//endflow

int N, M, G, A, B;
char ot;

int cnt[45][45];
int w[45], r[45];


int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    int i, j;

    for ( ; scanf("%d%d%d", &N, &M, &G) == 3 && (N + M + G != 0); ) {
        for (i = 0; i < MAXN; i++) {
            graph[i].clear();

            if (i <= N) r[i] = (N - 1) * M;
        }

        memset(w, 0, sizeof(w));
        memset(cnt, 0, sizeof(cnt));
        memset(capacity, 0, sizeof(capacity));
        memset(residual, 0, sizeof(residual));

        int s = 0, t = N*N+1;

        for (i = 0; i < G; i++) {
            scanf("%d %c%d", &A, &ot, &B);

            A += 1; B += 1;

            if (ot == '<') {
                w[B] += 1;
            } else if (ot == '>') {
                w[A] += 1;
            } else {
                w[A] += 1;
                w[B] += 1;
            }

            r[A] -= 1;
            r[B] -= 1;

            cnt[A][B] += 1;
            cnt[B][A] += 1;
        }

        for (i = 2; i <= N; i++) {
            graph[i].push_back(t); capacity[i][t] = w[1] + r[1] - w[i];

            for (j = 2; j < i; j++) {
                int f = M - cnt[i][j];

                if (f > 0) {
                    cnt[i][j] = cnt[j][i] = 0;

                    graph[s].push_back(i * N + j); capacity[s][i * N + j] = f;

                    graph[i * N + j].push_back(i); capacity[i * N + j][i] = INF;
                    graph[i * N + j].push_back(j); capacity[i * N + j][j] = INF;
                }
            }
        }

        printf("%c\n", max_flow(s, t) ? 'Y' : 'N');
    }
    return 0;
}
