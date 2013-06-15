#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char base[310];
int i, j, k, n, total, tmp, mt[310], used[310];
vector<int> graph[310];

 bool match(char &a, char &b) {
    if(a == 'B' && b == 'S') return true;
    if(b == 'B' && a == 'S') return true;
    if(a == 'C' && b == 'F') return true;
    if(b == 'C' && a == 'F') return true;
    return false;
}

bool dfs(int x) {
    if(used[x]) return false;
    used[x] = true;
    for(int i = 0; i < graph[x].size(); i++) {
        if(mt[graph[x][i]] == -1 || dfs(mt[graph[x][i]])) {
            mt[graph[x][i]] = x;
            return true;
        }
    }
    return false;
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%s", base) == 1) {
        n = strlen(base);
        total = 0;
        for(i = 0; i < n; i++) {
            tmp = 0;
            for(j = i, k = i + 1; j >= 0 && k < n; j--, k++) {
                if(match(base[j], base[k])) {
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }
        memset(mt, -1, sizeof(mt));
        for(int i = 0; i < n; i++) {
            memset(used, 0, sizeof(used));
            dfs(i);
        }
        for(int i = 0; i < n; i++) {
            if(mt[i] != -1) {
                total += 1;
    //            printf("%d %d\n", mt[i], i);
            }
        }
        printf("%d\n", total/2);
    }
    return 0;
}
