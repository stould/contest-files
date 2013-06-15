#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, i, n, m, ans, id[1005], sz[1005];

int root(int i) {
    while(i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}
int find(int p, int q) {
    return root(p) == root(q);
}
void unite(int p, int q) {
    int i = root(p);
    int j = root(q);
    if(i == j) return;
    if(sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
}
int main(void) {
    while(scanf("%d%d", &n, &m) == 2) {
        for(i = 1; i <= n; i++) { id[i] = i; sz[i] = 1; }
        ans = n;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            if(!find(a, b)) {
                unite(a, b); ans--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
