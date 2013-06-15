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

const int MAXN = 23;
int N, M, vi, vj, state, ans, max_pos, matrix[MAXN][MAXN];

int di[4] = {-1,-1, 1, 1};
int dj[4] = {-1, 1, 1,-1};

void update(int& vi, int& vj) {
    vj += 2;
    if (vj >= M) {
        vi -= 1;
        if ((vj - 2) % 2 == 0) {
            vj = 1;
        } else {
            vj = 0;
        }
    }
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

void rec(int x, int y, int all) {
    if (all > ans) ans = all;
    if (all == max_pos) return;

    int i;

    matrix[x][y] = 0;

    for (i = 0; i < 4; i++) {
        int opp_i = x + di[i];
        int opp_j = y + dj[i];
        int mov_i = opp_i + di[i];
        int mov_j = opp_j + dj[i];

        if (ok(mov_i, mov_j) && matrix[opp_i][opp_j] == 2 && matrix[mov_i][mov_j] == 0) {
            matrix[opp_i][opp_j] = 0; matrix[mov_i][mov_j] = 1;
            rec(mov_i, mov_j, all + 1);
            matrix[opp_i][opp_j] = 2; matrix[mov_i][mov_j] = 0;
        }

    }

    matrix[x][y] = 1;
}

int main(void) {
    int i, j;
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        memset(matrix, 0, sizeof(matrix));
        vi = N - 1, vj = 0, ans = 0, max_pos = 0;

        for (i = 0; i < (int) ceil((N * M) / 2.0); i++) {
            scanf("%d", &state);
            matrix[vi][vj] = state; update(vi, vj); if (state == 2) max_pos += 1;
        }

        ans = -1;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) if (matrix[i][j] == 1) {
                rec(i, j, 0);
            }
        }
        ans = max(ans, 0);
        printf("%d\n", ans);
    }
    return 0;
}
