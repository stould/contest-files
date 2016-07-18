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

int T, N;
string S;
int cnt[30];

int main(void) {
    cin >> T;

    while (T--) {
        cin >> S;

        N = (int) S.size();

        memset(cnt, 0, sizeof(cnt));

        string ans = "";

        for (int i = 0; i < N; i++) {
            cnt[S[i] - 'a'] += 1;
            ans += "$";
        }
        
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd += 1;
            }
        }
        if (odd > 1) {
            cout << "impossible\n";
        } else {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % 2 == 1) {
                    ans[N / 2] = char('a' + i);
                    cnt[i] -= 1;
                    break;
                }
            }
            int pos = 0;

            for (int i = 0; i < 26; i++) {
                while (cnt[i] > 0) {
                    ans[pos] = ans[N - pos - 1] = char('a' + i);
                    cnt[i] -= 2;
                    pos += 1;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
