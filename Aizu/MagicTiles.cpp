#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <stdio.h>

using namespace std;

vector<string> maze(101);

int H, W, ei, ej, i, j;

void dfs(int i, int j, vector<string>& maze) {
    cout << i << " " << j << endl;
    if(maze[i][j] = '.') {
        ei = i;
        ej = j;
    } else if(maze[i][j] == '.') {
        ei = -1;
        ej = -1;
    } else {
        char act = maze[i][j];
        maze[i][j] = 'X';
        if(act == 'v') dfs(i + 1, j, maze);
        if(act == '^') dfs(i - 1, j, maze);
        if(act == '<') dfs(i, j - 1, maze);
        if(act == '>') dfs(i, j + 1, maze);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(1) {
        scanf("%d %d", &H, &W);
        if(H == 0 && W == 0) break;
        maze.clear();
        for(i = 0; i < H; i++) {
            for(j = 0; j < W; j++) {
                cin >> maze[i][j];
            }
        }
        for(i = 0; i < H; i++) {
            for(j = 0; j < W; j++) {
            cout << maze[i][j];
            }
            cout << endl;
        }
        cout << endl;
        dfs(0, 0, maze);
        if(ei == -1 && ej == -1) {
            cout << "LOOP" << endl;
        } else {
            cout << ei << " " << ej << endl;
        }
    }
}
