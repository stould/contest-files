#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <math.h>

#define REP(i, n) for(i = 0; i < (n); i++)

using namespace std;

int a, b, i, n, m, times, teste, vis[410];
vector<int> graph[410];
set<int> ans;
set<int>::iterator it;

int dfs(int u){
    int less = vis[u] = times++;
    int filhos = 0;
    for(int i = 0; i< graph[u].size(); i++){
       if(vis[graph[u][i]]==0){
          filhos++;
          int m = dfs(graph[u][i]);
          less = min(less,m);
          if(vis[u] <= m && (u != 0 || filhos >= 2)){
              ans.insert(u);
          }
       }else{
          less = min(less, vis[graph[u][i]]);
       }
    }
    return less;
}
int main(void) {
    teste = 1;
    for( ; scanf("%d%d", &n, &m) == 2 && !(n + m) == 0; ) {
        REP(i, n+1) { graph[i].clear(); vis[i] = 0; }
        REP(i, m) {
            scanf("%d%d", &a, &b); a -= 1; b -= 1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        times = 1;
        ans.clear();
        dfs(0);
        printf("Teste %d\n", teste++);
        if(ans.size() == 0) {
            printf("nenhum\n");
        } else {
            for(it = ans.begin(); it != ans.end(); it++) {
                printf("%d ", (*it) + 1);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
