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

string S, P;
int L, R;

int main(void) {
    cin >> S >> P;
    bool br = false;

    string LL = "", RR = "";

    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == '|') {
            br = true;

            LL = S.substr(0, i);
            RR = S.substr(i + 1);
            continue;
        }
        if (!br) {
            L += 1;
        } else {
            R += 1;
        }
    }

    if (P.size() + min(L, R) >= max(L, R) && (L + R + P.size()) % 2 == 0) {
        int M = (L + R + P.size()) / 2;
        int pv = 0;

        for ( ; LL.size() < M; ) {
            LL += P[pv++];
        }
        for ( ; RR.size() < M; ) {
            RR += P[pv++];
        }
        cout << LL << "|" << RR << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
