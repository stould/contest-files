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

int dist(char a, char b) {
    int pa = a - 'a';
    int pb = b - 'a';

    int l = 0;
    int r = 0;

    if (a < b) {
        l = a + (26 - b);
        r = b - a;
    } else {
        r = b + (26 - a);
        l = a - b;
    }

    return min(l, r);
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S;
        N = (int) S.size();

        bool ok = true;
        
        for (int i = 0; i < N - 1; i++) {
            //cout << dist(S[i], S[i + 1]) << "\n";
            if (dist(S[i], S[i + 1]) != 1) {
                ok = false;
            }
        }

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
