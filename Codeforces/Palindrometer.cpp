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

int toInt(string s) {
    int ans;

    istringstream ss(s);

    ss >> ans;

    return ans;
}

bool comp(string a, string b) {
    return toInt(a) < toInt(b);
}

set<int> pal;

void build(string s) {
    if (s.size() > 9) return;

    pal.insert(toInt(s));

    char c;

    for (c = '0'; c <= '9'; c++) {
        build(c + s + c);
    }
}

string s;

int main(void) {
    freopen("i.in", "r", stdin);
    build("");

    char c;

    for (c = '0'; c <= '9'; c++) {
        build(string(1, c));
    }

    for ( ; cin >> s && s != "0"; ) {
        set<int>::iterator it = upper_bound(pal.begin(), pal.end(), toInt(s));

        cout << s << " " << *it << "\n";

        printf("%d\n", *it - toInt(s));
    }

    return 0;
}

