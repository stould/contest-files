#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

typedef long long ll;

int test, n, m, w, x, y, z;

template<typename T> T min(T a, T b) {
    return a < b ? a : b;
}
template<typename T> T max(T a, T b) {
    return a > b ? a : b;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

struct segment {
    int first, last, diffGcd;
    int lazysum;
};

void addSegment(segment &s1, segment &s2, segment &s3) {
    s3.first = s1.first;
    s3.last = s2.last;
    s3.diffGcd = abs(gcd(s1.diffGcd, gcd(s2.first - s1.last, s2.diffGcd)));
}
void getSegment(int a, segment &s) {
    s.first = s.last = a;
    s.lazysum = 0;
    s.diffGcd = 0;
}
struct segtree {
    int base;
    vector<segment> tree;
    vector<int> A;
    segtree() {}

    segtree(vector<int> _A) {
        A = _A;
        int N = A.size();
        base = 1;
        while(base < N) base *= 2;
        tree.resize(2*base);
        makeSegment(1);
    }
    void makeSegment(int ind) {
        if(ind >= base)
            getSegment(A[ind-base], tree[ind]);
        else {
            int twice = ind << 1;
            makeSegment(twice);
            makeSegment(twice+1);
            addSegment(tree[twice], tree[twice+1], tree[ind]);
            tree[ind].lazysum = 0;
        }
    }
    int lo, hi;
    void update(int ind, int beg, int end, int d) {
        if( end < lo || beg > hi) return;
        if( lo <= beg && end <= hi) {
            tree[ind].first += d;
            tree[ind].last += d;
            tree[ind].lazysum += d;
            return;
        }
        int twice = ind << 1, mid = (beg + end) >> 1;

        update(twice, beg, mid, d);
        update(twice+1, mid+1, end,d);

        addSegment(tree[twice], tree[twice+1], tree[ind]);
        tree[ind].first += tree[ind].lazysum;
        tree[ind].last += tree[ind].lazysum;
    }

    int query(int ind, int beg, int end, int lazysum) {
        if(end < lo || beg > hi) return 0;
        if(lo <= beg && end <= hi)
            return gcd(tree[ind].first + lazysum, tree[ind].diffGcd);

        lazysum += tree[ind].lazysum;
        int twice = ind << 1, mid = (beg + end) >> 1;

        return gcd( query(twice, beg, mid, lazysum), query(twice+1, mid+1, end, lazysum));
    }

    void update(int u, int v, int d) {
        lo = u, hi = v;
        update(1, 0, base -1, d);
    }

    int query(int u, int v) {
        lo = u, hi = v;
        return query(1, 0, base-1, 0);
    }
};

int main(void) {
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%d", &n, &m);
        segtree s(vector<int>());
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d%d", &w, &x, &y, &z);
            if(w == 1) {
                s.update(x, y, z);
            } else {
            }
        }
        printf("%d\n", s.query(0, n - 1));
    }
    return 0;
}

