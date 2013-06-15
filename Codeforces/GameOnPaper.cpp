#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int n, m, a, b, maze[1010][1010];

bool square(int x, int y) {
    int u = 0, m = 0, d = 0;
    for(int i = y - 1; i <= y + 1; i++) {
        if(x - 1 >= 1 && i >= 1 && i <= n && maze[x - 1][i] == 1) u++;
    }
    for(int i = y - 1; i <= y + 1; i++) {
        if(i >= 1 && i <= n && maze[x][i] == 1) m++;
    }
    for(int i = y - 1; i <= y + 1; i++) {
        if(i >= 1 && i <= n && x + 1 <= n && maze[x + 1][i] == 1) d++;
    }
    return u == 3 && m == 3 && d == 3;
}

int main(void) {
    memset(maze, 0, sizeof(maze));
    cin >> n >> m;
    int index = -1;
    for(int x = 0; x < m; x++) {
        cin >> a >> b;
        maze[a][b] = 1;
        bool ans = false;
        for(int g = a - 5; g <= a + 5; g++) {
            for(int h = b - 5; h <= b + 5; h++) {
                if(g >= 1 && h >= 1 && g <= n && h <= n) {
                    if(square(g, h)) ans = true;
                }
            }
        }
        if(ans && index == -1) {
            index = x;
        }
    }
    if(index == -1) {
        cout << -1 << endl;
    } else {
        cout << index + 1 << endl;
    }
    return 0;
}
