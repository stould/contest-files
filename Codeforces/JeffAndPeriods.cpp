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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

map<int, vector<int> > b;
map<int, vector<int> >::iterator it;
int N;

int func(vector<int>& v) {
    int i;

    if (v.size() == 1) return 0;

    int p = v[1] - v[0];

    for (i = 2; i < (int) v.size(); i++) {
        if (v[i] - v[i - 1] != p) return -1;
    }

    return p;
}

int main(void) {
    N = in();

    int i;

    for (i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        b[x].push_back(i);
    }

    vector<pair<int, int> > ans;

    for (it = b.begin(); it != b.end(); it++) {
        int p = func(it->second);
        if (p != -1) {
            ans.push_back(make_pair(it->first, p));
        }
    }

    printf("%d\n", (int) ans.size());

    for (i = 0; i < (int) ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
