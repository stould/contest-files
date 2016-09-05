#include <bits/stdc++.h>

using namespace std;

long long A, B;

int main() {
    while (cin >> A >> B) {
        if (B > A) swap(A, B);

        long long ans = (2 + (A - 1)) * B;
        
        cout << ans << endl;
    }
    return 0;
}
