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
typedef unsigned uint;
 
const int MAXN = 1005;
 
int N, M, P, Q;
int tree[4 * MAXN][4 * MAXN];
 
void update_y(int node_x, int node_y, int xl, int xr, int yl, int yr, int pos_x, int pos_y, int value) {
    if (yl > yr || yl > pos_y || yr < pos_y) {
        return;
    }
    if (yl == yr) {
        if (xr == xl) {
            tree[node_x][node_y] += value;
        } else {
            tree[node_x][node_y] = tree[2 * node_x][node_y] + tree[2 * node_x + 1][node_y];
        }
    } else {
        int m = (yl + yr) / 2;
 
        if (pos_y <= m) {
            update_y(node_x, 2 * node_y, xl, xr, yl, m, pos_x, pos_y, value);
        } else {
            update_y(node_x, 2 * node_y + 1, xl, xr, m + 1, yr, pos_x, pos_y, value);
        }
 
        tree[node_x][node_y] = tree[node_x][2 * node_y] + tree[node_x][2 * node_y + 1];
    }
}
 
void update_x(int node_x, int node_y, int xl, int xr, int yl, int yr, int pos_x, int pos_y, int value) {
    if (xl > xr || xl > pos_x || xr < pos_x) {
        return;
    }
    if (xl != xr) {
        int m = (xl + xr) / 2;
 
        if (pos_x <= m) {
            update_x(2 * node_x, node_y, xl, m, yl, yr, pos_x, pos_y, value);
        } else {
            update_x(2 * node_x + 1, node_y, m + 1, xr, yl, yr, pos_x, pos_y, value);
        }
    }
 
    update_y(node_x, node_y, xl, xr, yl, yr, pos_x, pos_y, value);
}
 
void update(int node_x, int node_y, int xl, int xr, int yl, int yr, int pos_x, int pos_y, int value) {
    update_x(node_x, node_y, xl, xr, yl, yr, pos_x, pos_y, value);
}
 
int query_y(int node_x, int node_y, int xl, int xr, int yl, int yr, int qxl, int qxr, int qyl, int qyr) {
    if (yl > yr || yr < qyl || yl > qyr) {
        return 0;
    } else if (yl >= qyl && yr <= qyr) {
        return tree[node_x][node_y];
    } else {
        int m = (yl + yr) / 2;
 
        int q1 = query_y(node_x, 2 * node_y, xl, xr, yl, m, qxl, qxr, qyl, qyr);
        int q2 = query_y(node_x, 2 * node_y + 1, xl, xr, m + 1, yr, qxl, qxr, qyl, qyr);
 
        return q1 + q2;
    }
}
 
int query_x(int node_x, int node_y, int xl, int xr, int yl, int yr, int qxl, int qxr, int qyl, int qyr) {
    if (xl > xr || xl > qxr || xr < qxl) {
        return 0;
    } else if (xl >= qxl && xr <= qxr) {
        return query_y(node_x, node_y, xl, xr, yl, yr, qxl, qxr, qyl, qyr);
    } else {
        int m = (xl + xr) / 2;
 
        int q1 = query_x(2 * node_x, node_y, xl, m, yl, yr, qxl, qxr, qyl, qyr);
        int q2 = query_x(2 * node_x + 1, node_y, m + 1, xr, yl, yr, qxl, qxr, qyl, qyr);
 
        return q1 + q2;
    }  
}
 
int query(int node_x, int node_y, int xl, int xr, int yl, int yr, int qxl, int qxr, int qyl, int qyr) {
    query_x(node_x, node_y, xl, xr, yl, yr, qxl, qxr, qyl, qyr);
}
 
int main(void) {
    for ( ; scanf("%d%d%d", &N, &M, &P) && N + M + P != 0; ) {
        scanf("%d", &Q);
 
        int Xl, Xr, Yl, Yr, V;
        char C;
         
        for ( ; Q--; ) {
            scanf(" %c", &C);      
 
            if (C == 'A') {
                scanf("%d%d%d", &V, &Xl, &Yl);
                update(1, 1, 0, N - 1, 0, M - 1, Xl, Yl, V);
            } else {
                scanf("%d%d%d%d", &Xl, &Yl, &Xr, &Yr);
                 
                if (Xr < Xl) {
                    swap(Xl, Xr);
                }
                if (Yr < Yl) {
                    swap(Yl, Yr);
                }
                int ans = P * query(1, 1, 0, N - 1, 0, M - 1, Xl, Xr, Yl, Yr);
 
                printf("%d\n", ans);
            }
        }
        memset(tree, 0, sizeof(tree));
    }
    return 0;
}
