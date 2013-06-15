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
#include <numeric>
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

typedef unsigned long long hash;
map<string, int> mp;

const int MAXN = 120007;
hash BASE = 29ULL, power[MAXN];
string str;
vector<string> vs;
set<hash> s;

void build(void) {
    power[0] = 1ULL;
    FOR(i, 1, MAXN) {
        power[i] = power[i-1]*BASE;
    }
}

hash gethash(string str) {
    hash ans = 0;

    REP(i, str.size()) {
        ans = ans + power[i] * (str[i]-'a'+1);
    }

    return ans;
}

int main(void) {
    build();
    while(cin >> str) {
        s.insert(gethash(str));
        vs.push_back(str);
    }
    REP(i, vs.size()) FOR(j, 0, vs[i].size()-1) {
        string a1 = vs[i].substr(0, j+1), a2 = vs[i].substr(j+1, vs[i].size()-j);
        if(s.count(gethash(a1)) && s.count(gethash(a2))) {
            cout << vs[i] << "\n";
            break;
        }
    }
    return 0;
}
