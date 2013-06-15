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

int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, -1, 1, 0};
int mat[3][3], pos[3][3];

int main(void) {
    REP(i, 3) REP(j, 3) {
        scanf("%d", &pos[i][j]);
        mat[i][j] = 1;
    }

    REP(i, 3) REP(j, 3) {
        REP(k, pos[i][j]) {
            REP(l, 5) {
                int ai = i + dx[l], aj = j + dy[l];
                if(ai >= 0 && aj >= 0 && ai < 3 && aj < 3) {
                    mat[ai][aj] ^= 1;
                }
            }
        }
    }

    REP(i, 3) {
        REP(j, 3) {
            printf("%d", mat[i][j]);
        }
        puts("");
    }

    return 0;
}
