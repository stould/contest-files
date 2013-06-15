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
#include <numeric>
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

int N, a, b;
vector<pair<int, int> > vp;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);

    vp.reserve(N);

    REP(i, N) {
        scanf("%d%d", &a, &b);
        vp.push_back(make_pair(b, a));
    }

    sort(vp.begin(), vp.end(), greater<pair<int, int> >());

    int low = vp[0].first;

    REP(i, N) {
        low = min(vp[i].first, low) - vp[i].second;
    }

    printf("%d\n", low);

    return 0;
}
