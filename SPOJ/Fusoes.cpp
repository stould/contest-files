#include <iostream>
#include <stdio.h>

using namespace std;

struct UF {
    int *id;
    int *sz;
    int count;

    UF(int N) {
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    int find(int p) {
        while (p != id[p])
            p = id[p];
        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void _union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        if   (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else                 { id[j] = i; sz[i] += sz[j]; }
        count--;
    }
};

int n, k, a, b;
char c;

int main(void) {
    cin >> n >> k;
    UF un(n + 1);

    for(int i = 0; i < k; i++) {
        cin >> c >> a >> b;
        if(c == 'F') {
            un._union(a, b);
        } else {
            if(un.connected(a, b)) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}

