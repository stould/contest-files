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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N;
double P;

double ans[99] = {1.00, 21.00, 91.00, 253.00, 561.00, 1081.00, 1891.00, 3081.00, 4753.00, 7021.00, 10011.00, 13861.00, 18721.00, 24753.00, 32131.00, 41041.00, 51681.00, 64261.00, 79003.00, 96141.00, 115921.00, 138601.00, 164451.00, 193753.00, 226801.00, 263901.00, 305371.00, 351541.00, 402753.00, 459361.00, 521731.00, 590241.00, 665281.00, 747253.00, 836571.00, 933661.00, 1038961.00, 1152921.00, 1276003.00, 1408681.00, 1551441.00, 1704781.00, 1869211.00, 2045253.00, 2233441.00, 2434321.00, 2648451.00, 2876401.00, 3118753.00, 3376101.00, 3649051.00, 3938221.00, 4244241.00, 4567753.00, 4909411.00, 5269881.00, 5649841.00, 6049981.00, 6471003.00, 6913621.00, 7378561.00, 7866561.00, 8378371.00, 8914753.00, 9476481.00, 10064341.00, 10679131.00, 11321661.00, 11992753.00, 12693241.00, 13423971.00, 14185801.00, 14979601.00, 15806253.00, 16666651.00, 17561701.00, 18492321.00, 19459441.00, 20464003.00, 21506961.00, 22589281.00, 23711941.00, 24875931.00, 26082253.00, 27331921.00, 28625961.00, 29965411.00, 31351321.00, 32784753.00, 34266781.00, 35798491.00, 37380981.00, 39015361.00, 40702753.00, 42444291.00, 44241121.00, 46094401.00, 48005301.00, 49975003.00};

int main(void) {
    for ( ; scanf("%d%lf", &N, &P) == 2 && N + P != 0.0; ) {
        //(N*N - 2) * (N*N - 3) / 2;
        cout << fixed << setprecision(2) << ans[N-2] * P / 100.0 << "\n";
    }
    return 0;
}
