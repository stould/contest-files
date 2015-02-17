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

string S;
string goal = "niet";

int rem[4] = {3, 1, 3, 1};
int sum[512];

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> S;

    for (int i = 0; i < (int) S.size(); i++) {
        sum[S[i]] += 1;
    }

    int ans = INT_MAX / 3;

    for (int i = 0; i < 4; i++) {
        int now;
        if (i == 0) {
            now = (sum[goal[i]] / rem[i]) + (sum[goal[i]] % rem[i]) ? 1 : 0;
        } else {
            now = sum[goal[i]] / rem[i];
        }
        cout << goal[i] << " " << now << "\n";
        ans = min(ans, now);
    }

    cout << ans << "\n";
    return 0;
}
