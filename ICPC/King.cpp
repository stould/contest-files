#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

int main() {
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

    int n, x, y, destX, destY, tempX, tempY;

    vector<vector<int> > maze;

    cin >> x >> y;
    cin >> destX >> destY;

    maze[x][y] = 1;
    maze[destX][destY] = 2;

    cin >> n;

    while(n > 0) {
        cin >> tempX >> tempY;
        maze[tempX][tempY] = -1;
    }



    return 0;
}
