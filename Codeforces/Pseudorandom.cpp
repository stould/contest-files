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

typedef long long ll;
typedef long double ld;

int a, b, m, r0, rec[10000];

int func(int n) {
    return (a * rec[n - 1] + b) % m;
}

int main(void) {
    cin >> a >> b >> m >> rec[0];

    for(int i = 1; i <= 200; i++) {
        rec[i] = func(i);
        int ct = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(rec[i] == rec[j]) {
                ct = j;
                break;
            }
        }
        if(ct) {
            cout << i - ct << endl;
            break;
        }
    }

    return 0;
}

