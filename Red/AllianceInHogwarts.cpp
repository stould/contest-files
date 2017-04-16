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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int N, Q;

struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);

        if(i == j) return;

        if (i > j) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};


int main(void) {
    while (cin >> N >> Q) {
        int C, A, B;

        UnionFind fr(N + 1);
        UnionFind en(N + 1);
        
        for (int i = 0; i < Q; i++) {
            cin >> C >> A >> B;
            
            if (C == 1) {
                if (en.find(A, B) || fr.find(en.root(A), en.root(B)) || en.find(fr.root(A), fr.root(A))) {
                    cout << C << " " << A << " " << B << " ";
                    cout << "-1\n";
                } else {
                    fr.unite(A, B);
                }
            } else if (C == 2) {
                if (en.find(A, fr.root(B)) || en.find(B, fr.root(A))) {
                    cout << C << " " << A << " " << B << " ";
                    cout << "-1\n";
                } else {
                    en.unite(A, B);
                }
            } else if (C == 3) {
                if (fr.find(A, B)) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            } else if (C == 4) {
                if (fr.find(en.root(A), en.root(B))) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
        }
    }
    return 0;
}
