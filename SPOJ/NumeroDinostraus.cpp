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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1000007;
int N, test = 1, buff[MAXN];
vector<int> primes;

void build(void) {
    int i, j;

    memset(buff, 0, sizeof(buff));

    buff[0] = buff[1] = 1;

    for (i = 2; i <= (int) sqrt(MAXN); i++) {
        if (!buff[i]) {
            for (j = i * i; j < MAXN; j += i) {
                buff[j] = 1;
            }
        }
    }

    for (i = 2; i < MAXN; i++) if (!buff[i]) primes.push_back(i);
}

vector<pair<int, int> > func(int x) {
    int i;
    vector<pair<int, int> > ans;

    for (i = 0; i < primes.size(); i++) {
        if (x <= 1) break;
        pair<int, int> curr = make_pair(primes[i], 0);
        while (x % primes[i] == 0) {
            curr.second += 1;
            x /= primes[i];
        }
        if (curr.second != 0) ans.push_back(curr);
    }

    return ans;
}

int main(void) {
    build();
    int i;
    for ( ; scanf("%d", &N) == 1; ) {
        vector<pair<int, int> > factors = func(N);

        int pos = 1, div = 0;

        for (i = 0; i < factors.size(); i++) {
            pos *= factors[i].second + 1;
            if (N % factors[i].first == 0) div += 1;
        }

        pos -= 1;

        printf("Instancia %d\n", test++);

        if (pos >= 8 || div >= 4) {
            printf("sim\n\n");
        } else {
            printf("nao\n\n");
        }
    }
    return 0;
}
