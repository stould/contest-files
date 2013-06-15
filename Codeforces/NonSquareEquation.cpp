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

ll N;

ll func(int x) {
    ll ans = 0LL;
    while(x > 0) {
        ans += (ll) x % 10;
        x /= 10;
    }
    return ans;
}

ll ok(int x) {
    return (ll) x * x + func(x)*x - N;
}

int main(void) {
    cin >> N;

    int low = 1, high = 100001010, found = 0, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        ll outcome = ok(mid);

        cout << mid << " " << outcome << "\n";

        if(outcome == 0) {
            found = 1;
            high = mid - 1;
        }

        if(outcome < 0) {
            low = mid + 1;
        } else if(outcome > 0) {
            high = mid - 1;
        }
    }
    if(found) {
        cout << low << "\n";
    } else {
        cout << "-1" << "\n";
    }
    return 0;
}

