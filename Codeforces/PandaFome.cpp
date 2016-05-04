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

const int MAXN = 1000010;

int N, Q;
int P[MAXN];
int L[4 * MAXN], R[4 * MAXN];
Int tree[4 * MAXN];
int id = 2;
int node_id[MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = P[l];
    } else {
        int m = (l + r) / 2;

        L[node] = id++;
        R[node] = id++;

        build(L[node], l, m);
        build(R[node], m + 1, r);

        tree[node] = tree[L[node]] + tree[R[node]];
    }
}

Int query(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return 0;
    } else if (l >= bl && r <= br) {
        return tree[node];
    } else {
        int m = (l + r) / 2;

        Int a = query(L[node], l, m, bl, br);
        Int b = query(R[node], m + 1, r, bl, br);

        return a + b;
    }
}

int update(int node, int l, int r, int pos, Int val) {
    int next = id++;
    L[next] = L[node];
    R[next] = R[node];

    tree[next] = tree[node];

    if (l == r) {
        tree[next] = val;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            L[next] = update(L[node], l, m, pos, val);
        } else {
            R[next] = update(R[node], m + 1, r, pos, val);
        }

        tree[next] = tree[L[next]] + tree[R[next]];
    }

    return next;
}


int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int cnt = 0;
    
    node_id[cnt++] = 1;

    build(node_id[0], 0, N - 1);
        
    cin >> Q;

    for ( ; Q--; ) {
        char T;
        
        cin >> T;
        
        if (T == 'Q') {
            int A, B, U;
            
            cin >> A >> B >> U;

            Int ans = query(node_id[U], 0, N - 1, A - 1, B - 1);

            cout << ans << "\n";
        } else {
            int A, V;
            
            cin >> A >> V;

            int rt = node_id[cnt - 1];
            
            node_id[cnt++] = update(rt, 0, N - 1, A - 1, V);
        }
    }
    
    return 0;
}
