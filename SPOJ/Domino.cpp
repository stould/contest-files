#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int a, b, n, ok, teste = 1, mem[7][7], vis[7], ct[7];

void dfs(int x) {
    vis[x] = 1;
    for(int j = 0; j <= 6; j++) {
        if(vis[j] == 0 && mem[x][j] == 1) dfs(j);
    }
}

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        memset(mem, 0, sizeof(mem)); memset(vis, 0, sizeof(vis)); memset(ct, 0, sizeof(ct));
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            ct[a] += 1;
            ct[b] += 1;
            mem[a][b] = 1;
            mem[b][a] = 1;
        }
        for(int i = 0; i <= 6; i++) {
            if(ct[i] > 0) {
                dfs(i); break;
            }
        }
        ok = 1;
        for(int i = 0; i <= 6; i++) {
            if(ct[i] > 0 && !vis[i]) {
                ok = 0;
            }
        }
        int o = 0;
        for(int i = 0; i <= 6; i++) {
            if(ct[i] % 2 == 1) o++;
        }
        printf("Teste %d\n%s\n\n", teste++, ok == 1 && (o == 0 || o == 2) ? "sim" : "nao");
    }
    return 0;
}

