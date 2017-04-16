#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

const int INF = 100000000;
int a, b, c, i, j, k, n, m, gr[200][200], dist[200];

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n >> m && !(n == 0 && m == 0)) {
        for(i = 1; i <= n; i++) {
            dist[i] = INF;
            for(j = 1; j <= n; j++) {
                gr[i][j] = INF;
            }
        }
        for(i = 0; i < m; i++) {
            cin >> a >> b >> c;
            gr[a][b] = c;
        }
        cin >> a >> b;
        queue<int> q; q.push(a); dist[a] = 0;
        while(!q.empty()) {
            int tmp = q.front(); q.pop();

            for(i = 1; i <= n; i++) {
                if(gr[tmp][i] != INF && dist[tmp] + gr[tmp][i] < dist[i]) {
                    dist[i] = dist[tmp] + gr[tmp][i];
                    q.push(i);
                }
            }
        }
        if(dist[b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[b] << endl;
        }
    }
    return 0;
}
