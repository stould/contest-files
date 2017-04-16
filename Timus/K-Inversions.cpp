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

const int MAXN = 20005;
const int MAXK = 11;
const Int MOD = 1000000000LL;

int N, K;
int P[MAXN];
Int tree[MAXK][4 * MAXN];

Int query(int tr, int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return 0LL;
    } else if (l >= bl && r <= br) {
        return tree[tr][node];
    } else {
        int m = (l + r) / 2;

        Int a = query(tr, 2 * node, l, m, bl, br);
        Int b = query(tr, 2 * node + 1, m + 1, r, bl, br);

        return ((a % MOD) + (b % MOD)) % MOD;
    }
}

void update(int tr, int node, int l, int r, int pos, Int add) {
    if (l == r) {
        tree[tr][node] += add;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            update(tr, 2 * node, l, m, pos, add);
        } else {
            update(tr, 2 * node + 1, m + 1, r, pos, add);
        }

        tree[tr][node] = ((tree[tr][2 * node] % MOD) + (tree[tr][2 * node + 1] % MOD)) % MOD;
        tree[tr][node] %= MOD;
    }
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            Int bef = query(j - 1, 1, 0, MAXN - 1, P[i] + 1, MAXN - 1);
            update(j, 1, 0, MAXN - 1, P[i], bef);
        }
        update(1, 1, 0, MAXN - 1, P[i], 1);
    }
    
    Int ans = query(K, 1, 0, MAXN - 1, 0, MAXN - 1);

    cout << ans << "\n";
    
    return 0;
}
