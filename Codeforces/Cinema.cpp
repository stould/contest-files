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
#include <time.h>
#include <math.h>

using namespace std;

int dx[] = {-1, -1, -1,  0, 0, +1, +1, +1};
int dy[] = {-1,  0, +1, -1, 1, -1,  0, +1};

int a, b, i, j, l, x, z, n, m, k, g[2010][2010];

vector<pair<int, int> > helper;

bool cmp(pair<int, int> aa, pair<int, int> bb) {
    int da = abs(aa.first - a) + abs(aa.second - b);
    int db = abs(bb.first - a) + abs(bb.second - b);

    if(da != db) {
        return da < db;
    } else {
        if(aa.first != bb.first) {
            return aa.first < bb.first;
        } else {
            return aa.second <= bb.second;
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();

        if(g[p.first][p.second] == 0) {
            helper.push_back(p);
            if(helper.size() == 5) {
                sort(helper.begin(), helper.end(), cmp);
                g[helper[0].first][helper[0].second] = 1;
                printf("%d %d\n", helper[0].first, helper[0].second);
                break;
            }
        }
        for(int t = 0; t < 8; t++) {
            int ax = p.first + dx[t];
            int ay = p.second + dy[t];

            if(ax >= 1 && ay >= 1 && ax <= n && ay <= m) {
                q.push(make_pair(ax, ay));
            }
        }
    }
}

int main(void) {
    scanf("%d%d%d", &n, &m, &x);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            g[i][j] = 0;
        }
    }
    for(z = 0; z < x; z++) {
        scanf("%d%d", &a, &b);
        helper.clear();
        bfs(a, b);
        if(helper.size() < 5) {
            printf("%d %d\n", helper[0].first, helper[0].second);
        }
    }
    return 0;
}
