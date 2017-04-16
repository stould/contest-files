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

const int MAXN = 1000005;

int N;
int p[MAXN];

void build() {
    for (int i = 2; i < MAXN; i++) {
        if (!p[i]) {
            for (Int j = i; j < MAXN; j += i) {
                p[j] = i;
            }
        }
    }
}

int func(int x) {
    int ans = 0;

    if (x == 1) return 1;

    set<int> cnt;
    while (p[x] != 0 && x > 1) {
        cnt.insert(p[x]);
        x /= p[x];
    }
    ans += (int) cnt.size();
    
    return ans;
}

int main(void) {
    build();
    while (cin >> N && N != 0) {
        int ans = func(N);
        cout << N << " : " << ans << endl;
    }
    return 0;
}
