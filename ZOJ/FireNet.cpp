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

int a, b, i, j, k, n, ans;
char maze[10][10];

int rec(int i, int j, int now) {
    maze[i][j] = 'U';
    for(k = i + 1; k < n && maze[k][j] != 'X'; k++) maze[k][j] = 'P';
    for(k = i - 1; k >= 0 && maze[k][j] != 'X'; k--) maze[k][j] = 'P';
    for(k = j + 1; k < n && maze[i][k] != 'X'; k++) maze[i][k] = 'P';
    for(k = j - 1; k >= 0 && maze[i][k] != 'X'; k--) maze[i][k] = 'P';

    if(now > ans) {
        ans = now;
    }

    for(a = 0; a < n; a++) for(b = 0; b < n; b++) {
        if(maze[a][b] == '.') rec(a, b, now + 1);
    }

}

int main(void) {
    //freopen("i.in", "r", stdin);
    while(scanf("%d", &n) == 1 && n != 0) {
        REP(i, n) {
            scanf("%s", maze[i]);
        }
        ans = 0;
        REP(i, n) REP(j, n) {
            if(maze[i][j] == '.') {
                rec(i, j, 1);
            }
            REP(a, n) REP(b, n) if(maze[a][b] != 'X') maze[a][b] = '.';
        }
        printf("%d\n", ans);
    }
    return 0;
}

