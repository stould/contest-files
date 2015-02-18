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

const int MAXN = 310;

int N;
int X[MAXN];

int main(void) {
    N = in();

    for (int i = 0; i < N; i++) {
        X[i] = in();
    }

    string ans = "";

    int pivot = 0;
    int l = 1;
    int sum = accumulate(X, X + N, 0);

    for ( ; sum > 0; ) {
        if (X[pivot] > 0) {
            X[pivot] -= 1;
            sum -= 1;
            ans += "P";
        }

        if (l) {
            pivot += 1;

            if (pivot == N) {
                pivot -= 2;
                l = 0;
                ans += "L";
            } else {
                ans += "R";
            }
        } else {
            pivot -= 1;
            if (pivot == -1) {
                pivot += 2;
                l = 1;
                ans += "R";
            } else {
                ans += "L";
            }
        }
    }

    if (ans[ans.size() - 1] != 'P') ans = ans.substr(0, ans.size() - 1);

    cout << ans << "\n";

    return 0;
}
