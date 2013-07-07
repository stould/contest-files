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

const int MAXN = 100007;
int B, P, L, N, I, V;
int f[MAXN];
Int power[MAXN];
char opt;

Int modpow(int a, int n) {
	Int ans = 1LL;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * (Int) a) % P;
        }
        a = (a * 1LL * a) % P;
        n >>= 1;
    }
    return (Int) (ans % P);
}


Int func(int l, int h) {
    Int ans = 0LL;

    int k;

    for (k = 0; k <= h - l; k++) {
        //printf ("%lld * %d\n", modpow(B, k), f[h-k]);
        ans = (Int) (((ans % P) + ((power[k] * (f[h-k])) % P)) % P);
    }

    return (Int) (ans % P);
}

template<typename T = int>
struct FenwickTree {
    int N;
    T *values;

    FenwickTree(int N) {
        this->N = N;
        values = new T[N+5];

        for(int i = 1; i <= N; i++) values[i] = 0;
    }

    void increase(int index, T add) {
        while(index <= N) {
            values[index] += add;
            index += (index & -index);
        }
    }

    void update(int index, T new_value) {
        increase(index, new_value - readSingle(index));
    }

    T read(int index) {
        T sum = 0;

        while(index > 0) {
            sum += values[index];
            index -= (index & -index);
        }

        return sum;
    }

    T readSingle(int index){
        T sum = values[index];
        if(index > 0) {
            int z = index - (index & -index);
            index--;
            while(index != z) {
                sum -= values[index];
                index -= (index & -index);
            }
        }
        return sum;
    }

    T read(int low, int high) {
        return read(high) - read(low - 1);
    }
};


int main(void) {
    freopen("i.in", "r", stdin);
//    freopen("o.ot", "w", stdout);

    int i;

    power[0] = 1LL;

    for ( ; scanf("%d%d%d%d", &B, &P, &L, &N) == 4 && (B + P + L + N != 0); ) {
        for (i = 0; i <= L; i++) {
            f[i] = 0;
            if (i > 0) power[i] = (power[i - 1] * B) % P;
        }
        for (i = 0; i < N; i++) {
            scanf(" %c%d%d", &opt, &I, &V);

            if (opt == 'E') {
                f[I] = V;
            } else {
                printf("%lld\n", func(I, V));
            }
        }
        printf("-\n");
    }
    return 0;
}
