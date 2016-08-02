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

int N, M;
int cnt[MAXN];
bool canRed[MAXN];

int main(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cnt[i] = 1;
    }

    canRed[1] = 1;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cnt[a] -= 1;
        cnt[b] += 1;

        if (canRed[a]) {
            canRed[b] = 1;
        }
        if (cnt[a] == 0) {
            canRed[a] = 0;
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        ans += canRed[i];
    }

    cout << ans << endl;
    return 0;
}
