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

const int MAXN = 1007;

int N, R;
int cost_factor[MAXN], child[MAXN];
vector<int> graph[MAXN];

void reset(void) {
    int i;

    for (i = 0; i < N; i++) {
        graph[i].clear();
        child[i] = cost_factor[i] = 0;
    }
}

int build_height(int x) {
    if (graph[x].empty()) return child[x] = 0;

    int i;

    int buff = 1;

    for (i = 0; i < graph[x].size(); i++) {
        buff += build_height(graph[x][i]);
    }

    return child[x] = buff;
}

int main(void) {
    freopen("i.in", "r", stdin);
    int a, b, i;

    for ( ; scanf("%d%d", &N, &R) == 2 && N + R != 0; ) {
        for (i = 0; i < N; i++) scanf("%d", &cost_factor[i]);

        reset();

        for (i = 0; i < N - 1; i++) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
        }

        build_height(R);

        for (i = 1; i <= N; i++) printf("%d\n", child[i]);
    }
    return 0;
}
