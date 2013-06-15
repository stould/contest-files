#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, m, s = 0;

int main(void) {
    cin >> n >> m;
    cin.ignore();
    vector<string> mz(n);
    vector<bool> sign(n, false);

    for(int i = 0; i < n; i++) {
        getline(cin, mz[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mark = mz[i][j] - '0', best = -1;

            for(int k = 0; k < n; k++) {
                if(mz[k][j] - '0' > best) best = mz[k][j] - '0';
            }
            if(mark == best) sign[i] = true;
        }
    }
    for(int i = 0; i < n; i++) if(sign[i]) s++;
    printf("%d\n", s);
    return 0;
}
