#include <iostream>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

queue<int> q;
int n, a, b, graph[10010][10010];
int dist[10010];
bool used[10010];

int bfs(int x) {
    int ans = 0;
    q.push(x);

    for(int i = 1; i <= n; i++) { used[i] = false; dist[i] = 0; }

    while(!q.empty()) {
        int tmp = q.front(); q.pop();
        used[tmp] = true;
        ans = max(ans, dist[tmp]);
        for(int i = 1; i <= n; i++) {
            if(!used[i] && graph[tmp][i] == 1) {
                dist[i] = dist[tmp] + 1;
                q.push(i);
            }
        }
    }
    return ans;
}

int main(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = -1;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        cin  >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, bfs(i));
    }
    cout << ans << endl;
    return 0;
}
