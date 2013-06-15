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
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

int parse(string s, int base) {
    int i,ans=0;

    REP(i,s.length()){
        int x = ((s[i] >= 'A' && s[i] <= 'Z') ? (s[i] - 'A' + 10) : (s[i] - '0'));
        if(x >= base) return -1;
        ans = ans * base + x;
    }

    return ans;
}

int main(void) {
    string s;
    vector<int> v;

    cin >> s;
    int i = 0;
    for(;i < sz(s); i++) {
        if(s[i] == ':') break;
    }
    string h = s.substr(0, i);
    string m = s.substr(i + 1);

    for(int i = 2; i <= 80; i++) {
        int th = parse(h, i);
        int tm = parse(m, i);

        if(th >= 0 && th <= 23 && tm >= 0 && tm <= 59) {
            v.push_back(i);
        }
    }

    if(v.size() == 0) {
        v.push_back(0);
    } else if(v[sz(v) - 1] > 60) {
        v.clear();
        v.push_back(-1);
    }
    for(int i = 0; i < sz(v); i++) {
        if(i == sz(v) - 1) {
            cout << v[i] << endl;
        } else {
            cout << v[i] << " ";
        }
    }
    return 0;
}
