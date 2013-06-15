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

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

const int INF = 100000;

int maze[301][301];

int a, b, c, i, j, k, n, m;
ll sum;

int main(void) {
    cin >> n;
    REP(i, n) {
        REP(j, n) {
            cin >> maze[i][j];
        }
    }
    cin >> m;
    REP(k, m) {
        sum = 0L;
        cin >> a >> b >> c; a -= 1; b -= 1;
        REP(i, n) {
            REP(j, n) {
                maze[i][j] = min (maze[i][j], maze[i][a] + maze[b][j] + c);
				maze[i][j] = min (maze[i][j], maze[i][b] + maze[a][j] + c);
                sum += maze[i][j];
            }
        }
        cout << (sum / 2) << " ";
    }
    cout << endl;
    return 0;
}

