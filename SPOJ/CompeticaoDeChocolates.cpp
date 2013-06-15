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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int N, base = 1, vis[1010], dist[1010];
string P, F;
vector<int> order, graph[1010];
map<string, int> msi;
map<int, string> mis;
map<int, int> parent;

pair<int, int> bfs(int x) {
    queue<int> q; q.push(x); vis[x] = 1;
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    int m = 0, index = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();

        REP(i, graph[u].size()) {
            int v = graph[u][i];
            if(!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = vis[u] = 1;
                q.push(v);
                if(dist[v] > m) {
                    m = dist[v];
                    index = v;
                }
            }
        }
    }
    return make_pair(m, index);
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        cin >> P >> F;
        if(msi[P] == 0) {
            msi[P] = base;
            mis[base] = P;
            base += 1;
        }
        if(msi[F] == 0) {
            msi[F] = base;
            mis[base] = F;
            base += 1;
        }
        graph[msi[P]].push_back(msi[F]);
        graph[msi[F]].push_back(msi[P]);
    }
    int ansA = bfs(1).second;
    pair<int, int> chk = bfs(ansA);
    int ansB = chk.second;
    P = mis[ansA];
    F = mis[ansB];
    if(P > F) swap(P, F);
    cout << P << " " << F << " " << chk.first << "\n";
    return 0;
}

