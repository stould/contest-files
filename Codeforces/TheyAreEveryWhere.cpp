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

using namespace std;


typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int N;
string S;


int main(void) {
    cin >> N >> S;

    set<char> st;
    map<char, int> cnt;
    
    for (int i = 0; i < N; i++) {
        st.insert(S[i]);
    }

    int ans = N;
    int l = 0, r = 0, add = 0;

    while (r < N) {
        if (cnt[S[r]] == 0) {
            add += 1;
        }
        cnt[S[r]] += 1;

        if (add == (int) st.size()) {
            ans = min(ans, r - l + 1);
        }

        while (add == (int) st.size()) {
            cnt[S[l]] -= 1;
            if (cnt[S[l]] == 0) {
                add -= 1;
            }
            l++;
            if (add == (int) st.size()) {
                ans = min(ans, r - l + 1);
            }
        }
        r += 1;
    }
    cout << ans << "\n";
    return 0;
}
