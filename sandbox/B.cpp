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

const int MAXN = 100005;

int N, Q;
Int P[MAXN];

int main(void) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        Int B;
        cin >> B;
        
        int l = 0, h = N - 1;
        int ans = 0;

        while (l <= h) {
            int m = (l + h) / 2;

            if (P[m] <= B) {
                ans = m + 1;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
