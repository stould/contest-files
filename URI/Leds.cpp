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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

int i, j, n;
int led[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string s;

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        cin >> s;
        ll ans = 0L;
        REP(j, s.size()) {
            ans += led[s[j]-'0'];
        }
        printf("%lld leds\n", ans);
    }
    return 0;
}

