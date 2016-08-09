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
int A[5], B[5];

int main(void) {
    cin >> T;

    while (T--) {
        int sa = 0;
        int sb = 0;
        
        for (int i = 0; i < 3; i++) {
            cin >> A[i];
            sa += A[i];

            cout << A[i] << " ";
        }
        for (int i = 0; i < 3; i++) {
            cin >> B[i];
            sb += B[i];

            if (i > 0) {
                cout << " ";
            }
            cout << B[i];
        }

        cout << "\n";

        bool bc = sa > sb ? true : false;
        bool bm = false;

        if (A[0] > B[0] || (A[0] == B[0] && A[1] > B[1]) || (A[0] == B[0] && A[1] == B[1] && A[2] > B[2])) {
            bm = true;
        }

        if (bc && bm) {
            cout << "both\n";
        } else if (bc) {
            cout << "count\n";
        } else if (bm) {
            cout << "color\n";
        } else {
            cout << "none\n";
        }
        
    }
    return 0;
}
