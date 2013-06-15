#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int INF = 1 << 23;

int b, n, m, s, t, dist[1010], inQ[1010];
vector<pair<int, int> > maze[1010];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

int main(void) {
#ifdef LOCAL
    freopen("i.in","r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> t >> b;
        maze[s].push_back(make_pair(b, t));
        maze[t].push_back(make_pair(b, s));
    }
    for(int i = 0; i <= 1010; i++) dist[i] = INF, inQ[i] = 0;
    dist[0] = 0; inQ[0] = 1;
    priority_queue<int, vector<int>, MyLess> q;
    q.push(0);
    while(!q.empty()) {
        int tmp = q.top();
        q.pop();
        inQ[tmp] = 0;
        for(int i = 0; i < maze[tmp].size(); i++) {
            int aux_dist = dist[tmp] + maze[tmp][i].first;
            int actual_dist = dist[maze[tmp][i].second];
            if(aux_dist < actual_dist) {
                dist[maze[tmp][i].second] = aux_dist;
                if(!inQ[maze[tmp][i].second]) {
                    inQ[maze[tmp][i].second] = 1;
                    q.push(maze[tmp][i].second);
                }
            }
        }
    }
    cout << dist[n + 1] << endl;
    return 0;
}
