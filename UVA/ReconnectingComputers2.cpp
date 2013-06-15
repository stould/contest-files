#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

struct Edge {
    int f, t, c;
    Edge() {}
    Edge(int _f, int _t, int _c) {
        f = _f;
        t = _t;
        c = _c;
    }
    bool operator<(const Edge& e) {
        return c < e.c;
    }
};

int n, i, a, b, c;

vector<Edge> v;

int Kruskal(vector<Edge>& v, int n) {
    vector<int> t(n);
    for(int a = 0; a < n; a++) {
        t[a] = a;
    }
    for(int i = 0; i < v.size(); i++) {

    }
}

int main(void) {
    while(cin >> c) {
        v.clear();
        int sum = 0;
        for(i = 0; i < n; i++) {
            cin >> a >> b >> c;
            v.push_back(Edge(a - 1, b - 1, c));
            sum += d;
        }
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> a >> b >> c;
            v.push_back(Edge(a - 1, b - 1, c));
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            v.push_back(Edge(a - 1, b - 1, c));
        }
        cout << sum << endl;
        cout << Kruskal(v, n) << endl;
    }
    return 0;
}

