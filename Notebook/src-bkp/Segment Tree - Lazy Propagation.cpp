void goDown(int node, int l, int r) {    
    if (lazy[node]) {
        tree[node] += lazy[node];
        
        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        } 
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = A[l];
    } else {
        int m = (l + r) / 2;
        
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);
        
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

Int query(int node, int l, int r, int bl, int br) {
    goDown(node, l, r);
    if (l >= bl && r <= br) {
        return tree[node];
    } else if (l > br || r < bl) { 
        return -INF;
    } else {
        int m = (l + r) / 2;
        
        Int a = query(2 * node, l, m, bl, br);
        Int b = query(2 * node + 1, m + 1, r, bl, br);
        
        return max(a, b);
    }
}

void update(int node, int l, int r, int bl, int br, Int value) {    
    goDown(node, l, r);
    if (l > r) {
        return;
    } else if (l > br || r < bl) {
        return;
    } else if (l >= bl && r <= br) {
        lazy[node] = value;    
        goDown(node, l, r);
    } else {
        int m = (l + r) / 2;       
        
        update(2 * node, l, m, bl, br, value);
        update(2 * node + 1, m + 1, r, bl, br, value);
        
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }    
}
