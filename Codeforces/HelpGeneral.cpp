#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M, xa, ya, ans = 0;

int dx[4] = {-1, 1,  2, 2};
int dy[4] = { 2, 2, -1, 1};

bool isValid(int i, int j) {
    if(i >= 0 && j >= 0 && i < N && j < M) return true;
    return false;
}

int main() {
    cin >> N >> M;

    int maze[N][M];

    memset(maze, 0, sizeof(maze));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(maze[i][j] == 0) {
                ans++;
                cout << i << " " << j << endl;
                for(int k = 0; k < 4; k++) {
                    xa = i + dx[k];
                    ya = j + dy[k];
                    if(isValid(xa, ya) && maze[xa][ya] == 0) {
                        maze[xa][ya] = 1;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
