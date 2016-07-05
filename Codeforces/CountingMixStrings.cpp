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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 10004;
const Int MOD = 1000000007LL;

int T;
long long pow(Int a, Int b, Int MOD) {
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
long long InverseEuler(Int n, Int MOD) {
    return pow(n,MOD-2,MOD);
}

long long C(Int n, Int r, Int MOD)
{
    vector<long long> f(n + 1,1);
    for (Int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;
		
		cout << C(A + B, (int) floor((A + B) / 2.0), MOD) << "\n";
	}

	return 0;
}
