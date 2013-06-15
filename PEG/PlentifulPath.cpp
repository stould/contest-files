#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int a, b, i, j, m, n, grid[110][110], dp[110][110];

int main(void) {
    memset(grid, 0, sizeof(grid));
    memset(dp, 0, sizeof(dp));
    scanf("%d%d", &m, &n);
    while(scanf("%d%d", &a, &b) == 2 && !(a == 0 && b == 0)) {
        a -= 1; b -= 1;
        grid[m - a - 1][b] = 1;
    }
    for(int i = m - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(i == m - 1) {
                if(j > 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else {
                    dp[i][j] = grid[i][j];
                }
            } else {
                if(j == 0) {
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                } else {
                    dp[i][j] = grid[i][j] + max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}

