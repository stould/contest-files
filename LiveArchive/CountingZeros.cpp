#include <bits/stdc++.h>

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

const int MAXN = 10010006;

Int N;
Int ans;
vector<Int> primes;
int sieve[MAXN];

void build() {
	for (int i = 2; i < MAXN; i++) {
		if (!sieve[i]) {
			primes.push_back(i);

			for (Int j = (Int) i * (Int) i; j < MAXN; j += i) {
				sieve[j] = true;
			}
		}
	}
}

int getZero(Int x) {
	Int base = x;
	Int rep = 0, p = N;

	while (x <= p && p % x == 0) {
		rep += 1;
		x *= base;
	}
	
	return rep;
}

void gen(vector<pair<Int, int> >& v, int id, Int x) {
    if (id == (int) v.size()) {
		if (x != 1) {
			ans += getZero(x);
		}
    } else {
        for (int i = 0; i <= v[id].second; i++) {
            gen(v, id + 1, x);
            x *= (Int) v[id].first;
        }
    }
}

void func(Int x) {
    vector<pair<Int, int> > vp;

    for (int i = 0; i < (int) primes.size(); i++) {
		if (i == 1) continue;

        if (x % primes[i] == 0) {

            vp.push_back(make_pair(primes[i], 0));
			
            for ( ; x % primes[i] == 0; ) {
                vp.back().second += 1;
                x /= primes[i];
            }
        }
    }
	
    if (x != 1) {
        vp.push_back(make_pair(x, 1));
    }
	
    gen(vp, 0, 1LL);
}

int main(void) {
	build();

	while (scanf("%lld", &N) == 1 && N != 0) {
		if (N != 1) {
			ans = 0;
			func(N);
		}		
		printf("%lld %lld\n", N, ans);
	}
	return 0;
}
