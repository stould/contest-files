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

int N, now, ans = 0;
map<int, int> mp;

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", &now);
        if(now == 4) {
            ans += 1;
        } else {
            mp[now] += 1;
        }
    }
    if(mp[1] != 0 && mp[3] != 0) {
        int th1 = min(mp[1], mp[3]);
        mp[1] -= th1; mp[3] -= th1;
        ans += th1;
    }
    if(mp[3] > 0) {
        ans += mp[3];
        mp[3] = 0;
    }
    if(mp[2] >= 2) {
        ans += mp[2]*2/4;
        if(mp[2] % 2 == 0) {
            mp[2] = 0;
        } else {
            mp[2] = 1;
        }
    }
    int summie = mp[1] + (mp[2]*2);
    if(summie <= 4 && summie != 0) {
        ans += 1;
    } else {
        ans += summie / 4;
        if(summie % 4 != 0) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
