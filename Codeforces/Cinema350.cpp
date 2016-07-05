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

const int MAXN = 200020;

int N, M;
Int A[MAXN];
Int B[MAXN];
Int C[MAXN];

Int P[MAXN];
Int Q[MAXN];

int main(void) {
    cin >> N;

    map<Int, Int> cnt;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];

        cnt[A[i]] += 1;
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> B[i];

        P[i] += cnt[B[i]];
    }
    for (int i = 0; i < M; i++) {
        cin >> C[i];

        Q[i] += cnt[C[i]];
    }

    int ans = 1;

    Int a = -1;
    Int b = -1;

    for (int i = 0; i < M; i++) {
        if (P[i] > a || (P[i] == a && Q[i] > b)) {
            a = P[i];
            b = Q[i];
            ans = i + 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
