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

int T;
int N, M;

map<string, int> mp;

void build(void) {
    mp["XS"] = 1;
    mp["S"] = 2;
    mp["M"] = 3;
    mp["L"] = 4;
    mp["XL"] = 5;
    mp["XXL"] = 6;
}

const int MAXN = 100;
const int INF = 1010101;

vector<int> graph[MAXN];
int capacity[MAXN][MAXN];
int residual[MAXN][MAXN];

void add_edge(int u, int v, int c) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    capacity[u][v] = c;
    capacity[v][u] = 0;
}

int max_flow(int source, int sink) {
    //memset(residual, 0, sizeof(residual));
    int prev[MAXN], actual[MAXN];
    while(1) {
        memset(prev,  -1, sizeof(prev));
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
    return -1;
}

string A, B;


int main(void) {
    T = in();

    build();

    int i;
    int j;

    for ( ; T--; ) {
        N = in();
        M = in();

        for (i = 0; i < MAXN; i++) {
            graph[i].clear();
            for (j = 0; j < MAXN; j++) {
                capacity[i][j] = residual[i][j] = 0;
            }
        }

        for (i = 1; i <= M; i++) {
            add_edge(0, i, 1);

            cin >> A >> B;

            add_edge(i, M + mp[A], 1);
            add_edge(i, M + mp[B], 1);
        }

        for (i = 1; i <= 6; i++) {
            add_edge(M + i, M + 7, N / 6);
        }

        int flow = max_flow(0, M + 7);

        puts(flow == M ? "YES" : "NO");
    }

    return 0;
}

