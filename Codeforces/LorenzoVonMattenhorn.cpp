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
typedef unsigned long long uInt;
typedef unsigned uint;

int Q, T;
map<Int, Int> tree;

void update(Int a, Int b, Int cost) {
    while (a != b) {
        if (b < a) {
            swap(a, b);
        }
        tree[b] += cost;
        b /= 2LL;
    }
}

Int query(Int a, Int b) {
    Int ans = 0;

    while (a != b) {
        if (b < a) {
            swap(a, b);
        }
        ans += tree[b];
        b /= 2LL;
    }
    return ans;
}

int main(void) {
    cin >> Q;

    while (Q--) {
        cin >> T;

        if (T == 1) {
            Int A, B, C;
            
            cin >> A >> B >> C;

            update(A, B, C);
        } else {
            Int A, B;

            cin >> A >> B;

            cout << query(A, B) << "\n";
        }
    }
    return 0;
}
