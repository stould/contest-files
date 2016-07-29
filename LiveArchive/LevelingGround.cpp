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
const Int INF = 100101;

struct field {
    int hill;
    int flat;
    int lowest;
    int sumHeight;
    int dots;
    int len;

    field() {
        hill = 0;
        flat = 0;
        lowest = INF;
        sumHeight = 0;
        dots = 0;
        len = 0;
    }
};


int T, N, M;
string S;
int level[MAXN];
field tree[4 * MAXN];

field construct(int id) {
    field ans;
    
    if (S[id] == '_') {
        ans.flat += 1;
    } else {
        ans.hill += 1;
    }

    ans.len = 1;
    
    ans.lowest = level[id];
    ans.sumHeight = level[id];
    
    return ans;
}

field combine(field a, field b) {
    field ans;

    ans.hill = a.hill + b.hill;
    ans.flat = a.flat + b.flat;
    ans.lowest = min(a.lowest, b.lowest);    
    ans.sumHeight = a.sumHeight + b.sumHeight;
    ans.len = a.len + b.len;
    
    ans.dots = (ans.sumHeight - ans.len * ans.lowest - ans.hill - ans.flat);
    
    return ans;
}


void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = construct(l);
    } else {
        int m = (l + r) / 2;
        
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

field query(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return field();
    } else if (l >= bl && r <= br) {
        return tree[node];
    } else {
        int m = (l + r) / 2;
        
        field a = query(2 * node, l, m, bl, br);
        field b = query(2 * node + 1, m + 1, r, bl, br);
        
        return combine(a, b);
    }
}


int type(char v) {
    if (v == '/') {
        return 1;
    } else if (v == '\\') {
        return 1;
    } else if (v == '.') {
        return 2;
    }
    return 0;
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> S;

        int lv = 0;
        int base = 0;

        for (int i = 0; i < N; i++) {
            if (S[i] == '/') {
                lv += 1;
            } else if (S[i] == '\\') {
                lv -= 1;
            }
            level[i] = lv;
            base = min(base, level[i]);
        }

        base = abs(base);

        for (int i = 0; i < N; i++) {
            level[i] += base;
        }

        build(1, 0, N - 1);
        
        double ans = INF;
        
        for (int i = M; i < N; i++) {
            field now = query(1, 0, N - 1, i - M, i);
            
            double cnt = now.sumHeight - (now.lowest - 1) * 2 - now.hill - now.flat;
            
            cnt += now.hill * 0.5;
            
            //cout << now.sumHeight - (now.lowest - 1) * 2 << endl;
            cout << S.substr(i - M, M) << " " << now.hill << " " << now.flat << endl;
            chmin(ans, cnt);
        }

        cout << fixed << setprecision(2) << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
