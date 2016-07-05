#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, a, b, inst, gr[110][110], color[110];

bool dfs(int node, int c) {
    if(color[node] != 0) {
        if(color[node] == c) {
            return true;
        } else {
            return false;
        }
    }
    color[node] = c;
    for(int i = 1; i <= n; i++) if(gr[node][i] == 1) {
        if(!dfs(i, -c)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    inst = 1;
    for(; ~scanf("%d%d", &n, &m); ) {
        memset(gr, 0, sizeof(gr));
        memset(color, 0, sizeof(color));
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            gr[a][b] = gr[b][a] = 1;
        }
        printf("Instancia %d\n", inst++);
        if(dfs(1, 1)) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
        printf("\n");
    }
}
