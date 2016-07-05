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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N;
int P[MAXN];
pair<int, int> tree[4 * MAXN];
Int dp[MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = make_pair(P[l], l);        
    } else {
        int m = (l + r) / 2;

        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

pair<int, int> query(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return make_pair(0, 0);
    } else if (l >= bl && r <= br) {
        return tree[node];
    } else {
        int m = (l + r) / 2;
       
        pair<int, int> a = query(2 * node, l, m, bl, br);
        pair<int, int> b = query(2 * node + 1, m + 1, r, bl, br);
       
        return max(a, b);
    }
}

    
int main(void) {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> P[i];
        P[i] -= 1;
    }

    build(1, 0, N - 1);
    
    Int ans = 0;

    dp[N - 1] = 0;
    
    for (int i = N - 2; i >= 0; i--) {
        int pos = query(1, 0, N - 1, i, P[i]).second;
        dp[i] = dp[pos] - (P[i] - pos) + (N - i);
        ans += dp[i];
    }

    cout << ans << "\n";
    return 0;
}
