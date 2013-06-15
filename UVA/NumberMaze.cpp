#include <set>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int INF = 1000001;

int dx[4] = {1, 0,-1, 0};
int dy[4] = {0,-1, 0, 1};

int maze[1000][1000];
int best[1000][1000];

set<pair<int, int> > q;
set<pair<int, int> >::iterator it;

int main() {
    freopen("i.in", "r", stdin);
    int n, R, C;

    scanf("%d", &n);

    while(n > 0) {
        q.clear();
        scanf("%d%d", &R, &C);
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                scanf("%d", &maze[i][j]);
                best[i][j] = INF;
            }
        }
        q.insert(make_pair(0, 0));

        best[0][0] = 0;

        while(!q.empty()) {
            pair<int, int> p = *q.begin();
            q.erase(q.begin());

            if(p.first == R - 1 && p.second == C - 1) {
                printf("%d\n", best[p.first][p.second]);
                break;
            }
            for(int i = 0; i < 4; i++) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];

                if(x >= 0 && y >= 0 && x < R && y < C && best[x][y] > best[p.first][p.second] + maze[x][y]) {
                    q.insert(make_pair(x, y));
                    best[x][y] = best[p.first][p.second] + maze[x][y];
                }
            }
        }
        n--;
    }
    return 0;
}
