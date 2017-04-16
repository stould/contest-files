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

int i, j, n, matrix[1010][5], ans = 0;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        int know = 0;
        REP(j, 3) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 1) know += 1;
        }
        if(know >= 2) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
