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

const int MAXN = 200005;
const Int INF = 100010100010010LL;

int N;
Int A[MAXN], B[MAXN];
Int tree[4 * MAXN][2];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node][0] = A[l];
        tree[node][1] = B[l];
    } else {
        int m = (l + r) / 2;
        
        build(2 * node + 0, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node][0] = max(tree[2 * node][0], tree[2 * node + 1][0]);
        tree[node][1] = min(tree[2 * node][1], tree[2 * node + 1][1]);
    }
}

Int queryMax(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return -INF;
    } else if (l >= bl && r <= br) {
        return tree[node][0];
    } else {
        int m = (l + r) / 2;

        Int a = queryMax(2 * node, l, m, bl, br);
        Int b = queryMax(2 * node + 1, m + 1, r, bl, br);

        return max(a, b);
    }
}

Int queryMin(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return INF;
    } else if (l >= bl && r <= br) {
        return tree[node][1];
    } else {
        int m = (l + r) / 2;

        Int a = queryMin(2 * node, l, m, bl, br);
        Int b = queryMin(2 * node + 1, m + 1, r, bl, br);
        
        return min(a, b);
    }
}


int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    build(1, 0, N - 1);

    Int ans = 0;
    int l = 0, r = 0;

    Int mn = +INF;
    Int mx = -INF;
    
    while (r < N) {
        mx = max(mx, A[r]);
        mn = min(mn, B[r]);
        
        while (mx != mn && l < r) {
            l += 1;

            mx = queryMax(1, 0, N - 1, l, r);
            mn = queryMin(1, 0, N - 1, l, r);
            
            if (mx == mn) {
                break;
            }
        }
        
        if (mx == mn) {
            ans += max(1, (r - l));
            
            while (r < N) {         
                r += 1;
                if (r >= N) break;
                mx = max(mx, A[r]);
                mn = min(mn, B[r]);
                if (mx != mn) break;
                ans += (r - l);            
                //cout << ans << " " << l << " " << r << "\n";
            }
        }
        r += 1;
    }
    cout << ans << "\n";
    return 0;
}
