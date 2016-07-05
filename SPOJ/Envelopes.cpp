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

int a, i, n, k, v[1010];

int main(void) {
    scanf("%d%d", &n, &k); memset(v, 0, sizeof(v));
    for(i = 0; i < n; i++) {
        scanf("%d", &a);
        v[a] += 1;
    }
    int ans = v[1];
    for(int i = 2; i <= k; i++) {
        ans = min(ans, v[i]);
    }
    printf("%d\n", ans);
    return 0;
}
