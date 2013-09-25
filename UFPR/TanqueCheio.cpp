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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1010;
const int INF = 1010101010;

int N, M, Q;
int c, d, u, v;

vector<pair<int, int> > graph[MAXN];

struct state {
    int w, fuel, cost;

    state(){}

    state(int _w, int _fuel, int _cost) {
        w = _w;
        fuel = _fuel;
        cost = _cost;
    }

    bool operator < (const state& s) const {
        return cost > s.cost;
    }
};

void func(void) {
    int i;

    priority_queue<state> q;

    q.push(state(u, 0, 0));

    for ( ; !q.empty(); ) {
        state now = q.top(); q.pop();

        if (now.w == v) now.cost;

        for (i = 0; i < graph[now.w].size(); i++) {
            int next_id = graph[now.w][i].first;
            int next_dist = graph[now.w][i].second;

            if (now.fuel >= next_dist) {
                int next_fuel = now.fuel - next_dist;

                if (    )
            }
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    N = in(), M = in();

    int i;

    for (i = 0; i < N; i++) fuel[i] = in();

    for (i = 0; i < M; i++) {
        u = in(), v = in(), d = in();

        graph[u].push_back(make_pair(v, d));
        graph[v].push_back(make_pair(u, d));
    }

    Q = in();

    for (i = 0; i < Q; i++) {
        c = in(), u = in(), v = in();

        int ans = func();

        if (ans == INF) {
            puts("impossible");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
