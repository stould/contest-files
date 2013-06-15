#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <deque>
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
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(i = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;

int i, n, r, c;

void shuffle(vector<int>& v, int c) {
    deque<int> b(v.begin(), (v.begin() + (sz(v) / 2)));
    deque<int> a(v.begin() + sz(v) / 2, v.end());

    vector<int> nova;

    int k;
    REP(k, a.size()) { cout << a[k] << " "; }
    REP(k, b.size()) { cout << b[k] << " "; }

    int xa = 0, xb = 0;
    while(!a.empty() && !b.empty()) {
        int ca = 0, cb = 0;
        for(; xa < a.size(); xa++) {
            if(ca == c) break;
            nova.push_back(a.front());
            a.pop_front();
            ca++;
        }
        for(; xb < b.size(); xb++) {
            if(cb == c) break;
            printf("d");
            nova.push_back(b.front());
            b.pop_front();
            cb++;
        }
    }
    v = nova;
}

int main() {
    scanf("%d%d", &n, &r);
        vector<int> v(n);
        REP(i, n) { v[i] = i; }
        REP(i, r) {
            scanf("%d", &c);
            cout << "A";
            shuffle(v, c);
        }
        cout << v[sz(v) - 1] << endl;

    return 0;
}
