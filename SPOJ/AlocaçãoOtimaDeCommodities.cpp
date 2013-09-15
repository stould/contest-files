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
#include <numeric>
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1300031;
int T, I, F, N, now;

template<typename T>
T lcm(T a, T b) {
    return (a * b / __gcd(a, b));
}

int readInt(void) {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();

	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') {
	    minus = true;
    } else {
        result = ch-'0';
    }

	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main(void) {
    T = readInt();
    for( ; T--; ) {
        I = readInt();
        F = readInt();
        N = readInt();
        vector<int> v(N);

        REP(i, N) v[i] = readInt();

        ll ans = 0LL;

        for(int x = 0; x < (1 << N); x++) {
            if(__builtin_popcount(x) == 0) continue;

            ll mmc = 1LL;
            for(int i = 0; i < N; i++) if(x & (1<<i)    ) {
                mmc = lcm(mmc, (ll) v[i]);
            }

            ll low = mmc + (I - I % mmc), high = F - (F % mmc);

            if(I % mmc == 0) low = I;

            ll sum = ((low + high) * ((high - low + mmc)/mmc) / 2LL);


            if(__builtin_popcount(x) & 1) {
                ans = ((ans % MOD) + (sum % MOD)) % MOD;
            } else {
                ans = ((ans % MOD) - (sum % MOD) + MOD) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
