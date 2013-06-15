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

#define MAXN 550
#define INF 10000000

int i, n, e, x, y, h, k, dist[MAXN], mem_matrix[MAXN][MAXN];
vector<pair<int, int> > graph[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

int dijsktra(int source, int destiny) {
    for(int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }
    priority_queue<int, vector<int>, MyLess> q;
    dist[source] = 0;
    q.push(source);
    while(!q.empty()) {
        int tmp = q.top();
        q.pop();
        for(int i = 0; i < graph[tmp].size(); i++) {
            int invariantA = mem_matrix[tmp][graph[tmp][i].first];
            int invariantB = mem_matrix[graph[tmp][i].first][tmp];
            int aux_dist = dist[tmp];
            int actual_dist = dist[graph[tmp][i].first];
            if(!(invariantA == 1 && invariantB == 1)) {
                aux_dist += graph[tmp][i].second;
            }
            if(aux_dist < actual_dist) {
                dist[graph[tmp][i].first] = aux_dist;
                q.push(graph[tmp][i].first);
            }
        }
    }
    return dist[destiny];
}

int main(void) {
    for( ; scanf("%d%d", &n, &e) == 2 && !(n == 0 && e == 0); ) {
        REP(i, MAXN) graph[i].clear();
        memset(mem_matrix, 0, sizeof(mem_matrix));
        REP(i, e) {
            scanf("%d%d%d", &x, &y, &h);
            graph[x].push_back(make_pair(y, h));
            mem_matrix[x][y] = 1;
        }
        scanf("%d", &k);
        REP(i, k) {
            scanf("%d%d", &x, &y);
            int ac = dijsktra(x, y);
            if(ac == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", ac);
            }
        }
        printf("\n");
    }
    return 0;
}
