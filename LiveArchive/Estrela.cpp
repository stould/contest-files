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

int N;

int totient(int x) {
    int base = 2, ans = 0;
    vector<pair<int, int> > vp;
    while(x != 1) {
        if(x % base == 0) {
            int now = base, cnt = 0;
            while(x % base == 0) {
                cnt += 1;
                x /= base;
            }
            //printf("%d %d\n", base, cnt);
            vp.push_back(make_pair(base, cnt));
        }
        base += 1;
    }
    REP(i, vp.size()) {
        ans += (vp[i].first - 1) * pow((vp[i].first), vp[i].second - 1);
    }
    return ans;
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &N) == 1) {
        printf("%d\n", totient(N)/2LL);
    }
    return 0;
}

