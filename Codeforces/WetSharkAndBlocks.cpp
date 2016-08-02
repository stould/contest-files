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

Int N, B, K, X, D;

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b) {
    vector<vector<Int> > res(X, vector<Int>(X));
	
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < X; j++) {
            int sum = 0;
            for (int k = 0; k < X; k++) {
                sum += ((a[i][k] % MOD)* (b[k][j] % MOD)) % MOD;
                sum = ((sum % MOD) + MOD) % MOD;
            }
            res[i][j] = ((sum % MOD) + MOD) % MOD;
        }
    }
    return res;
}

vector<vector<Int> > binPow(vector<vector<Int> > a, Int n) {
    if (n == 1) {
        return a;
    } else if ((n & 1) != 0) {
        return multiply(a, binPow(a, n - 1));
    } else {
        vector<vector<Int> > b = binPow(a, n / 2);
        return multiply(b, b);
    }
}


int main(void) {
    cin >> N >> B >> K >> X;

    vector<vector<Int> > V(X, vector<Int>(X, 0));
	
    for (int i = 0; i < N; i++) {
        cin >> D;
        for (int j = 0; j < X; j++) {
            V[j][(j * 10 + D) % X] += 1;
        }
    }

    vector<vector<Int> > ans = binPow(V, B);
	
    cout << ans[0][K] << "\n";
	
    return 0;
}
