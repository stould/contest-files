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

const int MAXN = 110;
int T, N, F, M, Q, bi, bj, fi, fj, ts, qbi, qfi, qbj, qfj;

struct bridge {
    int now_floor, next_tower, next_floor, cost;

    bridge() {}

    bridge(int a, int b, int c, int d) {
        now_floor = a;
        next_tower = b;
        next_floor = c;
        cost = d;
    }
};

struct vertex {
    int tower, floor;

    vertex() {}

    vertex(int a, int b) {
        tower = a;
        floor = b;
    }
};

struct path {
    int from_tower, from_floor, to_tower, to_floor;

    path(){}

    path(int a, int b, int c, int d) {
        from_tower = a;
        from_floor = b;
        to_tower = c;
        to_floor = d;
    }

    bool operator<(const path& p) const {
        return from_floor < p.from_floor;
    }

    bool operator==(const path& p) const {
        return from_tower == p.from_tower && from_floor == p.from_floor && to_tower == p.to_tower && to_floor == p.to_floor;
    }
 };

map<path, int> mp;
vector<bridge> graph[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &T);
    for( ; T--; ) {
        scanf("%d%d%d", &N, &F, &M);

        FOR(i, 1, N-1) {
            graph[i].push_back(bridge(1, i+1, 1, 1));
            graph[i+1].push_back(bridge(1, i, 1, 1));
        }

        graph[1].push_back(bridge(1, N, 1, 1));
        graph[N].push_back(bridge(1, 1, 1, 1));

        REP(i, M) {
            scanf("%d%d%d%d%d", &bi, &fi, &bj, &fj, &ts);
            graph[bi].push_back(bridge(fi, bj, fj, ts));
            graph[bj].push_back(bridge(fj, bi, fi, ts));
            graph[bi].push_back(bridge(fi, bi, 1, fi-1));
            graph[bi].push_back(bridge(1, bi, fi, fi-1));
            graph[bj].push_back(bridge(fj, bj, 1, fj-1));
            graph[bj].push_back(bridge(1, bj, fj, fj-1));

            mp[path(bi, fi, bj, fj)] = ts;
            mp[path(bj, fj, bi, fi)] = ts;

            printf("%d %d - %d %d -> %d\n", bi, fi, bj, fj, mp[path(bi, fi, bj, fj)]);
        }

        for(int i = 1; i <= N; i++) {
            for(int ni = 0; ni < graph[i].size(); ni++) {
                vertex from(i, graph[i][ni].now_floor);
                vertex midd(graph[i][ni].next_tower, graph[i][ni].next_floor);

                for(int j = 0; j < graph[graph[i][ni].next_tower].size(); j++) {
                    if(graph[graph[i][ni].next_tower][j].now_floor == graph[i][ni].next_floor) {
                        vertex goal(graph[graph[i][ni].next_tower][j].next_tower, graph[graph[i][ni].next_tower][j].next_floor);

                        path a(from.tower, from.floor, midd.tower, midd.floor);
                        path b(midd.tower, midd.floor, goal.tower, goal.floor);
                        path c(from.tower, from.floor, goal.tower, goal.floor);

                        if(mp[a] == 0) mp[a] = INT_MAX;
                        if(mp[b] == 0) mp[b] = INT_MAX;
                        if(mp[c] == 0) mp[c] = INT_MAX;

                        if(a == b || a == c || b == c) continue;

                        printf("%d %d <-> %d %d <-> %d %d ->> ", from.tower, from.floor, midd.tower, midd.floor, goal.tower, goal.floor);

                        mp[c] = min(mp[c], mp[a]+mp[b]);

                        printf("%d %d %d\n", mp[a], mp[b], mp[c]);
                    }
                }
            }
        }

        scanf("%d", &Q);
        REP(i, Q) {
            scanf("%d%d%d%d", &qbi, &qfi, &qbj, &qfj);
            printf("%d\n", mp[path(qbi, qfi, qbj, qfj)]);
        }
    }
    return 0;
}
