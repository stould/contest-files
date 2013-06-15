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
#include <numeric>
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

int v[6], test = 1, all, used[120100];
bool ok;

void rec(int sum, int a, int b, int c, int d, int e, int f) {
    if(sum > all/2+1 || used[sum] == 1) return;
    used[sum] = 1;
    if(sum == all / 2) {
        ok = true;
        return;
    } else {
        if(a > 0) rec(sum+1, a-1, b, c, d, e, f);
        if(b > 0) rec(sum+2, a, b-1, c, d, e, f);
        if(c > 0) rec(sum+3, a, b, c-1, d, e, f);
        if(d > 0) rec(sum+4, a, b, c, d-1, e, f);
        if(e > 0) rec(sum+5, a, b, c, d, e-1, f);
        if(f > 0) rec(sum+6, a, b, c, d, e, f-1);
    }
}

int main(void) {
    while(scanf("%d%d%d%d%d%d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6]) == 6) {
        memset(used, 0, sizeof(used));

        all = 0;
        for(int i = 0; i < 6; i++) {
            if(v[i] != 0) all += (i+1) * v[i];
        }

        if(all == 0) break;

        printf("Collection #%d:\n", test++);

        ok = false;
        rec(0, v[0], v[1], v[2], v[3], v[4], v[5]);

        if(all % 2 == 0 && ok) {
            printf("Can be divided.\n");
        } else {
            printf("Can't be divided.\n");
        }
        printf("\n");
    }
    return 0;
}
