int get(int pos) {
    int ans = 0;

    while (pos > 0) {
        ans = max(ans, tree[pos]);
        pos -= pos & -pos;
    }

    return ans;
}

void update(int pos, int new_value) {
    while (pos < MAXN) {
        tree[pos] = max(tree[pos], new_value);
        pos += pos & -pos;
    }
}

int ans = 1;

for (int i = 0; i < N; i++) {
    int now = get(P[i] - 1);
    update(P[i].second, now + 1);
    ans = max(ans, now + 1);
 }

