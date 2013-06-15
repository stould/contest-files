#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int i, e, l, a, b, maze[110][110], vis[110], t = 1;

bool dfs(int a) {
   stack<int> s;
   s.push(a);

    while(!s.empty()) {
        int tmp = s.top();
        s.pop();
        vis[tmp] = true;

        for(int i = 1; i <= e; i++) {
            if(!vis[i] && maze[tmp][i]) {
                s.push(i);
            }
        }
    }
    bool ans = true;
    for(int i = 1; i <= e; i++) {
        if(!vis[i]) ans = false;
    }
    return ans;
}

int main(void) {
  //  freopen("i.in", "r", stdin);
    while(scanf("%d%d", &e, &l) == 2 && e && l) {
        memset(maze, 0, sizeof(maze));
        memset(vis, 0, sizeof(vis));

        for(i = 1; i <= l; i++) {
            scanf("%d%d", &a, &b);
            maze[a][b] = maze[b][a] = 1;
        }

        printf("Teste %d\n", t++);

        if(dfs(1)) {
            printf("normal\n\n");
        } else {
            printf("falha\n\n");
        }
    }
}
