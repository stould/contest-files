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

const ll INF = 1000010100980980LL;
const int MAXN = 100009;
int N, M, a, b, c;
vector<pair<int, int> > graph[MAXN];
ll dist[MAXN];

ll func(int hashiri, int saigo) {
    for(int i = 0; i <= N; i++) dist[i] = INF;

    dist[hashiri] = 0LL;
    priority_queue<pair<int, int> > q;

    //Last bigger, index;
    q.push(make_pair(0, hashiri));

    while(!q.empty()) {
        int last = q.top().first, index = q.top().second; q.pop();

        for(int i = 0; i < graph[index].size(); i++) {
            int next = graph[index][i].first, cost = graph[index][i].second;

            if(next == saigo) cost *= 2;

            if(dist[index] + max(last, cost) < dist[next]) {
                dist[next] = dist[index] + max(last, cost);
                q.push(make_pair(cost, next));
            }
        }
    }

    return dist[saigo];
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &N, &M);

    REP(i, M) {
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    printf("%lld\n", func(1, N));

    return 0;
}
