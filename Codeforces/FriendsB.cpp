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

int a, b, i, j, n, vis[6];

int main(void) {
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a >> b;
        vis[a]++; vis[b]++;
    }
    bool is = false;
    for(i = 1; i <= 5; i++) {
        if(vis[i] >= 3 || vis[i] < 2) is = true;
    }
    if(is) {
        cout << "WIN" << endl;
    } else {
        cout << "FAIL" << endl;
    }
    return 0;
}

