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
int N;
string S;


int main(void) {
    cin >> T;

    int i;

    for ( ; T--; ) {
        cin >> S >> N;

        for (i = 0; i < (int) S.size(); i++) {
            cout << char('A' + ((((S[i] - 'A') - N) + 26) % 26));
        }
        cout << "\n";
    }

    return 0;
}
