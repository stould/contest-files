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

const int MAXN = 51;

int N, M, K;
int R[MAXN], C[MAXN];
Int bin[MAXN][MAXN];

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    
	if(n % 2 == 0) return false;

    int m = (int) sqrt(n);
	
    for (int i = 3; i <= m; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}


int main(void) {
	bin[0][0] = 1LL;
	
	for(int n = 1; n < MAXN; n++) {
		bin[n][0] = 1LL;
		bin[n][n] = 1LL;

		for (int k = 1; k < n; k++) {
			bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
		}
	}
	
	for ( ; cin >> N >> M >> K && !(N == 0 && M == 0 && K == 0); ) {
		memset(R, 0, sizeof(R));
		memset(C, 0, sizeof(C));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int t = !isPrime(i * M + j);
				R[i] += t;
				C[j] += t;
			}
		}

		Int ans = 0LL;

		for (int i = 0; i < N; i++) {
			ans += bin[R[i]][K];
		}

		for (int j = 0; j < M; j++) {
			ans += bin[C[j]][K];
		}

		if (K == 1) {
			ans /= 2;
		}
		
		cout << ans << "\n";
	}
    return 0;
}
