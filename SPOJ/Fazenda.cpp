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
#include <numeric>
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

const int MAXN = 1007;
int N, X, Y, L, C, matrix[MAXN][MAXN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    freopen("i.in", "r", stdin);
    for( ; scanf("%d", &N) && N != 0; ) {
        int area = 0, perimeter = 0;

        REP(i, MAXN) REP(j, MAXN) matrix[i][j] = 0;

        REP(i, N) {
            scanf("%d%d%d%d", &X, &Y, &L, &C);
            for(int a = 1000 - Y; a >= 1000 - Y - L; a--) {
                for(int b = X; b <= X + C; b++) {
                    //cout << (1000-a) << " " << b << "\n";
                    matrix[a][b] = 1;
                }
            }
        }

        for(int i = 1000 - 10; i < 1000; i++) {
            for(int j = 1000 - 10; j < 1000; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }


        REP(i, 1001) REP(j, 1001) if(matrix[i][j] == 1) {
            area += 1;
            int cnt = 0;
            REP(k, 4) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni < 0 || nj < 0 || ni > 1000 || nj > 1000) continue;
                if(matrix[ni][nj] == 0) {
                    perimeter += 1;
                    cnt += 1;
                }
            }
            //printf("%d %d %d\n", i, j, cnt);
        }
        //printf("\n");
        printf("%d %d\n", area, perimeter);
    }
    return 0;
}
