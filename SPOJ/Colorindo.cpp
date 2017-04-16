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

int n, m, k, x, y, a, b, ans, graph[2010][2010];

const int dx[] = {-1, -1, -1,  0, 0, +1, +1, +1};
const int dy[] = {-1,  0, +1, -1, 1, -1,  0, +1};

void func(int &a) {
    a = n - (a - 1);
}

void dfs(int p, int q) {
    ans++;
    graph[p][q] = 2;
    for(int i = 0; i < 8; i++) {
        int tp = p + dx[i];
        int tq = q + dy[i];

        if(tp >= 1 && tq >= 1 && tp <= n && tq <= m && graph[tp][tq] == 0) {
            dfs(tp, tq);
        }
    }
}

int main(void) {
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &k); func(x);
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < k; i++) {
        scanf("%d%d", &a, &b); func(a);
        graph[a][b] = 1;
    }
    ans = 0;
    dfs(x, y);
    printf("%d\n", ans);
    return 0;
}


