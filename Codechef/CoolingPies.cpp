#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j, t, n, w[40], l[40], u[40];

int main(void) {
    cin >> t;
    while(t--) {
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> w[i]; u[i] = 0;
        }
        for(i = 0; i < n; i++) {
            cin >> l[i];
        }
        sort(w, w + n);
        sort(l, l + n);

        int poss = n;
        j = n - 1;
        for(i = n - 1; i >= 0; i--) {
            if(w[i] <= l[j]) {
                j -= 1;
            } else {
                poss -= 1;
            }
        }
        cout << poss << endl;
    }
    return 0;
}
