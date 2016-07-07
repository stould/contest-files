#include <bits/stdc++.h>

using namespace std;

int A, B, C;

int main() {
    while (cin >> A >> B >> C) {
        int N = A * B;
        int M = C - B;

        int gc = __gcd(N, M);

        N /= gc;
        M /= gc;

        cout << N << "/" << M << "\n";    
    }
    return 0;
}
