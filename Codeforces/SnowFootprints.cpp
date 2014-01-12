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

int N;
string S;

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> N >> S;

    int s = 0, t = 0;

    for (int i = 1; i < N && s == 0; i++) {
        if (S[i] == 'R') {
            s = i;
            t = i + 1;
        } else if (S[i] == 'L') {
            s = i;
            t = i - 1;
        }
    }

    cout << (s + 1) << " " << (t + 1) << "\n";

    return 0;
}
