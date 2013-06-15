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


const double EPS = 1e-9;
int vp, vd, t, f, c;

bool cmp(double a, double b) {
    return a > b || fabs(a-b) < EPS;
}

bool func(int jewel) {
    double pri = vp * t;
    if(cmp(vp, vd)) return 1;
    while(jewel >= 0) {
        double need = pri / (vd - vp);
        pri += need * vp;
        if(cmp(pri, c)) break;
        jewel -= 1;
        need = pri / vd + f;
		pri += need * vp;
    }
    return jewel >= 0;
}

int main(void) {
    while(scanf("%d%d%d%d%d", &vp, &vd, &t, &f, &c) == 5) {
        int low = 0, high = 1001001001, mid;

        while(low <= high) {
            mid = (high + low) >> 1;
            if(func(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        printf("%d\n", low);
    }
    return 0;
}
