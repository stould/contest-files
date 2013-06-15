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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 25;
int T, N, M;
char c[MAXN][MAXN];

int dx[8] = {0, 0,  1, -1, 1, -1,  1, -1};
int dy[8] = {1, -1, 0,  0, 1, -1, -1,  1};

int main(void) {
    scanf("%d", &T);
    for(int x = 0; x < T; x++) {
        scanf("%d%d", &N, &M);
        REP(i, N) {
            scanf("%s", c[i]);
        }
        bool ok = true;
        REP(i, N) REP(j, M) {
            if (!ok) break;
            if(c[i][j] != 'F') {
                int num = c[i][j] - '0', check = 0;
                REP(k, 8) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= 0 && ny >= 0 && nx < N && ny < M && c[nx][ny] == 'F') {
                        check += 1;
                    }
                }
                if(num != check) ok = false;
            }
        }
        if(ok) printf("Well done Clark!");
        else printf("Please sweep the mine again!");
        printf("\n");
    }
    return 0;
}
