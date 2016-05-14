#include <iostream>
#include <vector>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <valarray>
#include <complex>
#include <utility>
#include <new>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <math.h>

using namespace std;

int i, n, x, y, g[510][510];

int main(void) {
    memset(g, 0, sizeof(g));
    scanf("%d", &n);

    bool ok = false;
    for(i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        if(g[x][y] > 0) {
            ok = true;
        }
        g[x][y] += 1;
    }
    printf("%d\n", ok);
    return 0;
}

