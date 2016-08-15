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

int T;
Int R, S, Q;

Int eval(Int a, Int b) {
    return a * R + b * S;
}

int main(void) {
    cin >> T;

    while (T--) {
        cin >> R >> S >> Q;

        Int A = 1;
        Int B = 10;
        
        while (1) {
            Int now = eval(A, B);

            cout << A << " " << B << " " << now << endl;
            
            if (now == Q) {
                break;
            } else if (now < Q) {
                A += 1;
            } else {
                if (B - 1 >= 1) {
                    B -= 1;
                } else {
                    A -= 1;
                }
            }
        }
        
        cout << A << " " << B << endl;
    }
    return 0;
}
