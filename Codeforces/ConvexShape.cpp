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

#define rep(i, n) for(int (i) = 0; i < n; i++)
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

const int MAXN = 59;
int N, M;
char mat[MAXN][MAXN];
bool ok;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &N, &M);

    rep(i, N) scanf("%s", mat[i]);

    ok = true;

    rep(i, N) rep(j, M) if(mat[i][j] == 'B') {
        rep(k, N) rep(l, M) if(mat[k][l] == 'B') {
            if(i == k) {
                for(int a = min(j, l) + 1; a <= max(j, l) - 1; a++) if(a >= 0 && a < M) {
                    if(mat[i][a] == 'W') {
                        ok = false;
                        goto end;
                    }
                }
            } else if(j == l) {
                for(int a = min(i, k) + 1; a <= max(i, k) - 1; a++) if(a >= 0 && a < N) {
                    if(mat[a][j] == 'W') {
                        ok = false;
                        goto end;
                    }
                }
            } else {
                int ax = i, ay = l, bx = k, by = j;

                if(mat[ax][ay] != 'B' && mat[bx][by] != 'B') {
                    ok = false;
                    goto end;
                }
            }
        }
    }

    end:;

    if(ok) puts("YES");
    else puts("NO");

    return 0;
}
