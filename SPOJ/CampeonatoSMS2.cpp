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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 300;
const double EPS = 1e-7;

int N;
string buff, str;

double dp[MAXN][7][7][7][7];
double dist[15][15];

map<char, pair<int, int> > belong;
map<char, int> types;

int decode(int a, int b) {
    if (a == 1 && b == 2) return 2;
    else if (a == 1 && b == 3) return 3;
    else if (a == 2 && b == 1) return 4;
    else if (a == 2 && b == 2) return 5;
    else if (a == 2 && b == 3) return 6;
    else if (a == 3 && b == 1) return 7;
    else if (a == 3 && b == 2) return 8;
    else if (a == 3 && b == 3) return 9;
    else if (a == 4 && b == 2) return 11;
    else if (a == 4 && b == 3) return 10;
    else return -1;
}

void build(void) {
    int i, j, k, l;

    belong.clear(); types.clear();

    belong['a'] = belong['b'] = belong['c'] = make_pair(1, 1);
    belong['d'] = belong['e'] = belong['f'] = make_pair(1, 2);
    belong['g'] = belong['h'] = belong['i'] = make_pair(2, 1);
    belong['j'] = belong['k'] = belong['l'] = make_pair(2, 2);
    belong['m'] = belong['n'] = belong['o'] = make_pair(2, 3);
    belong['p'] = belong['q'] = belong['r'] = belong['s'] = make_pair(3, 1);
    belong['t'] = belong['u'] = belong['v'] = make_pair(3, 2);
    belong['w'] = belong['x'] = belong['y'] = belong['z'] = make_pair(3, 3);
    belong['#'] = make_pair(4, 3);
    belong[' '] = make_pair(4, 2);

    types[' '] = 1;
    types['#'] = 1;
    types['a'] = types['d'] = types['g'] = types['j'] = types['m'] = types['p'] = types['t'] = types['w'] = 1;
    types['b'] = types['e'] = types['h'] = types['k'] = types['n'] = types['q'] = types['u'] = types['x'] = 2;
    types['c'] = types['f'] = types['i'] = types['l'] = types['o'] = types['r'] = types['v'] = types['y'] = 3;

    types['s'] = types['z'] = 4;
}

void clear(void) {
    int i, j, k, l, m;

    for (i = 0; i < MAXN; i++) {
        for (j = 0; j < 7; j++) {
            for (k = 0; k < 7; k++) {
                for (l = 0; l < 7; l++) {
                    for (m = 0; m < 7; m++) {
                        dp[i][j][k][l][m] = -1.0;
                    }
                }
            }
        }
    }
}

int same(char a, char b) {
    return belong[a] == belong[b];
}

double func(int index, int l_i, int l_j, int r_i, int r_j) {
    if (index >= str.size()) return 0.0;

    double& ans = dp[index][l_i][l_j][r_i][r_j];

    if (ans != -1.0) return ans;

    pair<int, int> p = belong[str[index]];

    if (p.first == l_i && p.second == l_j) return ans = func(index + 1, l_i, l_j, r_i, r_j);
    if (p.first == r_i && p.second == r_j) return ans = func(index + 1, l_i, l_j, r_i, r_j);

    double go_l = (double) hypot(l_i - p.first, l_j - p.second) + (double) func(index + 1, p.first, p.second, r_i, r_j);
    double go_r = (double) hypot(r_i - p.first, r_j - p.second) + (double) func(index + 1, l_i, l_j, p.first, p.second);

    return ans = min(go_l, go_r);

}

int main(void) {
    freopen("i.in", "r", stdin);
    //freopen("o.ot", "w", stdout);
    int i;

    build();

    for ( ; getline(cin, buff); ) {
        clear();

        str = string(1, buff[0]);

        double clicks = types[buff[0]];

        for (i = 1; i < (int) buff.size(); i++) {
            if (same(buff[i], buff[i - 1])) {
                str += '#';
                clicks += 1.0;
            }
            str += buff[i];
            clicks += (double) types[buff[i]];
        }

        printf("%.2lf\n", ((double) func(0, 2, 1, 2, 3) * 0.033333333) + ((double) clicks * 0.20));
    }
    return 0;
}

