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
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

string name;
char base, maze[251][251];
int i, j, k, n, m;

int dx[8] = {1, 1,  1,  0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1,  0,  1, 1};

void dfs(int i, int j, char c, char base) {
    if(maze[i][j] == base) {
        maze[i][j] = c;
    } else {
        return;
    }
    for(k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
            if(maze[ni][nj] == base) {
                dfs(ni, nj, c, base);
            }
        }
    }
}

bool al = false;

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> base) {
        if(base == 'X') break;
        if(base == 'I') {
            cin >> m >> n;
            for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++) {
                    maze[i][j] = 'O';
                }
            }
        } else if(base == 'S') {
            if(al) cout << endl;
            al = true;
            cin >> name;
            cout << name << endl;
            for(i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << maze[i][j];
                }
                if(i != n - 1) cout << endl;
            }
        } else if(base == 'C') {
            for(i = 0; i < 250; i++) {
                for(j = 0; j < 250; j++) {
                    maze[i][j] = 'O';
                }
            }
        } else if(base == 'L') {
            int x, y; char c;
            cin >> x >> y >> c; x--; y--;
            maze[y][x] = c;
        } else if(base == 'V') {
            int x, ya, yb; char c;
            cin >> x >> ya >> yb >> c; x--; ya--; yb--;
            for(int i = min(ya, yb); i <= max(ya, yb); i++) {
                maze[i][x] = c;
            }
        } else if(base == 'H') {
            int xa, xb, y; char c;
            cin >> xa >> xb >> y >> c; xa--; xb--; y--;
            for(int i = min(xa, xb); i <= max(xa, xb); i++) {
                maze[y][i] = c;
            }
        } else if(base == 'F') {
            int x, y; char c;
            cin >> x >> y >> c; x--; y--;
            dfs(x, y, c, maze[x][y]);
        } else if(base == 'K') {
            int xa, xb, ya, yb; char c;
            cin >> xa >> ya >> xb >> yb >> c; xa--; ya--; xb--; yb--;
            for(i = xa; i <= xb; i++) {
                for(j = ya; j <= yb; j++) {
                    maze[i][j] = c;
                }
            }
        }
    }
    return 0;
}


