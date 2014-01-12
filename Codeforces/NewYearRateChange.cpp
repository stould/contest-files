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

const int MAXN = 300005;

int N;
int X[MAXN];
int B[MAXN];

pair<int, int> pb[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i];

        pb[i].first = X[i];
        pb[i].second = i;
    }

    int now = 0;

    sort(pb, pb + N);

    for (int i = 0; i < N; i++) {
        pb[i].first = max(pb[i].first, now + 1);
        now = pb[i].first;
        B[pb[i].second] = pb[i].first;
    }

    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << "\n";

    return 0;
}
