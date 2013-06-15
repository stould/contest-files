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

const int MAXN = 210;
const int INF = 1010001010;
int A, B, C, N, M, K, dist[MAXN];
vector<pair<int, int> > graph[MAXN];

struct MyCmp {
    bool operator()(int a, int b) {
        return dist[a] > dist[b];
    }
};

struct city {
    int index, distance;

    city(){}
    city(int index, int distance): index(index), distance(distance) {}

    bool operator<(const city& c) const {
        if(distance != c.distance) return distance < c.distance;
        return index < c.index;
    }
};

int main(void) {
    while(scanf("%d%d", &N, &M) == 2) {
        REP(i, N+1) { graph[i].clear(); dist[i] = INF; }


        REP(i, M) {
            scanf("%d%d%d", &A, &B, &C);
            graph[A].push_back(make_pair(B, C));
            graph[B].push_back(make_pair(A, C));
        }

        scanf("%d", &K);

        priority_queue<int, vector<int>, MyCmp> q;
        q.push(0); dist[0] = 0;

        while(!q.empty()) {
            int now = q.top(); q.pop();

            REP(i, graph[now].size()) {
                int next = graph[now][i].first, cost = graph[now][i].second;

                if(dist[now] + cost < dist[next]) {
                    dist[next] = dist[now] + cost;
                    q.push(next);
                }
            }
        }
        vector<city> vc;
        FOR(i, 1, N+1) vc.push_back(city(i, dist[i]));
        sort(vc.begin(), vc.end());

        printf("%d\n", vc[K-1].index);
    }
    return 0;
}
