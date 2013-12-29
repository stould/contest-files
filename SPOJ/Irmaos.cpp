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

using namespace std;

typedef long long ll;
typedef unsigned uint;

const int MAXN = 107;
int N, R, C, K;
int field[MAXN][MAXN], next[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void func (void) {
    int i, j, k;

    memset(next, -1, sizeof(next));

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            for (k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                int enemy = (field[i][j] + 1) % N;

                if (ni >= 0 && nj >= 0 && ni < R && nj < C) {
                    if (field[ni][nj] == enemy) {
                        next[ni][nj] = field[i][j];
                    }
                }
            }
        }
    }

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (next[i][j] != -1) field[i][j] = next[i][j];
        }
    }
}

int main(void) {
    int i, j;

    for ( ; scanf("%d%d%d%d", &N, &R, &C, &K) == 4 && (N + R + C + K != 0); ) {
        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                scanf("%d", &field[i][j]);
            }
        }
        for ( ; K--; ) {
            func ();
        }

        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                printf("%d", field[i][j]);
                if (j != C - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
