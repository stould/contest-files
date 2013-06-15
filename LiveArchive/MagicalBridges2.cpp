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
int dist[105][105][2]; //[0] dist, [1] frequency

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
        }

        for(int k = 1; k <= N; k++) for(int nk = 0; nk < graph[k].size(); nk++) {
            for(int i = 1; i <= N; i++) for(int ni = 0; ni < graph[i].size(); ni++) {
                for(int j = 1; j <= N; j++) for(int nj = 0; nj < graph[j].size(); nj++) {


                }
            }
        }
    }
    return 0;
}

