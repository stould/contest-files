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

const int MAXN = 10000;
int a, b, N, M, K, m[MAXN][MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    memset(m, -63, sizeof(m));

    scanf("%d%d%d", &N, &M, &K);

    REP(i, M) {
        scanf("%d%d", &a, &b);
        m[a][b] = m[b][a] = 1;
    }

    FOR(i, 1, N+1) FOR(j, 1, N+1) FOR(k, 1, N+1) {
        m[i][j] = max(m[i][j], m[i][k] + m[k][j]);
    }
    FOR(i, 1, N+1) {
        printf("%d\n", m[i][i]);
        if(m[i][i] + 1 >= K + 1) {
        //    printf("%d\n", i);
        }
    }
    return 0;
}

