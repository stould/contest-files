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

const Int MOD = 1000000007LL;

string S;
int seen[30];
Int fat[1005];

Int pow(Int a, Int b) {
Int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
Int modInverse(Int a) {
    return pow(a, MOD-2);
}


int main(void) {
	fat[0] = 1LL;

	for (int i = 1; i <= 1000; i++) {
		fat[i] = (((fat[i - 1] * i) % MOD) + MOD) % MOD;
	}
	
	while (cin >> S) {
		memset(seen, 0, sizeof(seen));

		for (int i = 0; i < (int) S.size(); i++) {
			seen[S[i] - 'A'] += 1;
		}

		Int ans = fat[(int) S.size()];
		
		//cout << S << " " << ans << endl;
		for (int i = 0; i < 26; i++) {
			if (seen[i] > 1) {
				ans *= modInverse(fat[seen[i]]);
				ans = ((ans % MOD) + MOD) % MOD;
			}
		}
		ans = ((ans % MOD) + MOD) % MOD;

		cout << ans << endl;
	}
	return 0;
}
