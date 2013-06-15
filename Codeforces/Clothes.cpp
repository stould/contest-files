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

int a, b, n, m, price[1010], maze[1010][1010];

int main(void) {
    cin >> n >> m;
    memset(price, 0, sizeof(price));
    memset(maze, 0, sizeof(maze));
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        maze[a-1][b-1] = maze[b-1][a-1] = 1;
    }
    ll ans = 10000000000L;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(maze[i][j] && maze[i][k] && maze[j][k] && ans > price[i] + price[j] + price[k]) {
                    ans = price[i] + price[j] + price[k];
                }
            }
        }
    }
    if(ans == 10000000000L) ans = -1;
    cout << ans << endl;
    return 0;
}
