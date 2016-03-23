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

int i, n, m, v[10010];

int main(void) {
    scanf("%d%d", &n, &m);
    bool ok = false;
    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    } v[n] = 42195 ;
    for(i = 1; i <= n; i++) {
        if(v[i] - v[i - 1] > m) ok = true;
    }
    if(ok) {
        printf("N\n");
    } else {
        printf("S\n");
    }
    return 0;
}
