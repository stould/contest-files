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

using namespace std;

#define REP(i, n) for(i = 0; i < n; i++)
#define sz(n) n.size()

int i, n, r, c;

void shuffle(vector<int>& v, int c) {
    deque<int> b(v.begin(), (v.begin() + (sz(v) / 2)));
    deque<int> a(v.begin() + sz(v) / 2, v.end());

    vector<int> nova;

    while(1) {
        for(int x = 0; x < c && a.size() > 0; x++) {
            nova.push_back(a.front());
            a.pop_front();
        }
        for(int x = 0; x < c && b.size() > 0; x++) {
            nova.push_back(b.front());
            b.pop_front();
        }
        if(a.empty() && b.empty()) break;
    }
    v = nova;
}
int main() {
    while(~scanf("%d%d", &n, &r)) {
        vector<int> v(n);
        REP(i, n) { v[i] = i; }
        REP(i, r) {
            scanf("%d", &c);
            shuffle(v, c);
        }
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}

