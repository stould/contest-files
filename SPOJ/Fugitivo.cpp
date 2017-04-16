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

char c;
int i, n, m, p;

int main(void) {
    scanf("%d%d ", &n, &m);
    int x = 0, y = 0;
    bool ok = false;
    for(i = 0; i < n; i++) {
        scanf(" %c%d", &c, &p);
        if(c == 'N') y += p;
        if(c == 'S') y -= p;
        if(c == 'L') x += p;
        if(c == 'O') x -= p;

        if(hypot(x, y) > m) {
            ok = true;
        }
    }
    if(ok) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
