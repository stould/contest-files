#include <iostream>
#include <vector>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <valarray>
#include <complex>
#include <utility>
#include <new>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <math.h>

using namespace std;

const int INF = 1000000;
int n, k;
string maze[2];
int vis[2][100010];
queue<pair<int, int> > q;

int main(void) {
    cin >> n >> k;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            vis[i][j] = -1;
        }
    }

    cin >> maze[0] >> maze[1];

    int dx[4] = { 0, 0,1,-1};
    int dy[4] = {-1,+1,k, k};

    vis[0][0] = 0;
    q.push(make_pair(0, 0));


    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        if(p.second < vis[p.first][p.second]) continue;
        if(p.second + k >= n) {
            printf("YES\n"); return 0;
        }
        for(int i = 0; i < 4; i++) {
            int xi = dx[i] + p.first;
            int yi = dy[i] + p.second;

            if(xi >= 0 && xi <= 1 && yi >= 0 && yi < n && maze[xi][yi] == '-' && vis[xi][yi] == -1) {
                vis[xi][yi] = vis[p.first][p.second] + 1;
                q.push(make_pair(xi, yi));
            }
        }
    }
    printf("NO\n");
    return 0;
}
