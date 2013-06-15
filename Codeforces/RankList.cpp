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

int i, n, k;

struct Team {
    int solved, tim, r;
    Team() {}
    Team(int a, int b) {
        solved = a;
        tim = b;
        r = 0;
    }
    bool operator<(const Team& t) const {
        return solved > t.solved || (solved == t.solved && tim < t.tim);
    }
};

int main(void) {
    cin >> n >> k; vector<Team> v(n);
    REP(i, n) {
        cin >> v[i].solved >> v[i].tim;
    }
    sort(v.begin(), v.end());
    int ans = 0, rank = 1;
    v[0].r = 1;
    for(int i = 1; i < n; i++) {
        if(v[i - 1] < v[i]) rank++;
        v[i].r = rank;
    }
    int thres = v[k - 1].r;
    REP(i, n) if(v[i].r == thres) ans++;
    cout << ans << endl;
    return 0;
}

