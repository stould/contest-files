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
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;


set<pair<int, int> > cord;
char str[111100], poss[3] = {'R', 'L', 'F'};
int i, j, k, dir = 0;
int dx[4] = { 0, 1, 0,  -1};
int dy[4] = { 1, 0, -1,  0};

pair<int, int> endline() {
    dir = 0;
    int start_x = 0, start_y = 0;
    REP(k, strlen(str)) {
        if(str[k] == 'R') {
            dir = (dir + 1) % 4;
        } else if(str[k] == 'L') {
            dir = (dir + 3) % 4;
        } else {
            start_x += dx[dir];
            start_y += dy[dir];
        }
    }
    return make_pair(start_x, start_y);
}

int main(void) {
    freopen("10.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%s", str);
    REP(i, strlen(str)) {
        char base = str[i];
        REP(j, 3) if(base != poss[j]) {
            str[i] = poss[j];
            cord.insert(endline());
        }
        str[i] = base;
    }
    printf("%d\n", (int) cord.size());
    return 0;
}

