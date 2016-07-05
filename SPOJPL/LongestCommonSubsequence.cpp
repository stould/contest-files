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

#define MAXN 11000

char S[MAXN], T[MAXN];
int i, j, N, M, dp[MAXN][MAXN];

string lcs(int dp[MAXN][MAXN], char S[MAXN], char T[MAXN], int i, int j) {
    if(i == 0 || j == 0) {
        return "";
    } else if(S[i] == T[j]) {
        return lcs(dp, S, T, i-1, j-1) + S[i];
    } else {
        if(dp[i][j-1] > dp[i-1][j]) {
            return lcs(dp, S, T, i, j-1);
        } else {
            return lcs(dp, S, T, i-1, j);
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%s %s", S, T);
    N = strlen(S);
    M = strlen(T);
  /*  REP(i, N) {
        REP(j, M) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(i > 0 && j > 0) {
                if(S[i] == T[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
*/
    cout << lcs(dp, S, T, N, M) << "\n";
    printf("%d\n", dp[N-1][M-1]);
    return 0;
}

