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

const int MAXN = 205;
vector<int> graph[MAXN];
int capacity[MAXN][MAXN], N, M, K, a, b, now, test = 1;

int max_flow(int source, int sink) {
    int residual[MAXN][MAXN], prev[MAXN], actual[MAXN];
    memset(residual, 0, sizeof(residual));
    while(1) {
        memset(prev, -1, sizeof(prev));
        memset(actual, 0, sizeof(actual));

        prev[source] = source;
        actual[source] = INT_MAX;

        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
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

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d%d", &N, &M, &K) == 3) {
        REP(i, MAXN) {
            graph[i].clear();
            REP(j, MAXN) {
                capacity[i][j] = 0;
            }
        }
        REP(i, N) {
            scanf("%d", &now);
            capacity[0][i+1] = now;
        }
        REP(i, M) {
            capacity[N+i+1][N+M+1] = 1;
        }
        REP(i, K) {
            scanf("%d%d", &a, &b);
            capacity[a][N+b] = 1;
        }
        REP(i, N+M+2) REP(j, N+M+2) if(capacity[i][j] || capacity[j][i]) {
            graph[i].push_back(j);
        }
        printf("Instancia %d\n%d\n", test++, max_flow(0, N+M+1));
    }
    return 0;
}
