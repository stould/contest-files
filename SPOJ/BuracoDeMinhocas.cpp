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

int i, j, p, b, x, y, ans, test = 1, vis[3030];
vector<int> ga[3030], gb[3030];

void dfs1(int x) {
    vis[x] = true;
    ans++;
    for(int i = 0; i < ga[x].size(); i++) {
        if(vis[ga[x][i]] == 0) {
            dfs1(ga[x][i]);
        }
    }
}

void dfs2(int x) {
    vis[x] = true;
    ans++;
    for(int i = 0; i < gb[x].size(); i++) {
        if(vis[gb[x][i]] == 0) {
            dfs2(gb[x][i]);
        }
    }
}

int main(void) {
    while(~scanf("%d%d", &p, &b)) {
        if(!p && !b) break;
        for(i = 1; i <= p; i++) {
            ga[i].clear();
            gb[i].clear();
        }
        for(i = 0; i < b; i++) {
            scanf("%d%d", &x, &y);
            ga[x].push_back(y);
            gb[y].push_back(x);
        }
        cout << "Teste " << (test++) << endl;
        memset(vis, 0, sizeof(vis));
        ans = 0;
        dfs1(1);
        if(ans != p) {
            cout << "N" << endl << endl;
        } else {
            memset(vis, 0, sizeof(vis));
            ans = 0; dfs2(1);
            if(ans != p) {
                cout << "N" << endl << endl;
            } else {
                cout << "S" << endl << endl;
            }
        }
    }
    return 0;
}
