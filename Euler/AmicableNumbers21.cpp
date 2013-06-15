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
#include <numeric>
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

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 10000;
int sum[N+10];

vector<int> primes;

void build(void) {
    vector<int> memo(N+5, 1); memo[0] = memo[1] = 0;

    for(int i = 2; i <= (int) sqrt(N); i++) if(memo[i] == 1) {
        for(int j = i * i; j <= N; j += i) {
            memo[j] = 0;
        }
    }

    for(int i = 2; i <= N; i++) if(memo[i]) primes.push_back(i);
}

void mount(int x) {
    vector<int> fact;
    int base = 0, other = x, mult = 1;
    while(x > 1) {
        int cnt = 0;
        while(base < primes.size() && x % primes[base] == 0) {
            x /= primes[base];
            cnt += 1;
        }
        if(cnt) {
            mult *= (((int) pow(primes[base], cnt + 1) - 1) / (int) (primes[base] - 1));
        }
        base += 1;
    }
    sum[other] = mult - other;
}

int main(void) {
    build();
    for(int i = 1; i <= N; i++) mount(i);
    set<int> amicables;
    set<int>::iterator it;

    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(sum[i] == j && sum[j] == i) {
                amicables.insert(i);
                amicables.insert(j);
            }
        }
    }
    printf("%d\n", accumulate(amicables.begin(), amicables.end(), 0));
    return 0;
}
