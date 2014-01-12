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

int K, X, N, M;

string fb[60];

int main(void) {
    cin >> K;
    //cin >> K >> X >> N >> M;

    fb[0] = "AC";
    fb[1] = "AAD";

    for (int i = 2; i <= K; i++) {
        fb[i] = fb[i - 2] + fb[i - 1];
    }

    cout << fb[K - 1] << "\n";

    return 0;
}
