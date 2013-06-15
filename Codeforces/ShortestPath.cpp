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

int i, u, v, n, m, k, prev[3010], dist[3010];

struct triplet {
    int a, b, c;
    triplet(){}
    triplet(int a, int b, int c): a(a), b(b), c(c){
        if(a > b) swap(a, b);
        if(a > c) swap(a, c);
        if(b < c) swap(b, c);
    }
    bool operator==(const triplet& t) const {
        return a == t.a && b == t.b && c == t.c;
    }
    bool operator<(const triplet& t) const {
        if(a != t.a) return a < t.a;
        if(b != t.b) return b < t.b;
        return c < t.c;
    }
};

set<triplet> t;
vector<int> graph[3010];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    REP(i, k) {
        triplet tmp;
        scanf("%d%d%d", &tmp.a, &tmp.b, &tmp.c);
        t.insert(tmp);
    }
    fill(dist, dist + n + 1, 10000000);
    fill(prev, prev + n + 1, -1);
    queue<int> q; q.push(1); dist[1] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now == n) break;
        REP(i, graph[now].size()) {
            int next = graph[now][i];
            printf("%d %d %d\n", prev[now], now, next);
            if(t.find(triplet(prev[now], now, next)) == t.end()) {
                q.push(next);
                prev[next] = now;
            }
        }
    }
    if(dist[n] == 10000000) {
        puts("-1");
    } else {
        vector<int> path;
        u = n;
        while(prev[u] != -1) {
            path.push_back(u);
            u = prev[u];
        }
        path.push_back(u);
        reverse(path.begin(), path.end());
        REP(i, path.size()) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    return 0;
}

