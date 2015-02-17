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

const int MAXN = 10000007;

int N;
int X[MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    sort(X, X + N);

    int best = X[0];

    for (int i = 1; i < N; i++) {
        chmax(best, X[i] - X[0]);
    }

    cout << best << "\n";

    return 0;
}
