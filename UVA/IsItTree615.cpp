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

const int MAXN = 100013;

int A, B, T = 1;
int deg[MAXN], vis[MAXN];

set<int> graph[MAXN];
set<int> vertex;

void dfs(int x) {
    vis[x] = 1;

    set<int>::iterator it;

    for (it = graph[x].begin(); it != graph[x].end(); it++) {
        if (!vis[*it]) {
            dfs(*it);
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;

    for ( ; scanf("%d%d", &A, &B) == 2 && (A + B >= 0); ) {
        vertex.clear();
        for (i = 0; i < MAXN; i++) {
            graph[i].clear();
            deg[i] = vis[i] = 0;
        }

        printf("Case %d is ", T++);

        if (A == 0 && B == 0) {
            puts("a tree.");
            continue;
        }

        graph[A].insert(B); deg[B] += 1;

        vertex.insert(A);
        vertex.insert(B);

        for ( ; scanf("%d%d", &A, &B) == 2 && (A != 0 && B != 0); ) {
            graph[A].insert(B); deg[B] += 1;

            vertex.insert(A);
            vertex.insert(B);
        }


        int has_root = 0, point = 0, conn = 1;

        set<int>::iterator it;

        for (it = vertex.begin(); it != vertex.end(); it++) {
            i = *it;
            if (deg[i] == 0) {
                has_root += 1;
                dfs(i);
            }
            if (deg[i] == 1) point += 1;
        }

        if (has_root) {
            for (it = vertex.begin(); it != vertex.end(); it++) {
                if (!vis[*it]) conn = 0;
            }
        }


        if (has_root == 1 && point == vertex.size() - 1 && conn == 1) {
            puts("a tree.");
        } else {
            puts("not a tree.");
        }
    }
    return 0;
}
