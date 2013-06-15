#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int n, vis[1010], path[1010][1010];
double x[1010], y[1010];

void dfs(int a) {
    vis[a] = true;
    for(int i = 0; i < n; i++) {
        if(path[a][i] == 1 && !vis[i]) {
            dfs(i);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n && n) {
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        double low = 0.0, high = 10000000.0, mid;
        for(int z = 0; z <= 50; z++) {
            memset(vis, 0, sizeof(vis));
            bool has = false;
            mid = low + (high - low) / 2;
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(hypot(x[i] - x[j], y[i] - y[j]) < mid) {
                        path[i][j] = path[j][i] = 1;
                    } else {
                        path[i][j] = path[j][i] = 0;
                    }
                }
            }
            dfs(0);
            for(int i = 0; i < n; i++) if(vis[i] == 0) has = true;
            if(has) {
                low = mid;
            } else {
                high = mid;
            }
        }
        printf("%.4f\n", low);
    }
    return 0;
}
