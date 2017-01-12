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

const int MAXN = 10005;

int N, P;
int X[MAXN], Y[MAXN];
map<pair<int, int>, int> id;
double tree[4 * MAXN];

double query(int node, int l, int h, int bl, int br) {
    if (l >= bl && h <= br) {
        return tree[node];
    } else if (l > br or h < bl) {
        return -1.0;
    } else {
        int m = (l + h) / 2;

        double a = query(2 * node, l, m, bl, br);
        double b = query(2 * node + 1, m + 1, h, bl, br);

        return max(a, b);
    }
}

void update(int node, int l, int r, int pos, double val) {
    if (l == r) {
        tree[node] = val;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            update(2 * node, l, m, pos, val);
        } else {
            update(2 * node + 1, m + 1, r, pos, val);
        }

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

int main(void) {
    cin >> N >> P;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        id[make_pair(X[i], Y[i])] = i + 1;

        if (i > 0) {
            double ds = hypot(X[i] - X[i - 1], Y[i] - Y[i - 1]);

            update(1, 1, N, i, ds);
        }
    }

    for (int i = 0; i < P; i++) {
        int px, py;
        int qx, qy;
        
        cin >> px >> py >> qx >> qy;

        int ia = id[make_pair(px, py)];
        int ib = id[make_pair(qx, qy)];

        if (ib < ia) {
            swap(ia, ib);
        }

        double ans = query(1, 1, N, ia, ib - 1);

        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
