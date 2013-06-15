#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <new>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>

#define REP(i, n) for(i = 0; i < n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define FOR(i, a, n) for(i = (a); i < (n); i++)
#define FORR(i, a, n) for(i = (a); i <= (n); i++)

using namespace std;

int i, j, n;

bool match_begin(string& novo, string b) {
    if(b[0] == novo[1]) {
        return true;
    } else if(b[0] == novo[0]) {
        reverse(novo.begin(), novo.end());
        return true;
    } else {
        return false;
    }
}

bool match_end(string& novo, string b) {
    if(b[1] == novo[0]) {
        return true;
    } else if(b[1] == novo[1]) {
        reverse(novo.begin(), novo.end());
        return true;
    } else {
        return false;
    }
}

string valid(vector<string> s) {
    int N = s.size();
    deque<string> ss;

    bool memo[N];

    memset(memo, 0, sizeof(memo));

    ss.push_back(s[0]);
    memo[0] = true;

    REP(i, N) {
        REP(j, N) {
            if(!memo[j] && match_begin(s[j], ss[0])) {
                memo[j] = true;
                ss.push_front(s[j]);
            } else if(!memo[j] && match_end(s[j], ss[ss.size() - 1])) {
                memo[j] = true;
                ss.push_back(s[j]);
            }
        }
    }

    if(ss.size() != s.size()) return "No";


    bool ok = true;

    REP(i, N) {
        if(!memo[i]) ok = false;
    }
    if(ok) return "Yes";
    return "No";
}

int main(void) {
    while(~scanf("%d", &n)) {
        vector<string> v(n);
        REP(i, n) {
            cin >> v[i];
        }
        cout << valid(v) << endl;
    }
    return 0;
}

