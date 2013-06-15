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
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

ll y, n, k;
vector<int> ans;

int main(void) {
    cin >> y >> k >> n;

    for(ll r = k; r <= n; r += k) {
        if(r >= y + 1 && r <= n) ans.push_back(abs(y-r));
    }

    if(ans.empty()) {
        cout << "-1\n";
    } else {
        REP(i, ans.size()) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}


