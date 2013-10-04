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

const int MAXN = 100007;
const int INF = 101010010;

int N;
int type[MAXN];

int dist[MAXN];
int befr[MAXN];
int degr[MAXN];

vector<int> graph[MAXN];

int main(void) {
    int i, curr;

    N = in();

    for (i = 1; i <= N; i++) {
        type[i] = in();
        degr[i] = 0;
    }

    for (i = 1; i <= N; i++) {
        curr = in();

        if (curr != 0) {
            graph[i].push_back(curr);
            degr[curr] += 1;
        }
    }

    queue<int> q;

    for (i = 1; i <= N; i++) {
        befr[i] = -1;
        dist[i] = -INF;

        if (type[i] == 1) {
            q.push(i);
            dist[i] = 0;
        }
    }

    int best = -1;
    int id = -1;

    for ( ; !q.empty(); ) {
        int now = q.front(); q.pop();

        if (dist[now] > best) {
            best = dist[now];
            id = now;
        }

        for (i = 0; i < graph[now].size(); i++) {
            int u = graph[now][i];

            if (type[u] == 0 && dist[u] < dist[now] + 1 && degr[u] == 1) {
                dist[u] = dist[now] + 1;
                befr[u] = now;
                q.push(u);
            }
        }
    }

    vector<int> ans;

    while (id != -1) {
        ans.push_back(id);
        id = befr[id];
    }

    printf("%d\n", (int) ans.size());

    for (i = 0; i < (int) ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
