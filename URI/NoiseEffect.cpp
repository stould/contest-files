#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _foreach(it, b, e) for(__typeof__(b) it = (b); it != (e); ++it)
#define foreach(x...) _foreach(x)

typedef long long int Int;

const int inf = 0x3f3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;

const int MAXN = 410;

int N;
int base[MAXN][MAXN];

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

double func(int cp[MAXN][MAXN]) {
    int i, j;

    double cnt = 0.0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (abs(cp[i][j] - base[i][j]) <= 100) {
                cnt += 1.0;
            }
        }
    }

    if (cnt == 0) return 0.0;

    return (cnt * 100.0) / double(N * N);
}


int main(void) {
    int i, j;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                fastRead_int(base[i][j]);
            }
        }

        int A[MAXN][MAXN];
        int B[MAXN][MAXN];
        int C[MAXN][MAXN];
        int D[MAXN][MAXN];

        int E[MAXN][MAXN];
        int F[MAXN][MAXN];
        int G[MAXN][MAXN];
        int H[MAXN][MAXN];

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                int curr;
                fastRead_int(curr);

                int a = i, b = j, c = N - i - 1, d = N - j - 1;

                A[a][b] = curr;
                B[a][d] = curr;
                C[c][b] = curr;
                D[c][d] = curr;

                E[b][a] = curr;
                F[d][a] = curr;
                G[b][c] = curr;
                H[d][c] = curr;
            }
        }

        double ans = 0.0;

        ans = max(ans, func(A));
        ans = max(ans, func(B));
        ans = max(ans, func(C));
        ans = max(ans, func(D));
        ans = max(ans, func(E));
        ans = max(ans, func(F));
        ans = max(ans, func(G));
        ans = max(ans, func(H));

        printf("%.2lf\n", ans);

    }
    return 0;
}
