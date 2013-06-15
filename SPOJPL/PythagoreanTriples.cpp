#include <iostream>

using namespace std;

int n, a, b, roots[310];

int main(void) {
    cin >> n;

    for(int i = 1; i <= 300; i++) {
        roots[i - 1] = i*i;
    }

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        a = a * a;
        b = b * b;

        bool got = false; int ans = 0;

        for(int j = 0; j < 300; j++) {
            if(a + b == roots[j]) {
                got = true; ans = j + 1; break;
            }
        }
        if(got) {
            cout << "YES " << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
