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

const int MAXN = (int) (10000000);
int a, b, i, j, k, primes[MAXN+10] = {0}, c[MAXN+10] = {0};

int func(int x) {
    for(int i = a; i <= b - x + 1; i++) {
        if(c[i + x - 1] - c[i-1] < k) return 0;
    }
    return 1;
}

int main(void) {
    scanf("%d%d%d", &a, &b, &k);
    primes[0] = primes[1] = 1;
    int start = 0;
    for(i = 2; i <= b; i++) {
        c[i] = start;
        if(primes[i] == 0) {
            start += 1;
            c[i] += 1;
            if(i >= sqrt(b)) continue;
            for(j = i * i; j <= b; j += i) {
                primes[j] = 1;
            }
        }
    }
    if(c[b]-c[a-1] < k) {
        puts("-1");
    } else if(k == 0) {
        puts("1");
    } else {
        int low = 1, high = b - a + 1, mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(func(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(func(mid) == 0) mid += 1;
        printf("%d\n", mid);
    }
    return 0;
}


