int n, a[MAXN];

void downheap(int v) {
    int w = 2*v+1;
    while (w < n) {
        if(w + 1 < n) {
            if (a[w+1]>a[w]) w++;
        }
        if(a[v] >= a[w]) return;
        swap(a[v], a[w]);
        v = w;
        w = 2*v+1;
    }
}

void buildheap() {
    for (int v = n/2-1; v >= 0; v--) {
        downheap(v);
    }
}

void heapsort() {
    buildheap();
    while (n > 1) {
        n--;
        swap(a[0], a[n]);
        downheap(0);
    }
}
