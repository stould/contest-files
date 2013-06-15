#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, -1,  0, 1};

int main() {
    int i, j, k, n, m, wx, wy;
    int poss = 0;

    cin >> m >> n;

    vector<string> maze(m + 1);

    bool vis[1001][1001];

    for(i = 0; i < m; i++) {
       cin >> maze[i];
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(maze[i][j] == 'W') {
                for(k = 0; k < 4; k++) {
                    int xa = i + dx[k];
                    int ya = j + dy[k];

                    if(xa >= 0 && ya >= 0 && xa < maze.size() && ya < maze[0].size() && maze[xa][ya] == 'P' && !vis[xa][ya]) {
                        vis[i][j] = true;
                        vis[xa][ya] = true;
                        poss += 1;
                        break;
                    }
                }
            }
        }
    }
    cout << poss << endl;
    return 0;
}
