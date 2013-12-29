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

vector<int> L;

void build(void) {
    int i;
    int cnt = 0;
    
    for (i = 0; cnt <= 1000; i++) {
        int x = i;
        int curr = 2;
        int dist = 0;

        while (x > 1) {
            bool ok = false;
            while (x % curr == 0) {
                x /= curr;
                ok = true;
            }
            if (ok) dist += 1;
            curr += 1;
        }
        if (dist >= 3) {
            cnt += 1;
            L.push_back(i);
        }
    }
}

int main(void) {
    build();
    
    T = in();

    for ( ; T--; ) {
        int x = in();
        printf("%d\n", L[x-1]);
    }

    return 0;
}
