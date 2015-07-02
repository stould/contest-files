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

const Int MOD = 1000000009LL;
const int MAXN = 200005;

int N;
Int fat[MAXN];
Int catalan[MAXN];

Int modPow(Int a, Int n, Int mod) {
	Int res = 1LL;
	while (n) {
		if (n&1) {
			res=(res*a)%mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

Int getCatalan(int n){
	for (int i=0; i <= n; i++){
        if (i==0 || i==1){
            catalan[i] = 1;
        }else{
            Int sum =0;
            Int l, r;
            for (int k=1;k<=i;k++){
                l = catalan[k-1] % MOD;
                r = catalan[i-k] % MOD;
                sum = (sum + (l * r) % MOD) % MOD;
            }
            catalan[i] = sum;
        }
    }
	return catalan[n];
}

int main(void) {
	cin >> N;

	cout << getCatalan(N) << "\n";
	
	return 0;
}
