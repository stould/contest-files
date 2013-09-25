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

const int MAXN = 109;

int T, N, M;

int m[MAXN][MAXN];

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(void) {
    T = in();

    int i, j, k;

    for ( ; T--; ) {
        N = in(), M = in();

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                m[i][j] = in();
            }
        }

        set<int> ans;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) if (m[i][j] != -1) {
                bool ok = 0;
                for (k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < N && nj >= 0 && nj < M && m[i][j] == m[ni][nj]) {
                        ok = 1;
                    }
                }
                if (ok) ans.insert(m[i][j]);
            }
        }

        printf("%d\n", (int) ans.size());
    }
    return 0;
}
