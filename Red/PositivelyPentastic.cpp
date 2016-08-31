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
const int N = 5;
int P[N];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        while (1) {
            int v = INT_MAX;
            int p = 0;

            for (int i = 0; i < N; i++) {
                if (P[i] < v) {
                    v = P[i];
                    p = i;
                }
            }

            if (v >= 0) break;

            P[p] = -P[p];
            
            P[(p + 1) % N] = P[(p + 1) % N] - P[p];
            P[(p - 1 + N) % N] = P[(p - 1 + N) % N] - P[p];
        }

        cout << "Pentagon #" << t << ":\n";

        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << P[i];
        }
        cout << "\n";
    }
    return 0;
}
