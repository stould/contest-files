#include <iostream>

using namespace std;

int i, init, can, n, m, pos[110];

int main(void) {
    cin >> n >> m;
    for(i = 0; i <= 100; i++) pos[i] = 0;
    for(i = 0; i < m; i++) {
        cin >> init >> can;
        pos[init] = 1;
        int tmp = init;
        while(tmp + can <= n) {
            pos[tmp + can] = 1;
            tmp = tmp + can;
        }
        tmp = init;
        while(tmp - can >= 1) {
            pos[tmp - can] = 1;
            tmp = tmp - can;
        }

    }
    for(i = 1; i <= n; i++) {
        cout << pos[i] << endl;
    }
    return 0;
}
