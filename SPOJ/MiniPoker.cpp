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

int N, T, v[9];
map<int, int> mp;
set<int> s;

bool a (void) {
    for(int i = 1; i < 5; i++) if(v[i] != v[i - 1] + 1) return false;
    return true;
}

bool b (void) {
    if (s.size() != 2) return false;

    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++) {
        if (mp[*it] == 4) return true;
    }

    return false;
}

int ans_b (void) {
    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++) {
        if (mp[*it] == 4) return 180 + *it;
    }

    return -1;
}

bool c (void) {
    if (s.size() != 2) return false;

    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++) {
        if (mp[*it] == 3) return true;
    }

    return false;
}

int ans_c (void) {
    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++) {
        if (mp[*it] == 3) return 160 + *it;
    }

    return -1;
}

bool d (void) {
    if (s.size() != 3) return false;

    int i, v_a = 0;

    for (i = 0; i < 5; i++) {
        if (mp[v[i]] == 3) v_a = 1;
    }

    return v_a;
}

int ans_d (void) {
    int i;

    for (i = 0; i < 5; i++) {
        if (mp[v[i]] == 3) return 140 + v[i];
    }

    return -1;
}

bool e (void) {
    if (s.size() != 3) return false;

    int i, v_a = 0, v_b = 0;

    for (i = 0; i < 5; i++) {
        if (!v_a && mp[v[i]] == 2) v_a = 1;
        else if (!v_b && mp[v[i]] == 2) v_b = 1;
    }

    return v_a && v_b;
}

int ans_e (void) {
    int i, v_a = 0, v_b = 0, ans = 0;

    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++) {
        if (!v_a && mp[*it] == 2) {
            ans += 2 * (*it); v_a = 1;
        } else if (!v_b && mp[*it] == 2) {
            ans += 3 * (*it);
        }
    }

    return ans + 20;
}

bool f (void) {
    return s.size() == 4;
}

int ans_f (void) {
    int i;

    for (i = 0; i < 5; i++) if (mp[v[i]] == 2) return v[i];

    return -1;
}

int main(void) {
    scanf("%d", &N);

    T = 1;

    for ( ; N--; ) {
        s.clear(); mp.clear();
        REP(i, 5) {
            scanf("%d", &v[i]); s.insert(v[i]);
            mp[v[i]] += 1;
        }

        sort(v, v + 5);

        printf("Teste %d\n", T++);

        if (a()) {
            printf("%d\n", v[0] + 200);
        } else if (b()) {
            printf("%d\n", ans_b());
        } else if (c()) {
            printf("%d\n", ans_c());
        } else if (d()) {
            printf("%d\n", ans_d());
        } else if (e()) {
            printf("%d\n", ans_e());
        } else if (f()) {
            printf("%d\n", ans_f());
        } else if (s.size() == 5) {
            printf("0\n");
        }

        printf("\n");
    }
    return 0;
}
