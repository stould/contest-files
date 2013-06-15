#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int sx[5] = {0, 1,  0, -1, 0};
int sy[5] = {0, 0, -1,  0, 1};

int mx[9] = {0, 1,  1,  0, -1, -1, -1, 0, 1};
int my[9] = {0, 0, -1, -1, -1,  0,  1, 1, 1};

int lx[13] = {0, 1,  1,  0, -1, -1, -1, 0, 1, 2,  0, -2, 0};
int ly[13] = {0, 0, -1, -1, -1,  0,  1, 1, 1, 0, -2,  0, 2};

int maze[10][10];

int i, j, xi, xj;

bool isValid(int a, int b) {
    return a >= 0 && b >= 0 && a < 10 && b < 10;
}

vector<string> split(string source, string pattern) {
    unsigned i, base = 0;
    vector<string> ret;
    string buff;

    for(i = 0; i < source.size(); i++) {
        if(source.substr(i, pattern.size()) == pattern) {
            ret.push_back(buff);
            i += pattern.size() - 1;
            buff.clear();
        } else {
            buff += source[i];
        }
    }
    ret.push_back(buff);
    return ret;
}

int main(void) {
    memset(maze, 0, sizeof(maze));

    int ai, aj, s;
    string p;
    vector<string> ok;

    while(getline(cin, p)) {
        ok.clear();
        ok = split(p, ",");

        aj = ok[1].size() > 1 ? 10 : ok[1][0] - '0';
        ai = ok[0].size() > 1 ? 10 : ok[0][0] - '0';
        s = ok[2].size() > 1 ? 10 : ok[2][0] - '0';

        if(s == 1) {
            for(i = 0; i < 5; i++) {
                xi = ai + sx[i];
                xj = aj + sy[i];

                if(isValid(xi, xj)) {
                    maze[xi][xj] += 1;
                }
            }
        } else if(s == 2) {
            for(i = 0; i < 9; i++) {
                xi = ai + mx[i];
                xj = aj + my[i];

                if(isValid(xi, xj)) {
                    maze[xi][xj] += 1;
                }
            }
        } else {
            for(i = 0; i < 13; i++) {
                xi = ai + lx[i];
                xj = aj + ly[i];

                if(isValid(xi, xj)) {
                    maze[xi][xj] += 1;
                }
            }
        }
    }

    int mx = 0, ct = 0;

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            if(maze[i][j] == 0) ct += 1;
            mx = max(mx, maze[i][j]);
        }
    }
    cout << ct << endl << mx << endl;
    return 0;
}
