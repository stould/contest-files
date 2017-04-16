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

const Int INF = 100000000000000010LL;
const int MAXN = 100005;
const Int MOD = 1000000007LL;
const int MATRIX_LEN = 2;

int N, M;
Int P[MAXN];
Int tree[4 * MAXN];
Int lazy[4 * MAXN];

void goDown(int node, int l, int r) {    
    if (lazy[node]) {
        tree[node] += lazy[node] * (Int) (r - l + 1);
        
        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
    }
    
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = P[l];
    } else {
        int m = (l + r) / 2;
        
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

Int query(int node, int l, int r, int bl, int br) {
    goDown(node, l, r);
    if (l >= bl && r <= br) {
        return tree[node];
    } else if (l > br || r < bl) { 
        return 0;
    } else {
        int m = (l + r) / 2;
        
        Int a = query(2 * node, l, m, bl, br);
        Int b = query(2 * node + 1, m + 1, r, bl, br);
        
        return a + b;
    }
}

void update(int node, int l, int r, int bl, int br, Int value) {    
    goDown(node, l, r);
    if (l > r) {
        return;
    } else if (l > br || r < bl) {
        return;
    } else if (l >= bl && r <= br) {
        lazy[node] += value;    
        goDown(node, l, r);
    } else {
        int m = (l + r) / 2;
        
        update(2 * node, l, m, bl, br, value);
        update(2 * node + 1, m + 1, r, bl, br, value);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }    
}

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b, int n) {
    vector<vector<Int> > res(n, vector<Int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (a[i][k] * b[k][j]) % MOD;
                
                sum %= MOD;
                sum += MOD;
                sum %= MOD;
            }
            res[i][j] = sum % MOD;
        }
    }
    return res;
}

vector<vector<Int> > binPow(vector<vector<Int> > a, Int n) {
    if (n == 1) {
        return a;
    } else if ((n & 1) != 0) {
        return multiply(a, binPow(a, n - 1), MATRIX_LEN);
    } else {
        vector<vector<Int> > b = binPow(a, n / 2);
        return multiply(b, b, MATRIX_LEN);
    }
}



Int getFib(Int s) {
    if (s <= 2) return 1LL;

    Int ans = 0LL;
    
    vector<vector<Int> > base = {{0, 1},
                                 {1, 1}};

    vector<vector<Int> > res = binPow(base, s - 2);

    ans = res[0][1] + res[1][1];

    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    
    return ans;
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    build(1, 0, N - 1);

    for (int i = 0; i < M; i++) {
        int kind;
        cin >> kind;

        if (kind == 1) {
            int l, r;
            Int x;

            cin >> l >> r >> x;

            update(1, 0, N - 1, l - 1, r - 1, x);
        } else {
            int l, r;

            cin >> l >> r;

            Int sum = query(1, 0, N - 1, l - 1, r - 1);
            cout << sum << endl;
            //cout << getFib(sum) << endl;
        }
    }
    return 0;
}
