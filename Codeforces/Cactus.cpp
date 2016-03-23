#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

const int MOD = 1000000007;
int a, b, i, j, k, n, m, matrix[1001][1001];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(matrix, 0, sizeof(matrix));
    REP(i, m) {
        scanf("%d%d", &a, &b);
        matrix[a][b] = 1;
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            for(k = 1; k <= n; k++) {
                matrix[i][j] += (matrix[i][k] * matrix[k][j]) % MOD;
            }
        }
    }
    scanf("%d", &k);
    REP(i, k) {
        printf("%d\n", matrix[a][b] % MOD);
    }
    return 0;
}


