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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

Int N, M;
Int R[MAXN], C[MAXN];

int main(void) {
    cin >> N >> M;

    Int ans = 0;
    Int AR = 0;
    Int AC = 0;
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        if (!R[A]) {
            ans += (N - AC);
            AR += 1;
        }
        if (!C[B]) {
            ans += (N - AR);
            AC += 1;
        }
        R[A] = C[B] = 1;

        cout << N * N - ans<< "\n";
    }
    
    return 0;
}
