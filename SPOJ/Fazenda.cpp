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

const int MAXN = 1707;

int X[60], Y[60], L[60], C[60];

int N, matrix[MAXN][MAXN], vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    freopen("i.in", "r", stdin);
    int i, j, k, x;

    for( ; scanf("%d", &N) && N != 0; ) {
        int area = 0;

        for (i = 0; i < MAXN; i++) {
            for (j = 0; j < MAXN; j++) {
                matrix[i][j] = vis[i][j] = 0;
            }
        }

        set<pair<int, int> > per;

        for (x = 0; x < N; x++) {
            scanf("%d%d%d%d", &X[x], &Y[x], &L[x], &C[x]);
            X[x] += 1; Y[x] += 1;
            for (i = MAXN - X[x] - 1; i > MAXN - X[x] - L[x] - 1; i--) {
                for (j = MAXN - Y[x] - 1; j > MAXN - Y[x] - C[x] - 1; j--) {
                    if (!matrix[i][j]) {
                        matrix[i][j] += 1;
                        area += 1;
                    }



                    if (per.count(make_pair(i, j))) {
                        per.erase(make_pair(i, j));
                    }

                    for (x = 0; x < 4; x++) {
                        int ni = i + dx[x];
                        int nj = j + dy[x];

                        if (matrix[ni][nj] == 0) {
                            per.insert(make_pair(ni, nj));
                        }
                    }
                }
            }
        }

        printf("%d %d\n", area, (int) per.size());

    }
    return 0;
}
