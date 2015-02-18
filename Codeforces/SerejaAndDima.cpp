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

int N;
list<int> ls;

int main(void) {
    freopen("i.in", "r", stdin);
    N = in();

    for (int i = 0; i < N; i++) {
        int bf;
        bf = in();
        ls.push_back(bf);
        cout << bf << " ";
    }

    int ans[2];

    ans[0] = ans[1] = 0;

    int pivot = 0;

    for ( ; !ls.empty(); ) {
        int l = ls.back();
        int r = ls.front();

        //cout << l << " " << r << "\n";

        if (l > r) {
            ans[pivot] += l;
            ls.pop_back();
        } else {
            ans[pivot] += r;
            ls.pop_front();
        }
        pivot = (pivot + 1) % 2;
    }

    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}
