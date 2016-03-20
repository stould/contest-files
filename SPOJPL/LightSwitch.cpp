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

#define MAXN 100010

int n, t [4 * MAXN] ;

void build (int a[], int v, int tl, int tr ) {
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2 ;
        build(a, v * 2 , tl, tm);
        build(a, v * 2 + 1 , tm + 1 , tr);
        t[v] = t[v * 2] + t [v * 2 + 1] ;
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if(l > r) {
        return 0;
    }
    if(l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2 , tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}



void update(int v, int tl, int tr, int l, int r, int new_val) {
    if(l == r) {
        t[v] = new_val;
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2 , tl, tm, l, min(r, tm), new_val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
    t[v] = (t[v * 2] + t[v * 2 + 1]);
}

int i, j, v, q, op, si, ei;

int main(void) {
    scanf("%d%d", &v, &q);
    build(t, 1, 1, v);
    REP(i, q) {
        scanf("%d%d%d", &op, &si, &ei);
        if(op == 0) {
            update(1, 1, v, si, ei, 1);
            for(j = 1; j <= v; j++) {
                printf("%d ", sum(1, 1, v, j, j));
            } printf("\n");
        } else {
            printf("%d\n", sum(1, 1, v, si, ei));
        }
    }
    return 0;
}

