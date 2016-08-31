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

const int MAXN = 100005;

int N;
int P[MAXN];
int tree[4 * MAXN];

int query(int node, int l, int r, int bl, int br) {
    if ((l > br) or (r < bl)) {
        return 0;
    } else if (l >= bl && r <= br) {
        return tree[node];
    } else {
        int m = (l + r) / 2;

        int a = query(2 * node, l, m, bl, br);
        int b = query(2 * node + 1, m + 1, r, bl, br);

        return a + b;
    }
}

void update(int node, int l, int r, int pos, int value) {
    if (l == r) {
        tree[node] = 1;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            update(2 * node, l, m, pos, value);
        } else {
            update(2 * node + 1, m + 1, r, pos, value);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}


int main(void) {
    cin >> N;

    vector<pair<int, int> > pp;
    
    for (int i = 1; i <= N; i++) {
        cin >> P[i];

        int p = min(i, P[i]);
        int q = max(i, P[i]);

        if (abs(p - q) == 1 or abs(p - q) == N - 1) {
           continue;
        }

        pp.push_back(make_pair(p, q));
    }

    sort(pp.begin(), pp.end());

    Int ans = 0LL;

    for (int i = 0; i < (int) pp.size(); i++) {
        ans += query(1, 1, N, pp[i].first + 1, pp[i].second - 1);
        
        update(1, 1, N, max(pp[i].first, pp[i].second), 1);
    }
    
    cout << ans << endl;
    
    return 0;
}
