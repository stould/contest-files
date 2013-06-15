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

int in(void) { int x; scanf("%d", &x); return x; }

const int MAXN = 107;
int C, S, E, T, graph[MAXN][MAXN];
set<int> last;

struct state {
    int index, sum, elapsed;

    state() {
        index = sum = elapsed = 0;
    }
    state(int _index, int _sum) {
        index = _index;
        sum = _sum;
        elapsed = 0;
    }
};

int bfs(void) {
    queue<state> q; q.push(state(S, 0));

    int i, ans = -1;

    for ( ; !q.empty(); ) {
        state now = q.front(); q.pop();

        if (now.elapsed > T) continue;

        if (now.elapsed == T && last.count(now.index)) {
            ans = max(ans, now.sum); continue;
        }

        for (i = 0; i < C; i++) if (i != now.index) {
            state next;
            next.index = i;
            next.sum = now.sum + graph[now.index][i];
            next.elapsed = now.elapsed + 1;
            q.push(next);
        }
    }
    return ans;
}

int main(void) {
    int i, j;
    for ( ; scanf("%d%d%d%d", &C, &S, &E, &T) == 4 && (C + S + E + T != 0); ) {
        S -= 1;
        memset(graph, 0, sizeof(graph));
        for (i = 0; i < C; i++) {
            for (j = 0; j < C; j++) {
                graph[i][j] = in();
            }
        }
        last.clear();
        for (i = 0; i < E; i++) {
            last.insert(in()-1);
        }
        printf("%d\n", bfs());
    }
    return 0;
}
