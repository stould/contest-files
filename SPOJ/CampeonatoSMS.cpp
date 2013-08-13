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

const int MAXN = 170;

int N;
string buff, str;

double dp[MAXN][15][15];
double dist[15][15];

map<char, int> belong;
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

    belong['a'] = belong['b'] = belong['c'] = 2;
    belong['d'] = belong['e'] = belong['f'] = 3;
    belong['g'] = belong['h'] = belong['i'] = 4;
    belong['j'] = belong['l'] = belong['k'] = 5;
    belong['m'] = belong['n'] = belong['o'] = 6;
    belong['p'] = belong['q'] = belong['r'] = belong['s'] = 7;
    belong['t'] = belong['u'] = belong['v'] = 8;
    belong['w'] = belong['x'] = belong['y'] = belong['z'] = 9;
    belong['#'] = 10;
    belong[' '] = 11;

    types[' '] = 1;
    types['#'] = 1;
    types['a'] = types['d'] = types['g'] = types['j'] = types['m'] = types['p'] = types['t'] = types['w'] = 1;
    types['b'] = types['e'] = types['h'] = types['k'] = types['n'] = types['q'] = types['u'] = types['x'] = 2;
    types['c'] = types['f'] = types['i'] = types['l'] = types['o'] = types['r'] = types['v'] = types['y'] = 3;
    types['s'] = types['z'] = 4;

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 3; j++) {
            for (k = 1; k <= 4; k++) {
                for (l = 1; l <= 3; l++) {
                    int id_a = decode(i, j), id_b = decode(k, l);

                    if (id_a == -1 || id_b == -1) continue;

                    //printf("%d %d - %.2lf\n", decode(i, j), decode(k, l), hypot(i - k, j - l));

                    dist[id_a][id_b] = (double) hypot(i - k, j - l);
                }
            }
        }
    }
}

void clear(void) {
    int i, j, k;

    for (i = 0; i < MAXN; i++) {
        for (j = 0; j < 15; j++) {
            for (k = 0; k < 15; k++) {
                dp[i][j][k] = -1.0;
            }
        }
    }
}

int same(char a, char b) {
    return belong[a] == belong[b];
}

double move_cost (int a, char b) {
    return dist[a][belong[b]];
}

double func(int index, int l, int r) {
    if (index >= str.size()) return 0.0;

    double& ans = dp[index][l][r];

    if (ans != -1.0) return ans;

    double l_cost = move_cost(l, str[index]);
    double r_cost = move_cost(r, str[index]);

    ans = l_cost + func(index + 1, belong[str[index]], r);

    ans = min(ans, r_cost + func(index + 1, l, belong[str[index]]));

    return ans;
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

        printf("%.2lf\n", (func(0, 4, 6) / 30.0) + clicks * 0.20);
    }
    return 0;
}
