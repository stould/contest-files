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

const int MAXN = 110;
const int INF = 100010010;
int mat[MAXN][MAXN], has[MAXN];
int a, b, N, test = 1;

int main(void) {
    for( ; 2 == scanf("%d%d", &a, &b) && (a + b) != 0; ) {
        for(int i = 1; i <= 100; i++) {
            has[i] = 0;
            for(int j = 1; j <= 100; j++) {
                mat[i][j] = INF;
            }
        }

        mat[a][b] = has[a] = has[b] = 1;

        for( ; 2 == scanf("%d%d", &a, &b) && (a + b) != 0; ) {
            mat[a][b] = 1;
            has[a] = has[b] = 1;
        }

        N = 0;
        for(int i = 1; i <= 100; i++) if(has[i] == 1) N += 1;

        for(int k = 1; k <= 100; k++) {
            for(int i = 1; i <= 100; i++) {
                for(int j = 1; j <= 100; j++) {
                    if(mat[i][j] > mat[i][k] + mat[k][j]) {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }

        double sum = 0.0;

        for(int i = 1; i <= 100; i++) {
            for(int j = 1; j <= 100; j++) if(i != j && mat[i][j] != INF && mat[i][j] != 0) {
                sum += mat[i][j];
            }
        }
        if(N == 0) N = 1;
        printf("Case %d: average length between pages = %.3lf clicks\n", test++, sum / (N * (N - 1)));
    }
    return 0;
}
