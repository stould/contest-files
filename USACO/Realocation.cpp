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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

#define INF 1061109567;

using namespace std;

typedef long long ll;
typedef long double ld;

int a, b, c, i, j, tmp, n, m, k, ind, dist[10010];
set<int> impass;
set<int>::iterator it;
vector<pair<int, int> > graph[10010];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] < dist[y];
    }
};

void bfs(int x) {
    priority_queue<int, vector<int>, MyLess> q; q.push(x);
    while(!q.empty()) {
        tmp = q.top(); q.pop();
        REP(i, graph[tmp].size()) {
            int& ac = dist[graph[tmp][i].first];
            int novo = dist[tmp] + graph[tmp][i].second;
            if(ac > novo) {
                ac = novo;
                q.push(graph[tmp][i].first);
            }
        }
    }
}

int main(void) {
    freopen("1.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    REP(i, k) {
        scanf("%d", &tmp); impass.insert(tmp);
    }
    REP(i, m) {
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    int ct = INF;
    FOR(j, 1, n + 1) if(!impass.count(j)) {
        memset(dist, 63, sizeof(dist));
        dist[j] = 0;
        bfs(j);
        tmp = 0;
        for_each(it, impass) {
            tmp += dist[*it];
        }
        printf("%d\n", tmp);
        if(tmp < ct) ct = tmp;
    }
    printf("%d\n", ct);
    return 0;
}

