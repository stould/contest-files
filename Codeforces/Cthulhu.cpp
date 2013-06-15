#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

int a, b, n, m, all = 0;
vector<int> edge[110];
bool vis[110];

void dfs(int x) {
    vis[x] = true;
    all += 1;
    for(int i = 0; i < edge[x].size(); i++) {
        if(!vis[edge[x][i]]) {
            dfs(edge[x][i]);
        }
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));

    dfs(1);

    if(all == n && n == m) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

