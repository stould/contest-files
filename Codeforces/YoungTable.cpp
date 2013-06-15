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

using namespace std;

typedef long long ll;
typedef long double ld;

int N, C[60], now[60][60], base = 1;

int main(void) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", &C[i]);
    REP(i, N) REP(j, C[i]) {
        scanf("%d", &now[i][j]);
    }
    int ans = 0;
    vector<pair<pair<int, int>, pair<int, int> > > mp;
    REP(i, N) {
        REP(j, C[i]) {
            if(now[i][j] != base) {
                REP(k, N) REP(l, C[k]) if(now[k][l] == base) {
                    ans += 1;
                    mp.push_back(make_pair(make_pair(i+1, j+1), make_pair(k+1, l+1)));
                    swap(now[i][j], now[k][l]);
                }
            }
            base += 1;
        }
    }
    printf("%d\n", ans);
    REP(i, mp.size()) {
        printf("%d %d %d %d\n", mp[i].first.first, mp[i].first.second, mp[i].second.first, mp[i].second.second);
    }
    return 0;
}
