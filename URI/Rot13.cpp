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

string A;

int main(void) {
    //freopen("i.in", "r", stdin);
    int i;
    for ( ; getline(cin, A); ) {
        for (i = 0; i < (int) A.size(); i++) {
            if (A[i] >= 'a' && A[i] <= 'z') {
                putchar('a' + ((A[i] - 'a' + 13) % 26));
            } else if (A[i] >= 'A' && A[i] <= 'Z') {
                putchar('A' + ((A[i] - 'A' + 13) % 26));
            } else {
                putchar(A[i]);
            }
        }
        cout << "\n";
    }

    return 0;
}
