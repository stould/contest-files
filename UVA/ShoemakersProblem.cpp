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

int T;
int N;
int A[1010];
int B[1010];

struct Entry {
    int a, b, id;

    Entry(){}

    Entry(int a, int b, int id): a(a), b(b), id(id) {

    }
};

bool cmp(Entry i, Entry j) {
    int x = i.a * j.b;
    int y = j.a * i.b;

    if (x != y) {
        return x < y;
    } else {
        return i.id < j.id;
    }
}

int main(void) {
    T = in();

    int i;
    int x;

    for (x = 1; x <= T; x++) {
        N = in();

        vector<Entry> v(N);

        for (i = 0; i < N; i++) {
            v[i].a = in();
            v[i].b = in();
            v[i].id = i + 1;
        }

        sort(v.begin(), v.end(), cmp);

        for (i = 0; i < N; i++) {
            printf("%d", v[i].id);
            if (i != N - 1) printf(" ");
        }
        printf("\n");
        if (x != T) printf("\n");
    }
    return 0;
}
