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

using namespace std;

typedef long long ll;
typedef long double ld;

string in, ans = "";
int start = 0;

int main(void) {
    //freopen("i.in", "r", stdin);
    cin >> in;
    if(in.substr(0, 4) == "http") {
        ans += "http://";
        start = 4;
    } else {
        ans += "ftp://";
        start = 3;
    }
    for(int i = start; i < in.size(); i++) {
        if(i + 2 - start > 2 && i + 2 <= in.size() && in.substr(i, 2) == "ru") {
            ans += in.substr(start, i - start) + ".ru" + (i + 2 < in.size() ? "/" : "") +  in.substr(i + 2, in.size() - i + 3);
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}


