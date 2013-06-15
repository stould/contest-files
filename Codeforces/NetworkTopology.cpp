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

const int MAXN = 100009;
int N, M, x, y, deg[MAXN];
char ans[4][20] = {"ring topology", "bus topology", "star topology", "unknown topology"};

int main(void) {
    int i, ok = 0;
    scanf("%d%d", &N, &M);

    for (i = 0; i < M; i++) {
        scanf("%d%d", &x, &y); x--; y--;
        deg[x] += 1;
        deg[y] += 1;
    }

    if (N == M) {
        bool full_cycle = true;
        for (i = 0; i < N; i++) if (deg[i] != 2) full_cycle = false;
        if (full_cycle) {
            puts(ans[0]); ok = 1;
        }
    } else if (N - 1 == M) {
        int cnt = 0;
        for (i = 0; i < N; i++) {
            if (deg[i] == 1) cnt += 1;
        }
        if (cnt == 2) {
            puts(ans[1]); ok = 1;
        } else if (cnt == N - 1) {
            puts(ans[2]); ok = 1;
        }
    }
    if (!ok) puts(ans[3]);
    return 0;
}
