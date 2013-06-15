#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int i, j, p, b, x, y, maze[3010][3010], vis[3010], test = 1, run = 0, end = 0;

void dfs(int a) {
    stack<int> s;
    s.push(a);

    while(!s.empty()) {
        int sx = s.top();
        vis[sx] = true;
        s.pop();

        run += 1;

        for(int tmp = 1; tmp <= p; tmp++) {
            if(!vis[tmp] && maze[sx][tmp]) {
                s.push(tmp);
            }
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(~scanf("%d%d", &p, &b)) {
        if(!p && !b) break;
        memset(maze, 0, sizeof(maze));
        for(i = 0; i < b; i++) {
            scanf("%d%d", &x, &y);
            maze[x][y] = 1;
        }
        bool check = true;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        for(j = 1; j <= p; j++) {
            if(!vis[j]) {
                check = false;
            }
        }
        cout << "Teste " << (test++) << endl;
        if(check) {
            cout << "S" << endl << endl;
        } else {
            cout << "N" << endl << endl;
        }
    }
    return 0;
}

