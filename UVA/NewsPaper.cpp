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

string str;
int N, K, M, v;
char c;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);
    for( ; N-- ; ) {
        scanf("%d", &K);
        map<char, int> mc;
        REP(i, K) {
            scanf(" %c%d", &c, &v);
            mc[c] = v;
        }
        scanf("%d", &M);
        ll ans = 0;
        cin.ignore();
        REP(i, M) {
            getline(cin, str);
            REP(j, str.size()) {
                ans += (ll) mc[str[j]];
            }
        }
        printf("%lld.%02lld$\n", ans / 100LL, ans % 100LL);

    }
    return 0;
}
