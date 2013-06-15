#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int a, b, i, n, ind, vis[1000010];
vector<int> mp[1<<20];

int bfs1(pair<int, int > s) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > q; q.push(s);
    int ans = 0;

    while(!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        vis[tmp.first] = true;
        if(tmp.second > ans) {
            ans = tmp.second;
            ind = tmp.first;
        }
        for(int u = 0; u < mp[tmp.first].size(); u++) {
            if(!vis[mp[tmp.first][u]]) {
                q.push(make_pair(mp[tmp.first][u], tmp.second + 1));
            }
        }
    }
    return ans;
}

int bfs2(pair<int, int > s) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > q; q.push(s);
    int ans = 0;

    while(!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        vis[tmp.first] = true;
        if(tmp.second > ans) {
            ans = tmp.second;
            ind = tmp.first;
        }
        for(int u = 0; u < mp[tmp.first].size(); u++) {
            if(!vis[mp[tmp.first][u]]) {
                q.push(make_pair(mp[tmp.first][u], tmp.second + 1));
            }
        }
    }
    return ans;
}


int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        mp[a].push_back(b); mp[b].push_back(a);
    }
    printf("%d\n", abs(bfs2(make_pair(ind, 0)) - bfs1(make_pair(1, 0))));
    return 0;
}
