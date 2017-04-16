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

const int MAXN = 500005;
const int INF = INT_MAX / 5;

int N, M, D;
Int L;

//sum/active
pair<Int, Int> tree[4 * MAXN];
Int lazy[4 * MAXN];
Int X[MAXN], Z[MAXN];

int queryR(Int pos) {
    int l = 0, h = N - 1;
    int ans = -1;
 
    while (l <= h) {
        int m = (l + h) / 2;

        if (X[m] <= pos) {
            ans = m;

            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    return ans;
}

int queryL(Int pos) {
    int l = 0, h = N - 1;
    int ans = -1;
 
    while (l <= h) {
        int m = (l + h) / 2;

        if (X[m] >= pos) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
}

void goDown(int node, int l, int r) {
    /*
    if (lazy[node] != 0) {
        tree[node].second += lazy[node];        
        //cout << "in " << node << " " << l << " " << r << " " << tree[node].second << " => " << lazy[node] << endl;
        if (tree[node].second > 0) {
            tree[node].first = (r - l + 1);
        } else {
            tree[node].second = 0;
            tree[node].first = 0;
        }

        if (l != r) {
            lazy[2 * node + 0] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        } 
    }

    lazy[node] = 0;
    */
}

pair<Int, Int> query(int node, int l, int r, int bl, int br) {
    goDown(node, l, r);
    if (l >= bl && r <= br) {
        return tree[node];
    } else if (l > br || r < bl) { 
        return make_pair(0, 0);
    } else {
        int m = (l + r) / 2;
        
        pair<Int, Int> a = query(2 * node, l, m, bl, br);
        pair<Int, Int> b = query(2 * node + 1, m + 1, r, bl, br);
        
        return make_pair(a.first + b.first, a.second + b.second);
    }
}

void update(int node, int l, int r, int bl, int br, Int value) {    
    goDown(node, l, r);
    if (l > r) {
        return;
    } else if (l > br || r < bl) {
        return;
    } else if (l == r) {
        tree[node].first += value;
        //cout << "in " << l << " " << r << " " << value << " " << tree[node] << endl;
    } else {
        int m = (l + r) / 2;       
        
        update(2 * node, l, m, bl, br, value);
        update(2 * node + 1, m + 1, r, bl, br, value);
        
        tree[node].first = tree[2 * node].first + tree[2 * node + 1].first;
        //tree[node].second = min(tree[2 * node].second, tree[2 * node + 1].second);
    }    
}

int main(void) {
    cin >> N >> M >> D >> L;

    X[0] = 0;
    
    for (int i = 1; i < N; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> Z[i];

        int pl = queryL(Z[i] - L);
        int pr = queryR(Z[i] + L);

        if (pl != -1 && pr != -1 && pl <= pr) {
            update(1, 0, N - 1, pl, pr, 1);
        }
    }
    
    cout << query(1, 0, N - 1, 0, N - 1).first << endl;

    for (int i = 0; i < D; i++) {
        Int A, B;
        cin >> A >> B;

        //cout << A << " " << B << endl;
        int pl = queryL(A - L);
        int pr = queryR(A + L);
        
        
        if (pl != -1 && pr != -1 && pl <= pr) {
            //cout << "dec = " << A << " = " << pl << " " << pr << " " << endl;
            update(1, 0, N - 1, pl, pr, -1);
        }
        
        pl = queryL(B - L);
        pr = queryR(B + L);        

        //cout << pl << " " << pr << endl;

        if (pl != -1 && pr != -1 && pl <= pr) {
            //cout << "inc = " << B << " = " << pl << " " << pr << " " << endl;
            update(1, 0, N - 1, pl, pr, 1);            
        }

        pair<Int, Int> ans = query(1, 0, N - 1, 0, N - 1);
        
        cout << ans.first << endl;
    }
    
    return 0;
}
