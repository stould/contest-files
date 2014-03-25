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
const int INF = INT_MAX / 3;

int N, K;
int X[MAXN];

int main(void) {
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    
    sort(X, X + N);
    
    int ans = INF;
    
    for (int i = 0; i <= K; i++) {
        ans = min(ans, X[i + (N - K) - 1] - X[i]);
    }
    
    cout << ans << "\n";
    return 0;
}
