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

int i, n, dist[610];
string a, b;

void dijsktra() {
    while(1) {
        int close = -1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n) {
        for(int i = 0; i <= 600; i++) dist[i] = 1 << 23;
        vector<pair<int, pair<string, string> > > v;
        map<string, pair<st
        REP(i, n) {
            cin >> a >> b >> c;
            v.push_back(make_pair(c, make_pair(a, b));
            v.push_back(make_pair(c, make_pair(b, a)));
        }
        cin >> a >> b;
        disjktra(a, b);
    }
    return 0;
}

