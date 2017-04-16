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

int A, B;

bool func(int x) {
    vector<int> cnt(10, 0);
    int seen = 0;

    while (x > 0) {
        if (cnt[x % 10] == 0) {
            seen += 1;
        }        
                
        cnt[x % 10] += 1;
        x /= 10;
    }
    
    return seen == 1;
}

int main(void) {
    cin >> A >> B;

    int ans = 0;

    for (int i = A; i <= B; i++) {
        if (func(i)) ans += 1;
    }
    
    cout << ans << "\n";
    
    return 0;
}
