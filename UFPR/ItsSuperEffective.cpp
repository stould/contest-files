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

map<string, int> mp;
int mark[20][20];

void build (void) {
    mp["Normal"] = 1;
    mp["Fire"] = 2;
    mp["Water"] = 3;
    mp["Electric"] = 4;
    mp["Grass"] = 5;
    mp["Ice"] = 6;
    mp["Fighting"] = 7;
    mp["Poison"] = 8;
    mp["Ground"] = 9;
    mp["Flying"] = 10;
    mp["Psychic"] = 11;
    mp["Bug"] = 12;
    mp["Rock"] = 13;
    mp["Ghost"] = 14;
    mp["Dragon"] = 15;

    memset(mark, 0, sizeof(mark));

    mark[1][1] = 0;
    mark[1][2] = 0;
    mark[1][3] = 0;
    mark[1][4] = 0;
    mark[1][5] = 0;
    mark[1][6] = 0;
    mark[1][7] = 0;
    mark[1][8] = 0;
    mark[1][9] = 0;
    mark[1][10] = 0;
    mark[1][11] = 0;
    mark[1][12] = 0;
    mark[1][13] = 1;
    mark[1][14] = 0;
    mark[1][15] = 0;

    mark[2][2] = 1;
    mark[2][3] = 1;
    mark[2][5] = 2;
    mark[2][6] = 2;
    mark[2][12] = 2;
    mark[2][13] = 1;
    mark[2][15] = 1;

    mark[3][2] = 2;
    mark[3][3] = 1;
    mark[3][5] = 1;
    mark[3][9] = 2;
    mark[3][13] = 2;
    mark[3][15] = 1;

    mark[4][1] = 0;
    mark[4][2] = 0;
    mark[4][3] = 2;
    mark[4][4] = 1;
    mark[4][5] = 1;
    mark[4][6] = 0;
    mark[4][7] = 0;
    mark[4][8] = 0;
    mark[4][9] = 0;
    mark[4][10] = 2;
    mark[4][11] = 0;
    mark[4][12] = 0;
    mark[4][13] = 0;
    mark[4][14] = 0;
    mark[4][15] = 1;

    mark[5][1] = 0;
    mark[5][2] = 1;
    mark[5][3] = 2;
    mark[5][4] = 0;
    mark[5][5] = 1;
    mark[5][6] = 0;
    mark[5][7] = 0;
    mark[5][8] = 1;
    mark[5][9] = 2;
    mark[5][10] = 1;
    mark[5][11] = 0;
    mark[5][12] = 1;
    mark[5][13] = 2;
    mark[5][14] = 0;
    mark[5][15] = 1;

    mark[6][1] = 0;
    mark[6][2] = 0;
    mark[6][3] = 1;
    mark[6][4] = 0;
    mark[6][5] = 2;
    mark[6][6] = 1;
    mark[6][7] = 0;
    mark[6][8] = 0;
    mark[6][9] = 0;
    mark[6][10] = 2;
    mark[6][11] = 0;
    mark[6][12] = 0;
    mark[6][13] = 0;
    mark[6][14] = 0;
    mark[6][15] = 2;

    mark[7][1] = 2;
    mark[7][2] = 0;
    mark[7][3] = 0;
    mark[7][4] = 0;
    mark[7][5] = 0;
    mark[7][6] = 2;
    mark[7][7] = 0;
    mark[7][8] = 1;
    mark[7][9] = 0;
    mark[7][10] = 1;
    mark[7][11] = 1;
    mark[7][12] = 1;
    mark[7][13] = 2;
    mark[7][14] = 0;
    mark[7][15] = 0;

    mark[8][1] = 0;
    mark[8][2] = 0;
    mark[8][3] = 0;
    mark[8][4] = 0;
    mark[8][5] = 2;
    mark[8][6] = 0;
    mark[8][7] = 0;
    mark[8][8] = 1;
    mark[8][9] = 1;
    mark[8][10] = 0;
    mark[8][11] = 0;
    mark[8][12] = 2;
    mark[8][13] = 1;
    mark[8][14] = 1;
    mark[8][15] = 0;

    mark[9][1] = 0;
    mark[9][2] = 2;
    mark[9][3] = 0;
    mark[9][4] = 2;
    mark[9][5] = 1;
    mark[9][6] = 0;
    mark[9][7] = 0;
    mark[9][8] = 2;
    mark[9][9] = 0;
    mark[9][10] = 0;
    mark[9][11] = 0;
    mark[9][12] = 1;
    mark[9][13] = 2;
    mark[9][14] = 0;
    mark[9][15] = 0;

    mark[10][1] = 0;
    mark[10][2] = 0;
    mark[10][3] = 0;
    mark[10][4] = 1;
    mark[10][5] = 2;
    mark[10][6] = 0;
    mark[10][7] = 2;
    mark[10][8] = 0;
    mark[10][9] = 0;
    mark[10][10] = 0;
    mark[10][11] = 0;
    mark[10][12] = 2;
    mark[10][13] = 1;
    mark[10][14] = 0;
    mark[10][15] = 0;


    mark[11][1] = 0;
    mark[11][2] = 0;
    mark[11][3] = 0;
    mark[11][4] = 0;
    mark[11][5] = 0;
    mark[11][6] = 0;
    mark[11][7] = 2;
    mark[11][8] = 2;
    mark[11][9] = 0;
    mark[11][10] = 0;
    mark[11][11] = 1;
    mark[11][12] = 0;
    mark[11][13] = 0;
    mark[11][14] = 0;
    mark[11][15] = 0;


    mark[12][1] = 0;
    mark[12][2] = 1;
    mark[12][3] = 0;
    mark[12][4] = 0;
    mark[12][5] = 2;
    mark[12][6] = 0;
    mark[12][7] = 1;
    mark[12][8] = 2;
    mark[12][9] = 0;
    mark[12][10] = 1;
    mark[12][11] = 2;
    mark[12][12] = 0;
    mark[12][13] = 0;
    mark[12][14] = 1;
    mark[12][15] = 0;


    mark[13][1] = 0;
    mark[13][2] = 2;
    mark[13][3] = 0;
    mark[13][4] = 0;
    mark[13][5] = 0;
    mark[13][6] = 2;
    mark[13][7] = 1;
    mark[13][8] = 0;
    mark[13][9] = 1;
    mark[13][10] = 2;
    mark[13][11] = 0;
    mark[13][12] = 2;
    mark[13][13] = 0;
    mark[13][14] = 0;
    mark[13][15] = 0;


    mark[14][1] = 0;
    mark[14][2] = 0;
    mark[14][3] = 0;
    mark[14][4] = 0;
    mark[14][5] = 0;
    mark[14][6] = 0;
    mark[14][7] = 0;
    mark[14][8] = 0;
    mark[14][9] = 0;
    mark[14][10] = 0;
    mark[14][11] = 0;
    mark[14][12] = 0;
    mark[14][13] = 0;
    mark[14][14] = 2;
    mark[14][15] = 0;
    mark[14][15] = 0;


    mark[15][1] = 0;
    mark[15][2] = 0;
    mark[15][3] = 0;
    mark[15][4] = 0;
    mark[15][5] = 0;
    mark[15][6] = 0;
    mark[15][7] = 0;
    mark[15][8] = 0;
    mark[15][9] = 0;
    mark[15][10] = 0;
    mark[15][11] = 0;
    mark[15][12] = 0;
    mark[15][13] = 0;
    mark[15][14] = 0;
    mark[15][15] = 2;
}

int N, Q;

int main(void) {
    //freopen("i.in", "r", stdin);
    int i;

    string name, type;

    build();

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        map<string, string> p;

        for (i = 0; i < N; i++) {
            cin >> name >> type;
            p[name] = type;
        }

        Q = in();

        for ( ; Q--; ) {
            string a, b;
            cin >> a >> b;

            int kind = mark[mp[p[a]]][mp[p[b]]];

            if (kind == 0) {
                puts("Regular Attack.");
            } else if (kind == 1) {
                puts("It's not very effective...");
            } else {
                puts("It's super effective!");
            }
        }

        puts("");
    }
    return 0;
}
