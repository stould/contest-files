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

int N;
int P[MAXN];

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    int ans = 0;
    
    for (int i = 1; i <= N; i++) {
        if (P[P[i]] == i) {
            ans += 1;
        }
    }
    
    cout << ans / 2 << endl;
    return 0;
}
