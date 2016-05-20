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

const int MAXN = 1000005;

int N, Q;
int P[MAXN];
int tree[8 * MAXN];
int L[8 * MAXN];
int R[8 * MAXN];
int rt[MAXN];
int id = 1;

int update(int node, int l, int r, int pos) {
    int next = id++;
    L[next] = L[node];
    R[next] = R[node];
    tree[next] = tree[node];

    if (l == r) {
        tree[next] = 1;
    } else {
        int m = (l + r) / 2;

        if (pos < m) {
            L[next] = update(L[node], l, m, pos);
        } else {
            R[next] = update(R[node], m + 1, r, pos);                   
        }
        tree[next] = tree[L[next]] + tree[R[next]];
    }
    
    return next;
}

int query(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return 0;
    } else if (l >= bl && r <= br) {
        return tree[node];
    } else {
        int m = (l + r) / 2;

        int a = query(L[node], l, m, bl, br);
        int b = query(R[node], m + 1, r, bl, br);

        return a + b;
    }
}

int main(void) {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &P[i]);
        rt[i] = update(rt[i - 1], 0, MAXN, P[i]);
    }

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);

        int a = query(rt[r], 0, MAXN, 0, MAXN);
        int b = query(rt[l - 1], 0, MAXN, 0, MAXN);
        int ans = b;
        
        printf("%d %d\n", a, b);
    }
    return 0;
}
