#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int i, c, r, tempo;
char buff1[50], buff2[50];
bool vis[5005];
vector<int> graph[5005];

int dfs(int n) {
    tempo += 1;
    vis[n] = true;

    for(int i = 0; i < (int) graph[n].size(); i++) {
        int next = graph[n][i];
        if(!vis[next]) {
            dfs(next);
        }
    }
}

int mount(int n) {
    for(int i = 0; i < c; i++) vis[i] = 0;
    tempo = 0;
    dfs(n);
    return tempo;
}


int main(void) {
  //  freopen("i.in", "r", stdin);
    while(1) {
        scanf(" %d %d", &c, &r);
        if(c == 0 && r == 0) break;

        map<string, int> m;

        for(int i = 0; i < c; i++) {
            scanf("%s", buff1);
            m[string(buff1)] = i;
            graph[i].clear();
        }

        for(int i = 0; i < r; i++) {
            scanf("%s %s", buff1, buff2);
            graph[m[string(buff2)]].push_back(m[string(buff1)]);
            graph[m[string(buff1)]].push_back(m[string(buff2)]);
        }

        int mx = 1;

        for(int i = 0; i < c; i++) {
            mx = max(mx, mount(i));
        }
        printf("%d\n", mx);
    }
    return 0;
}
