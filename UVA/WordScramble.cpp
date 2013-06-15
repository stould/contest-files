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

string str;
vector<string> vs;

void split(vector<string>& v, const string& s) {
    istringstream ss(s, istringstream::in);
    v.clear(); string t;
    while(ss >> t) {
        v.push_back(t);
    }
}

int main(void) {
    int i;
    ios_base::sync_with_stdio(false);
    for ( ; getline(cin, str); ) {
        split(vs, str);
        for (i = 0; i < vs.size(); i++) {
            reverse(vs[i].begin(), vs[i].end());
            cout << vs[i];
            if (i != vs.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
