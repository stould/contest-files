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

    string ans = "";

    for (int i = 0; i < N; i++) {
        if (i > 0) ans += "that ";
        if (i % 2 == 0) {
            ans += "I hate ";
        } else {
            ans += "I love ";
        }
    }
    
    ans += "it";
    
    cout << ans << "\n";
    return 0;    
}
