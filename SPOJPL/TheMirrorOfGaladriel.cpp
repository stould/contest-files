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

int T;
string str;

int main(void) {
    scanf("%d", &T);
    for( ; T--; ) {
        cin >> str;
        map<string, int> mp;
        vector<string> rev;

        for(int i = 0; i <= str.size(); i++) {
            for(int j = i + 1; j <= str.size(); j++) {
                string now = str.substr(i, j - i);
                mp[now] = 1;
                reverse(now.begin(), now.end());
                rev.push_back(now);
            }
        }
        bool ok = true;
        for(int i = 0; i < (int) rev.size(); i++) {
            if(mp[rev[i]] == 0) {
                ok = false;
                break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
