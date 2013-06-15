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
int N, R, T, u, v, s, d, mat[MAXN][MAXN];

int main(void) {
    scanf("%d", &T);
    REP(x, T) {
        scanf("%d%d", &N, &R);
        REP(i, N) REP(j, N) {
            if(i == j) mat[i][j] = 0;
            else mat[i][j] = 1010100000;
        }
        REP(i, R) {
            scanf("%d%d", &u, &v);
            mat[u][v] = mat[v][u] = 1;
        }
        scanf("%d%d", &s, &d);
        REP(k, N) REP(i, N) REP(j, N) mat[i][j]= min(mat[i][j], mat[i][k] + mat[k][j]);
        int ans = 0;
        REP(i, N) ans = max(ans, mat[s][i] + mat[i][d]);
        printf("Case %d: %d\n", x + 1, ans);
    }
    return 0;
}

