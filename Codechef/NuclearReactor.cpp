#include <iostream>

using namespace std;

int a, n, k, v[1010];

int main(void) {
    ios::sync_with_stdio(false);
    cin >> a >> n >> k;
    for(int i = 0; i < k; i++) v[i] = 0;

    for(int i = 0; i < k; i++) {
       v[i] = a % (n + 1);
       a /= (n + 1);
    }
    for(int i = 0; i < k; i++) {
        if(i == k - 1) {
            cout << v[i] << "\n";
        } else {
            cout << v[i] << " ";
        }
    }
    return 0;
}
