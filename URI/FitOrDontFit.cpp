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

int T;
string A, B;

int main(void) {
    cin >> T;

    for ( ; T--; ) {
        cin >> A >> B;

        if (B.size() > A.size()) {
            cout << "nao encaixa\n";
        } else {
            int N = (int) B.size();

            if (A.substr(A.size() - N, N) == B) {
                cout << "encaixa\n";
            } else {
                cout << "nao encaixa\n";
            }
        }
    }

    return 0;
}
