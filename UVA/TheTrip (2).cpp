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

int i, n;
double memo[1001];

int main(void) {
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);
    while(cin >> n) {
        if(!n) break;
        double amount = 0.0;
        for(i = 0; i < n; i++) {
            cin >> memo[i];
            amount += (double) memo[i];
        }
        amount = (double) amount / n;
        double left = 0.0, right = 0.0;
        for(i = 0; i < n; i++) {
            double diff = memo[i] - amount;
            if(diff > 0) {
                right += (double) floor((diff) * 100) / 100;
            } else {
                left -= (double) ceil((diff)* 100) / 100;
            }
        }
        cout << "$" << (right > left ? right : left) << endl;
    }
    return 0;
}

