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

using namespace std;

typedef long long Int;
typedef unsigned uint;

Int A, B;

Int func (Int x) {
    if (x <= 100LL) {
        return 2LL * x;
    } else if (x > 100LL && x <= 10000LL) {
        return 2LL * 100LL + 3LL * (x - 100LL);
    } else if (x > 10000LL && x <= 1000000LL) {
        return 2LL * 100LL + 3LL * 9900LL + 5LL * (x - 10000LL);
    } else {
        return 2LL * 100LL + 3LL * 9900LL + 5LL * 990000LL + 7LL * (x - 1000000LL);
    }
}

Int rev (Int x) {
    if (x <= 200LL) {
        return x / 2LL;
    } else if (x > 200LL && x <= 29900LL) {
        return (x + 100LL) / 3LL;
    } else if (x > 29900LL && x <= 4979900LL) {
        return (x + 20100LL) / 5LL;
    } else {
        return (x + 2020100LL) / 7LL;
    }
}

int main(void) {
    int i;

    for ( ; scanf("%lld%lld", &A, &B) == 2 && (A + B != 0); ) {
        Int total_w = rev(A), l = 1LL, h = total_w / 2LL, m;

        int done = 0;

        for ( ; h - l >= 1; ) {
            m = (Int) (l + (h - l) / 2LL);

            Int X = func(m), Y = func(llabs(total_w-m)), s = llabs(X-Y);

            //printf("%lld %lld %lld %lld\n", X, Y, s, B);

            if (s == B) {
                printf("%lld\n", min(X, Y));
                done = 1;
                break;
            } else if (s > B) {
                l = m + 1LL;
            } else {
                h = m - 1LL;
            }
        }

        if (!done) {
            int x;
            for (x = 0; x <= 100 && !done; x++) {
                Int X = func(m), Y = func(llabs(total_w-m)), s = llabs(X-Y);

                if (s == B) {
                    printf("%lld\n", min(X, Y));
                    done = 1;
                    break;
                }
                m += 1;
            }
            m -= 100LL;
            for (x = 0; x <= 100 && !done; x++) {
                Int X = func(m), Y = func(llabs(total_w-m)), s = llabs(X-Y);

                if (s == B) {
                    printf("%lld\n", min(X, Y));
                    done = 1;
                    break;
                }
                m -= 1LL;
            }
        }
    }
    return 0;
}
