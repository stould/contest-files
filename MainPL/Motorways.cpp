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
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100009;
int N, M, A, B, D, n1, n2, c1, c2, p1, p2;
ll dist[MAXN];

struct MyLess {
    bool operator()(int a, int b) {
        return dist[a] > dist[b];
    }
};

struct edge {
    int next, cost, inc;

    edge() {}

    edge(int _next, int _cost, int _inc) {
        next = _next;
        cost = _cost;
        inc = _inc;
    }
};

vector<edge> graph[MAXN];

ll min_dist(int from, int to, int to_multiply) {
    REP(i, MAXN) {
        dist[i] = 1000101000100010LL;
    }
    dist[from] = 0LL;

    priority_queue<int, vector<int>, MyLess> q;

    q.push(from);

    while(!q.empty()) {
        int now = q.top(); q.pop();

        REP(i, graph[now].size()) {
            edge to_go = graph[now][i];

            ll& to_go_dist = dist[to_go.next];
            ll next_dist = dist[now] + (to_go.cost + (to_multiply * to_go.inc));

            if(to_go_dist > next_dist) {
                to_go_dist = next_dist;
                q.push(to_go.next);
            }
        }
    }
    return dist[to];
}

int main(void) {
 //   freopen("i.in", "r", stdin);
    while(5 == scanf("%d%d%d%d%d", &N, &M, &A, &B, &D)) {
        REP(i, M) {
            scanf("%d%d%d%d%d%d", &n1, &n2, &c1, &p1, &c2, &p2);
            graph[n1].push_back(edge(n2, c1, p1));
            graph[n2].push_back(edge(n1, c2, p2));
        }
        printf("%lld\n", min(min_dist(A, B, 0) + min_dist(B, A, 0), min_dist(A, B, D-1) + min_dist(B, A, D-1)));
    }
    return 0;
}
