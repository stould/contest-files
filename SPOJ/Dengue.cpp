#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int INF = 1000000;

int n, i, j, k, auxa, auxb, t = 1, maze[110][110];

int bfs(int a) {
    int ans = 0;
    queue<int> s;
    s.push(a);
    s.push(0);

    vector<bool> vis(n + 1, false);

    while(!s.empty()) {
        int tmp = s.front();
        s.pop();
        int mx = s.front();
        s.pop();

        vis[tmp] = true;

        if(mx > ans) {
            ans = mx;
        }

        for(int i = 1; i <= n; i++) {
            if(!vis[i] && maze[tmp][i] == 1) {
                s.push(i);
                s.push(mx + 1);
            }
        }
    }
    return ans;
}

int main(void) {
    while(scanf("%d", &n) && n > 0) {
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                maze[i][j] = INF;
            }
        }
        for(i = 0; i < n - 1; i++) {
            scanf("%d%d", &auxa, &auxb);
            maze[auxa][auxb] = maze[auxb][auxa] = 1;
        }

        int m = INF, index;
        for(i = 1; i <= n; i++) {
            int hold = bfs(i);
            if(hold < m) {
                m = hold;
                index = i;
            }
        }
        cout << "Teste " << t++ << endl;
        cout << index << endl;
    }
    return 0;
}
