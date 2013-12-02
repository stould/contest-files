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

const int MAXN = 100009;

int N;
int A[MAXN];
int dp[MAXN];
int mark[MAXN];

vector<int> primes;

void build(void) {
    int i;
    int j;

    for (i = 0; i < MAXN; i++) {
        dp[i] = 0;
        mark[i] = 1;
    }

    mark[0] = mark[1] = 0;

    for (i = 2; i <= sqrt(MAXN); i++) if (mark[i]) {
        for (j = i * i; j < MAXN; j += i) {
            mark[j] = 0;
        }
    }

    for (i = 0; i < MAXN; i++) if (mark[i]) {
        primes.push_back(i);
    }
}

int main(void) {
    N = in();

    int i;
    int j;
    int ans = 0;

    build();

    for (i = 0; i < N; i++) {
        A[i] = in();
        int bf = A[i];

        vector<int> factor;

        for (j = 0; bf != 1; j++) {
            if (bf % primes[j] == 0) {
                factor.push_back(primes[j]);                
            }
            for ( ; bf % primes[j] == 0; ) {                
                bf /= primes[j];
            }
        }

        int best = 0;

        for (j = 0; j < (int) factor.size(); j++) {
            chmax(best, dp[factor[j]]); 
        }

        for (j = 0; j < (int) factor.size(); j++) {
            chmax(dp[factor[j]], best + 1);                        
            chmax(ans, dp[factor[j]]);
        }
    }

    //for (i = 0; i < N; i++) chmax(ans, dp[A[i]]);

    printf("%d\n", N == 1 ? 1 : ans);

    return 0;
}
