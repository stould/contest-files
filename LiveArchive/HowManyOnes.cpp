#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

Int func(Int x) {
    Int ans = 0LL;
    Int bits = 1LL;
    Int range = 2LL;

    int i;
    Int len = (Int) floor(log10(x) / log10(2)) + 1;

    for (i = 0; i < len; i++) {
        if (x >= range) {
            if (x % range == 0) {
                ans += (Int) (x / range) * bits;
            } else {
                Int md = x % range + 1;
                Int div = floor(x / range);

                ans += div * bits + max(0LL, md - range / 2LL);
            }
        } else {
                Int c_range = range - (range - x) + 1;
                ans += max(0LL, c_range - range / 2LL);
        }

        bits *= 2LL;
        range *= 2LL;
    }

    return ans;
}

Int A, B;

int main(void) {
    int test = 1;
    while (cin >> A >> B && !(A == 0 && B == 0)) {
        cout << "Case " << test++ << ": " << func(B) - func(A - 1) << "\n";
    }
    return 0;
}
