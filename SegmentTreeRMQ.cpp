pair<int, int> tree[MAXN*4];

void build(int a[], int v, int tl, int tr){
    if (tl == tr) {
        tree[v].first = a[tl];
        tree[v].second = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build (a, 2 * v, tl, tm);
        build (a, 2 * v + 1, tm + 1, tr);
        tree[v].first = min (tree[2 * v].first, tree[2 * v + 1].first);
        tree[v].second = max (tree[2 * v].second, tree[2 * v + 1].second);
    }
}

int rmq_min(int v, int tl, int tr, int l, int r){
    if (l > r) {
        return INF;
    }
    if (tl == l && tr == r) {
        return tree[v].first;
    } else {
        int tm = (tl + tr) >> 1;
        return min(rmq_min(2 * v, tl, tm, l, min(tm, r)),rmq_min(2 * v + 1,tm + 1, tr, max(l ,tm + 1), r));
    }
}

int rmq_max(int v, int tl, int tr, int l, int r){
    if (l > r) {
        return -INF;
    }
    if (tl == l && tr == r) {
        return tree[v].second;
    } else {
        int tm = (tl + tr) >> 1;
        return max(rmq_max(2 * v, tl, tm, l, min(tm, r)), rmq_max(2 * v + 1,tm + 1, tr, max(l ,tm + 1), r));
    }
}

