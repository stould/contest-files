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

const int MAXN = 1000010;
int n;
ll v;
set<ll> s;

void build(void) {
    vector<bool> vb(MAXN, true);
    vb[0] = vb[1] = false;

    for(int i = 2; i <= sqrt(MAXN); i++) if(vb[i]) {
        for(int j = i * i; j <= MAXN; j += i) {
            vb[j] = false;
        }
    }
    FOR(i, 2, MAXN + 1) if(vb[i]) s.insert((ll)i*i);
}

int main(void) {
    build();
    cin >> n;
    REP(i, n)  {
        cin >> v;
        if(s.count(v) == 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
