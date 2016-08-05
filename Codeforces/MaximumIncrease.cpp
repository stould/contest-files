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

int N;

int main(void) {
    cin >> N;

    int ans = 1, now = 0, last = 0;
    int curr = 1;
    
    for (int i = 0; i < N; i++) {
        cin >> now;

        if (i > 0) {
            if (now > last) {
                curr += 1;
            } else {
                curr = 1;
            }
            ans = max(ans, curr);
        }

        last = now;
    }

    cout << ans << endl;
    return 0;
}
