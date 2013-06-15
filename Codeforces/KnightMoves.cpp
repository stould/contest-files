#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

using namespace std;

int maze[8][8];
bool memo[8][8];
int moves[8][8];

int kdx[8] = {2,2,-2,-2,1,1,-1,-1};
int kdy[8] = {1,-1,1,-1,2,-2,2,-2};

string from, to;

int rowf, rowt, colf, colt, i, xi, xj;

queue<pair<int, int> > q;

int main(void) {
    while(cin >> from >> to) {
        memset(maze, 0, sizeof(maze));
        memset(memo, false, sizeof(memo));
        memset(moves, 0, sizeof(moves));

        rowf = 8 - (from[1] - '0');
        colf = abs('a' - from[0]);

        rowt = 8 - (to[1] - '0');
        colt = abs('a' - to[0]);

        maze[rowt][colt] = 1;
        memo[rowf][colf] = true;

        q.push(make_pair(rowf, colf));

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for(i = 0; i < 8; i++) {
                xi = p.first + kdx[i];
                xj = p.second + kdy[i];

                if(xi >= 0 && xj >= 0 && xi < 8 && xj < 8 && !memo[xi][xj]) {
                    memo[xi][xj] = true;
                    moves[xi][xj] = moves[p.first][p.second] + 1;
                    q.push(make_pair(xi, xj));
                }
            }
        }
        cout << "To get from " << from << " to " << to << " takes " << moves[rowt][colt] << " knight moves." << endl;
    }
    return 0;
}
