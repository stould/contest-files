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

int i, j, k, n, m, v = 1;
char maze[101][101];
char mine[101][101];

int dx[8] = {1, 1,  1,  0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1,  0,  1, 1};

int main(void) {
    while(scanf("%d%d", &n, &m)) {
        if(!n && !m) break;
        if(v != 1) printf("\n");
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf(" %c", &maze[i][j]);
            }
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(maze[i][j] == '*') {
                    mine[i][j] = '*';
                } else {
                    int cont = 0;
                    for(k = 0; k < 8; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
                            if(maze[ni][nj] == '*') {
                                cont++;
                            }
                        }
                    }
                    mine[i][j] = (char) ('0' + cont);
                }
            }
        }
        printf("Field #%d:\n", v);
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                printf("%c", mine[i][j]);
            }
            printf("\n");
        }
        v += 1;
    }
    return 0;
}

