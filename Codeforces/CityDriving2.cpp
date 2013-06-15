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

int n, a, b, c, q;
vector<pair<int, int> > maze[100010];
bool vis[100010];
ll dist[100010];

struct cmp {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

int main(void) {
    while(cin >> n && n > 0) {
        for(int i = 0; i <= n; i++) {
            maze[i].clear();
        }
        for(int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            maze[a].push_back(make_pair(b, c));
            maze[b].push_back(make_pair(a, c));
        }
        cin >> q;
        for(int i = 0; i < q; i++) {
            cin >> a >> b;
            memset(dist, 63, sizeof(vis));
            priority_queue<int, vector<int>, cmp> p;
            p.push(a);

            dist[a] = 0;

            while(!p.empty()) {
                int tmp = p.top();
                p.pop();

                for(int j = 0; j < (int) maze[tmp].size(); j++) {
                    if(dist[tmp] + maze[tmp][j].second < dist[maze[tmp][j].first]) {
                        dist[maze[tmp][j].first] = dist[tmp] + maze[tmp][j].second;
                        p.push(maze[tmp][j].first);
                    }
                }
            }
            cout << dist[b] << endl;
        }
    }
    return 0;
}
