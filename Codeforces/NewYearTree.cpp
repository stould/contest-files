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

int Q;

struct node {
    int v;

};

node* root;

int main(void) {
    cin >> Q;

    int cr;


    int best = 2;
    int v = 4;

    for (int i = 0; i < Q; i++) {
        cin >> cr;

        h[v + 1] = h[cr] + 1;
        h[v + 2] = h[cr] + 1;

        if (best < h[v + 1]) {
            best = h[v + 1];
        }

        v += 2;

        cout << best << "\n";
    }

    return 0;
}
