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

const int MAXN = 100005;
const Int MOD = 1000000007LL;

int N;
Int F[MAXN], D[MAXN];
bool P[MAXN];

vector<int> primes;

Int modPow(Int a, Int n) {
	Int res = 1LL;
	
	while (n > 0) {
		if (n & 1) {
			res = (res*a) % MOD;
		}
		a = (a * 1LL * a) % MOD;
		n >>= 1;
	}
	return res;
}

int div(Int x, unordered_map<int, int>& powers) {
    Int base = 0, other = x, mult = 1;

    while(x > 1LL) {
        Int cnt = 0;
		
        while(base < primes.size() && x % primes[base] == 0) {
            x /= primes[base];
            cnt += 1;
        }
        if(cnt) {
			powers[primes[base]] += cnt;
        }
        base += 1;
    }
	
	for (auto& i: powers) {
		Int m = (((Int) modPow(i.first, i.second + 1) - 1) / (Int) (i.first - 1));
		mult = ((mult % MOD) * (m % MOD)) % MOD;
	}
    return (mult - F[other]) % MOD;
}

void build(void) {
	P[0] = P[1] = true;
	
	for (int i = 2; i <= 100000; i++) {
		if (!P[i]) {
			for (int j = i * i; j > 0 && j <= 100000; j += i) {
				P[j] = true;
			}
			primes.push_back(i);
		}
	}
	
	F[1] = D[1] = 1LL;	

	unordered_map<int, int> powers;
	
	for (int i = 2; i <= 10000; i++) {
		F[i] = (F[i - 1] * (Int) i) % MOD;		
		D[i] = div(i, powers) % MOD;
	}
}

int main(void) {
	build();
	for ( ; cin >> N; ) {
		cout << D[N] << " " << F[N] << "\n";
	}
    return 0;
}
