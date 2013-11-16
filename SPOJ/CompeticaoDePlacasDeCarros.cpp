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

string a, b;
int C;

map<char, int> m_new;

string forb = "ACMIP";

bool is_old(string& s) {
    int i;

    for (i = 0; i < 3; i++) {
        if (!(s[i] >= 'A' && s[i] <= 'Z')) return false;
    }

    for (i = 3; i < 7; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) return false;
    }

    return true;
}

bool is_new(string& s) {
    int i;

    for (i = 0; i < 5; i++) {
        if (!(s[i] >= 'A' && s[i] <= 'Z') || forb.find(s[i]) != string::npos) return false;
    }

    for (i = 5; i < 7; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) return false;
    }

    return true;
}

int func(string& s) {
    int i, ans = 0;

    if (is_old(s)) {
        for (i = 0; i < 3; i++) {
            ans = ans * 26 + s[i] - 'A';
        }
        for (i = 3; i < 7; i++) {
            ans = ans * 10 + s[i] - '0';
        }
    } else if (is_new(s)) {
        for (i = 0; i < 5; i++) {
            ans = ans * 21 + m_new[s[i]];
        }
        for (i = 5; i < 7; i++) {
            ans = ans * 10 + s[i] - '0';
        }
        ans += 26 * 26 * 26 * 10 * 10 * 10 * 10;
    } else {
        ans = -1;
    }
    return ans;
}

int main(void) {
    int i, id = 0;
    char c;

    for (c = 'A'; c <= 'Z'; c++) if (forb.find(c) == string::npos) {
        m_new[c] = id++;
    }

    for ( ; cin >> a >> b >> C && a != "*"; ) {
        int x_a = func(a);
        int x_b = func(b);

        if (x_a == -1 || x_b == -1 || x_a + C < x_b || x_a == x_b || x_b < x_a) {
            puts("N");
        } else {
            puts("Y");
        }
    }
    return 0;
}
