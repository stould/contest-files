#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int i, a, b, ans = 0, m[4];

bool func(int i, int a, int b, int c, int d) {
    return i == (((i % a) % b) % c) % d;
}

int main() {
    cin >> m[0] >> m[1] >> m[2] >> m[3] >> a >> b;

   	for(i=a;i<=b;i++) {
        sort(m, m + 4);
        do {
            if(func(i, m[0], m[1], m[2], m[3])) {
                ans++;
                break;
            }
        } while(next_permutation(m, m + 4));
    }
    cout << ans << endl;
}
