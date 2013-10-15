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

int N;
int H[1 << 4];

struct data {
    int p, c;

    data(){
        p = 0;
        c = 1;
    }

    data(int p, int c): p(p), c(c) {}
};

data dp[1 << 4][1 << 15];
int mark[1 << 4][1 << 15];

data func(int index, int mask) {
    if (mark[index][mask] != -1) {
        return dp[index][mask];
    }

    if (mask == (1 << N) - 1) {
        return data(H[index] + N, 1);
    }

    int i;

    mark[index][mask] = 1;
    data& ans = dp[index][mask] = data(0, 0);

    for (i = 1; i <= N; i++) {
        int pos = (1 << (i - 1));
        if (!(mask & pos)) {
            data aux = func(i, mask | pos);

            aux.p += abs(H[index] - H[i]) + 1;

            if (aux.p > ans.p) {
                ans.p = aux.p;
                ans.c = aux.c;
            } else if (aux.p == ans.p) {
                ans.c += aux.c;
            }
        }
    }

    return ans;
}

int main(void) {
    int i, j;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        H[0] = 0;
        for (i = 1; i <= N; i++) H[i] = in();

        for (i = 0; i <= N; i++) {
            for (j = 0; j < (1 << N); j++) {
                mark[i][j] = -1;
            }
        }

        data ans = func(0, 0);

        printf("%d %d\n", ans.p, ans.c);
    }
    return 0;
}
