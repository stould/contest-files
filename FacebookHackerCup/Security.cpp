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

int T, M, test = 1;
string k1, k2, comb1, comb2;

string match(string a, string b) {
    string ans = "";
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != '?' && b[i] != '?' && a[i] != b[i]) return "{";
        else if(a[i] == '?' && b[i] == '?') ans += 'a';
        else if(a[i] != '?') ans += a[i];
        else ans += b[i];
    }
    return ans;
}

int main(void) {
    freopen("i.in", "r", stdin);
    //freopen("o.out", "w", stdout);
    scanf("%d", &T);
    for( ; T-- ; ) {
        cin >> M >> k1 >> k2;
        vector<string> vs, v_base;
        int sz = k1.size()/M;
        for(int i = 0; i < k2.size(); i += sz) {
            vs.push_back(k2.substr(i, sz));
            v_base.push_back(k1.substr(i, sz));
        }

        sort(vs.begin(), vs.end());

        bool ok = true;
        string now = "";

        vector<bool> used(sz, false);

        for(int i = 0; i < v_base.size(); i++) {
            string tmp = "{";
            int index = -1;
            for(int j = 0; j < vs.size(); j++) if(!used[j]) {
                string gotch = match(vs[j], v_base[i]);
                if(gotch != "{" && gotch < tmp) {
                    tmp = gotch;
                    index = j;
                }
            }
            if(index == -1) {
                ok = false;
                break;
            } else {
                now += tmp;
                used[index] = true;
            }
        }
        printf("Case #%d: ", test++);
        if(ok) {
            cout << now;
        } else {
            printf("IMPOSSIBLE");
        }
        printf("\n");
    }
    return 0;
}
