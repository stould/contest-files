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

int T;
string S;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S;

        vector<int> cnt(26, 0);
        
        for (int i = 0; i < (int) S.size(); i++) {
            cnt[S[i] - 'a'] += 1;
        }

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++) {
            chmin(ans, cnt[i]);
        }
        
        cout << "Case " << t << ": " << ans << "\n";
    }
    return 0;
}
