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

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int n, d, m, l;

int main(void) {
    scanf("%d%d%d%d", &n, &d, &m, &l);
    int base = d;
    while(1) {
        int low = 1, high = n, mid;

        int ok = 0, ans = 0;

        while(low < high) {
            mid = (high + low) / 2;
            int start = (mid - 1) * m, end = ((mid - 1) * m) + l;

            printf("%d - %d %d\n", base, start, end);

            if(base >= low && base <= high) {
                ok = 1;
                break;
            } else if(low < base) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(!ok) {
            printf("%d\n", base);
            break;
        }
        base += d;
    }
    return 0;
}
