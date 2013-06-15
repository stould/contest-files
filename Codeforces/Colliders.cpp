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

int n, m, ac, l;
char sign;
bool state[1000000];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}


bool isConf(int i, int j) {
    if(gcd(i, j) == 1) return true;
    return false;
}

int main(void) {
    cin >> n >> m;
    memset(state, 0, sizeof(state));

    for(int i = 0; i < m; i++) {
        cin >> sign >> ac;
        if(sign == '+') {
            if(state[ac]) {
                cout << "Already on" << endl;
            }
            bool ok = false;
            for(int x = ac + 1, y = ac - 1; x <= n || y >= 0; x++, y--) {
                if(x <= n && state[x] == true && !isConf(ac, x)) {
                    ok = true;
                    cout << "Conflict with " << x << endl;
                    break;
                } else if(y >= 0 && state[y] == true && !isConf(ac, y)) {
                    ok = true;
                    cout << "Conflict with " << y << endl;
                    break;
                }
            }
            if(ok) continue;
            if(!state[ac]) {
                state[ac] = true;
                cout << "Success" << endl;
            }
        } else {
            if(state[ac]) {
                state[ac] = false;
                cout << "Success" << endl;
            } else {
                cout << "Already off" << endl;
            }
        }
    }
}
