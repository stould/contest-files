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

string S;

int main(void) {
    cin >> S;

    string ans = "";
    string A = "", D = "";
    int B = 0;

    bool inA = true;
    bool inD = false;
    
    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == '.') {
            inA = false;
            inD = true;
            continue;
        } else if (S[i] == 'e') {
            inD = false;
            continue;
        }
        if (inA) {
            A += S[i];
        } else if (inD) {
            D += S[i];
        } else {
            B = B * 10 + (S[i] - '0');
        }
    }

    ans = A;

    if (B >= D.size()) {
        ans += D;

        for (int i = (int) D.size(); i < B; i++) {
            ans += "0";
        }
    } else {
        ans += D.substr(0, B);

        for (int i = B; i < D.size(); i++) {
            if (D[i] != '0') {
                ans += ".";
                ans += D.substr(B, D.size() - B);
                break;
            }
        }
    }

    bool has_non_zero = false;

    for (int i = 0; i < (int) ans.size(); i++) {
        if (ans[i] != '0') {
            has_non_zero = true;
        }
    }
    
    if (!has_non_zero) {
        ans = "0";
    } else {
        int base = 0;

        while (base + 1 < ans.size() && ans[base] == '0' && ans[base + 1] != '.') {
            base += 1;
        }

        ans = ans.substr(base, ans.size() - base);

        if (ans.empty()) ans = "0";
    }
    
    cout << ans << "\n";
    return 0;
}
