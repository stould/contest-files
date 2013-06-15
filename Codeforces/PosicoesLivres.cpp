#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

int a, b, c, d, w, h, n, maze[510][510];

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d%d", &w, &h, &n) && n > 0 && h > 0 && w > 0) {
        memset(maze, 0, sizeof(maze));
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            for(; a <= c; a++) {
                for(; b <= d; b++) {
                    maze[a][b] = 1;
                }
            }
        }
        int spot = 0;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                if(maze[i][j] == 0) spot++;
            }
        }
        if(spot == 0) {
            printf("There is no empty spots.");
        } else if(spot == 1) {
            printf("There is one empty spot.");
        } else {
            printf("There are %d empty spots.", spot);
        }
    }
    return 0;
}
