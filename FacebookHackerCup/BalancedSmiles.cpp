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

int T;
string str;
bool ok;

int rec(int pos, stack<int>& s) {
    if(pos >= str.size()) return 0;
    if(str[pos] == '(') {
        s.push(1);
        return 1 + rec(pos + 1, s);
    } else if(str[pos] == ')') {
        if(!s.empty()) s.pop();
        return -1 + rec(pos + 1, s);
    } else if(str[pos] == ':') {
        if(pos + 1 < str.size())
    } else {
        return  rec(pos + 1, s);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> T;
    REP(x, T) {
        ok = 0;
        getline(cin, str);
        stack<int> s;
        int ok = rec(0, s);
        if(s.size() == 0 && ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
