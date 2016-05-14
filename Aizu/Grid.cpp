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

#define MAXN 260

int i, j, n, ans, grid[MAXN][MAXN], hor[MAXN][MAXN], ver[MAXN][MAXN], diagp[MAXN][MAXN], diago[MAXN][MAXN];
string str;

void reset() {
    memset(grid, 0, sizeof(grid));
    memset(hor, 0, sizeof(hor));
    memset(ver, 0, sizeof(ver));
    memset(diagp, 0, sizeof(diagp));
    memset(diago, 0, sizeof(diago));
}

int main(void) {
    while(scanf("%d", &n) == 1 && n != 0) {
        reset();
        ans = 0;
        REP(i, n) {
            cin >> str;
            REP(j, n) {
                grid[i][j] = str[j] - '0';
                if(grid[i][j] == 1) {
                    if(j - 1 >= 0) {
                        hor[i][j] = hor[i][j - 1] + 1;
                    } else {
                        hor[i][j] = grid[i][j];
                    }
                    if(i - 1 >= 0) {
                        ver[i][j] = ver[i - 1][j] + 1;
                    } else {
                        ver[i][j] = grid[i][j];
                    }
                    if(i - 1 >= 0 && j - 1 >= 0) {
                        diagp[i][j] = diagp[i - 1][j - 1] + 1;
                    } else {
                        diagp[i][j] = grid[i][j];
                    }
                    if(i - 1 >= 0 && j + 1 < n) {
                        diago[i][j] = diago[i - 1][j + 1] + 1;
                    } else {
                        diago[i][j] = grid[i][j];
                    }
                }
                ans = max(ans, hor[i][j]);
                ans = max(ans, ver[i][j]);
                ans = max(ans, diagp[i][j]);
                ans = max(ans, diago[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

