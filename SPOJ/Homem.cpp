#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, x, n, m, a, b, ca, cb, cc, state[100010];
char c;

struct data {
    int a, b, c, now;
    data(){ a = 0; b = 0; c = 0; now = 0;}
};

data t[200000];

data combine (data l, data r) {
    data res;
    if(l.a == 0) res.a += 1;
    if(l.b == 1) res.b += 1;
    if(l.c == 2) res.c += 1;
    if(r.a == 0) res.a += 1;
    if(r.b == 1) res.b += 1;
    if(r.c == 2) res.c += 1;
    return res;
}

data make_data(int val) {
    data res;
    res.a = res.b = res.c = 0;
    res.now = val;
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = make_data(a[tl]);
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = combine (t[v*2], t[v*2+1]);
    }
}

data query(int v, int tl, int tr, int l, int r) {
    if(l == tl && tr == r) {
   //     cout << t[v].a << " " << t[v].b << " " << t[v].c << "\n";
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(r <= tm) {
        return query(v*2, tl, tm, l, r);
    }
    if(l > tm) {
        return query(v*2+1, tm+1, tr, l, r);
    }
    return combine(query(v*2, tl, tm, l, tm), query(v*2+1, tm+1, tr, tm+1, r));
}

void update(int v, int tl, int tr, int l, int r) {
    if(l > r) {
        return;
    }
    if(l == tl && tr == r) {
        if(t[v].now == 0) {
            t[v].now = 1;
        } else if(t[v].b == 1) {
            t[v].now = 2;
        } else if(t[v].now == 2) {
            t[v].now = 0;
        }
    } else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm , l, min (r, tm));
        update(v * 2 + 1, tm + 1, tr, max (l, tm + 1), r);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    ios::sync_with_stdio(false);
    for(; cin >> n >> m; ) {
        memset(state, 0, sizeof(state));
        build(state, 1, 1, n+1);
        for(x = 0; x < m; x++) {
            cin >> c >> a >> b;
            if(c == 'C') {
                data d = query(1, 1, n+1, a, b);
                printf("%d %d %d\n", d.a, d.b, d.c);
            } else {
                update(1, 1, n+1, a, b);
            }
        }
        printf("\n");
    }
    return 0;
}
