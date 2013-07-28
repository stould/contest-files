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

string N;
map<string, string> mp;

int main(void) {

    mp["000"] = "0";
    mp["001"] = "1";
    mp["010"] = "2";
    mp["011"] = "3";
    mp["100"] = "4";
    mp["101"] = "5";
    mp["110"] = "6";
    mp["111"] = "7";

    int i;

    for ( ; cin >> N; ) {
        while (( (int) N.size()) % 3 != 0) N = "0" + N;

        string ans;

        for (i = 0; i < N.size(); i += 3) {
            ans += mp[N.substr(i, 3)];
        }

        cout << ans << "\n";
    }

    return 0;
}



