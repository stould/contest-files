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

int A, B;
int Q;

vector<int> dv;

void gen(vector<int>& ans, vector<pair<int, int> >& v, int id, int x, int N) {
    if (id == N) {
        ans.push_back(x);
    } else {
        for (int i = 0; i <= v[id].second; i++) {
            gen(ans, v, id + 1, x, N);
            x *= v[id].first;
        }
    }
}

vector<int> func(int x) {
    vector<pair<int, int> > vp;

    int d = 1;

    for (int i = 2; i * i <= x; i += d, d = 2) {
        if (x % i == 0) {
            vp.push_back(make_pair(i, 0));

            for ( ; x % i == 0; ) {
                vp.back().second += 1;
                x /= i;
            }
        }
    }
    if (x != 1) {
        vp.push_back(make_pair(x, 1));
    }

    vector<int> ans;

    gen(ans, vp, 0, 1, (int) vp.size());

    return ans;
}

int main(void) {
    A = in();
    B = in();

    vector<int> d1 = func(A);
    vector<int> d2 = func(B);

    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());

    set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), inserter(dv, dv.begin()));

    Q = in();

    for ( ; Q--; ) {
        int lb = in();
        int ub = in();

        int best = INT_MIN;

        int l = 0;
        int h = (int) dv.size() - 1;

        for ( ; l <= h; ) {
            int m = (l + h) / 2;

            int curr = dv[m];

            if (curr >= lb && curr <= ub) {
                chmax(best, curr);
            }

            if (curr > ub) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (best == INT_MIN) {
            printf("-1\n");
        } else {
            printf("%d\n", best);
        }
    }

    return 0;
}
