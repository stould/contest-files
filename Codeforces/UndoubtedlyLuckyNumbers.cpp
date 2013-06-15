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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 1000000000;

int pre[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 22, 33, 44, 55, 66, 77, 88, 99};
map<ll, int> mp;
ll x, tmp, ans = 0LL;
vector<ll> hp;

string longtostr(ll x) {
    string ans = "";
    while(x > 0) {
        ans += x%10LL+'0';
        x /= 10LL;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll strtol(string s) {
    ll ans = 0LL;
    for(int i = s.size() - 1; i >= 0; i--) {
        ans += s[i] - '0' * (ll) pow(10.0, s.size()-1-i);
    }
    return ans;
}

void generate(int x, int y, ll start) {
    if(start > MAXN) return;
    if(mp[start] == 0) {
        mp[start] = 1;
        if(start > 0 && start <= tmp) {
            ans += 1;
            hp.push_back(start);
        }
    }
    if(start != 0 && x == 0) {
        cout << strtol(longtostr(start*10)+'0') << "adsas\n";
        generate(x, y, (ll)strtol(longtostr(start*10)+'0'));
    } else {
        generate(x, y, (ll)start*10+x);
    }
    if(start != 0 && y == 0) {
        generate(x, y, (ll)strtol(longtostr(start*10)+'0'));
    } else {
        generate(x, y, (ll)start*10+y);
    }
}

void generate2(ll start) {
    if(start > MAXN) return;

    if(mp[start] == 0) {
        mp[start] = 1;
        if(start > 0 && start <= tmp) {
            ans += 1;
            hp.push_back(start);
        }
    }
    generate2(start*10LL);
}

int main(void) {
  //  freopen("i.in", "r", stdin);
    int i, j;
    cin >> tmp;
    REP(i, 19) generate2(pre[i]);
    FOR(i, 0, 10) FOR(j, 0, 10) generate(i, j, 0LL);
    sort(hp.begin(), hp.end());
    REP(i, hp.size()) {
        cout << hp[i] << "\n";
    }
    cout << ans << "\n";
    return 0;
}
