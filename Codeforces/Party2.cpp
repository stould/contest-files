#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, k, m, a, b, vis[2010];

vector<int> like[2010];
vector<int> dislike[2010];
vector<int> ac;

int is;

void dfs(int x) {
    vis[x] = 1;
    ac.push_back(x);
    for(int i = 0; i < dislike[x].size(); i++) {
        if(count(ac.begin(), ac.end(), dislike[x][i])) {
            is = 0;
            return;
        }
    }
    for(int i = 0; i < like[x].size(); i++) {
        if(!vis[like[x][i]]) {
            dfs(like[x][i]);
        }
    }
}

int main(void) {
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        like[a].push_back(b);
        like[b].push_back(a);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        dislike[a].push_back(b);
        dislike[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        is = 1;
        memset(vis, 0, sizeof(vis));
        ac.clear();
        dfs(i);
        if(is && ac.size() > ans) {
            ans = (int) ac.size();
        }
    }
    cout << ans << endl;
    return 0;
}
