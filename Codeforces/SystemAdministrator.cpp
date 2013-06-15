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

int n, t, x, y, all_x_1 = 0, all_y_1 = 0, all_x_2 = 0, all_y_2 = 0, n_1 = 0, n_2 = 0;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d%d", &t, &x, &y);
        if(t == 1) {
            all_x_1 += x;
            all_y_1 += y;
            n_1 += 1;
        } else {
            all_x_2 += x;
            all_y_2 += y;
            n_2 += 1;
        }
    }
    if(all_x_1 >= n_1 * 5) puts("LIVE");
    else puts("DEAD");

    if(all_x_2 >= n_2 * 5) puts("LIVE");
    else puts("DEAD");

    return 0;
}

