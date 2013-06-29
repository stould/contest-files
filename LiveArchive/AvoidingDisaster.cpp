
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

using namespace std;

typedef long long ll;
typedef unsigned uint;

int N;
string str, dummy;

struct t_rep {
    string rep;
    int m, h;

    t_rep() {}

    t_rep(string _rep) {
        this->rep = _rep;

        if (this->rep.size() == 5) {
            h = atoi(this->rep.substr(0, 2).c_str()) % 12;
            m = atoi(this->rep.substr(3, 2).c_str());
        } else {
            h = atoi(this->rep.substr(0, 1).c_str()) % 12;
            m = atoi(this->rep.substr(2, 2).c_str());
        }
    }

    bool eq(int add, struct t_rep& t) {
        int n_h, n_m;

        if (add >= 0) {
            n_m = (m + add) % 60, n_h = h + (int) (floor (m + add) / 60.0);
        } else {
            n_m = (((m + add) % 60) + 60) % 60, n_h = h + ((((int) floor((m + add) / 60.0)) % 12));
        }
        if (n_h < 0) n_h = 12+n_h;

        n_h %= 12;

        return n_h == t.h && n_m == t.m;
    }
};

void split(vector<string>& v, const string& s) {
    istringstream ss(s, istringstream::in);
    v.clear(); string t;
    while(ss >> t) {
        v.push_back(t);
    }
}

int main(void) {
    scanf("%d", &N);

    int i, j, k, x;

    getline(cin, dummy);

    for ( ; N--; ) {
        getline(cin, str);
        vector<t_rep> v(3);
        vector <string> vc; split(vc, str);

        v[0] = t_rep(vc[0]);
        v[1] = t_rep(vc[1]);
        v[2] = t_rep(vc[2]);

        int done = 0;

        set<string> ans;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) if (i != j) {
                for (k = 0; k < 3; k++) if (j != k && i != k) {
                    for (x = 1; x < 480; x++) {
                        if (v[i].eq(x, v[k]) && v[i].eq(-x, v[j])) {
                            ans.insert(v[i].rep);
                        }
                    }
                }
            }
        }

        if (ans.size() != 1) {
            puts("Look at the sun");
        } else {
            printf("The correct time is %s\n", ans.begin()->c_str());
        }
    }
    return 0;
}
