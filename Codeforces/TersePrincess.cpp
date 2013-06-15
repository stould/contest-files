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

int i, n, a, b, v[110] = {0};

int main(void) {
    scanf("%d%d%d", &n, &a, &b);
    v[0] = 1;
    all = 1;
    for(i = 1; i < n && a > 0; i++, a--) { v[i] = v[i - 1] + 1; all += v[i]; }
    for(; i < n; i < n && b > 0; i++, b--) { v[i] = all + 1; all *= 2; }
    for(i = 0; i < n; i++) if(v[i] == 0) v[i] = n - i;
    REP(i, )
    return 0;
}
