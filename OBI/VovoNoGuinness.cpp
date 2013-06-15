#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

int i, j, n, m, t = 1;

int main(void) {
    while(1) {
        vector<int> appear(10001, 0);
        cin >> n >> m; if(!n && !m) break;

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                int tmp; cin >> tmp;
                 appear[tmp] += 1;
            }
        }

        cout << "Teste " << t++ << endl;

        int max = 0;
        for(i = 0; i <= 10000; i++) {
            if(appear[i] > max) {
                max = appear[i];
            }
        }
        for(i = 0; i <= 10000; i++) {
            if(appear[i] == max) {
                appear[i] = -1;
            }
        }
        max = 0;
        for(i = 0; i <= 10000; i++) {
            if(appear[i] > max) {
                max = appear[i];
            }
        }
        for(i = 0; i <= 10000; i++) {
            if(appear[i] == max) {
                cout << i << " ";
            }
        }
        cout << endl << endl;
    }
    return 0;
}
