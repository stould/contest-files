#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define REP(i, n) for(i = 0; i < n; i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define pb(n) push_back(n);

using namespace std;

int i, k, r, m, n;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d%d", &k, &r, &m);
    vector<pair<int, int> > rest(m);
    REP(i, m) {
        scanf("%d%d", rest[i].first, rest[i].second);
    }
    scanf("%d", &n);
    vector<pair<int, pair<int, int> > > sol(n);
    REP(i, n) {
        scanf("%d%d%d", &sol[i].second.first, sol[i].second.second, sol[i].first);
    }
    REP(i, (m << 1)) {
        int count = 0;
        REP(j, n) {
            if((i << j) & 1) count += 1;
        }
        if(count <= k) {
            REP(j, n) {

            }
        }
        }
    }
    return 0;
}
