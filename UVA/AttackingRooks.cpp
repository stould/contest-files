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

#define debug(x) cerr << "debug x = " << x << "\n"

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

const int INF = 1010100100;
const int MAXN = 110 * 10 + 10;

vector<int> graph[MAXN];
int capacity[MAXN][MAXN];
int residual[MAXN][MAXN];
int prev[MAXN];
int actual[MAXN];

int max_flow(int source, int sink) {
    memset(residual, 0, sizeof(residual));
    while(1) {
        memset(prev, -1, sizeof(prev));
        memset(actual, 0, sizeof(actual));

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
            int sum = 0;
            for(int i = 0; i < MAXN; i++) {
                sum += residual[source][i];
            }
            return sum;
        }
    }
}

int N;
string str[110];

int conv(int i, int j) {
    return N * (i + 1) + j + 1;
}

void add_edge(int a, int b, int c) {
    graph[a].push_back(b);
    graph[b].push_back(a);

    capacity[a][b] = c;
    capacity[b][a] = 0;
}

int deg[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    int i, j, k;

    for ( ; cin >> N; ) {
        for (i = 0; i < MAXN; i++) {
            for (j = 0; j < MAXN; j++) {
                capacity[i][j] = 0;
            }
            deg[i] = 0;
            graph[i].clear();
        }
        for (i = 0; i < N; i++) {
            cin >> str[i];

            for (j = 0; j < N; j++) deg[i] += (str[i][j] == 'X');
        }

        int source = 0, sink = N * N + 2;

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) if (i != j) {
                add_edge(i + 1, N + j + 1, deg[i]);
            }
        }

        for (i = 0; i < N; i++) {
            add_edge(source, i + 1, 1);
            add_edge(N + i + 1, sink, 10000);
        }

        int flow = max_flow(source, sink);

        cout << flow << "\n";
    }

    return 0;
}
