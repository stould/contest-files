#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int i, j, k, p, r, n, state, tmp, s[110], t = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(~scanf("%d%d", &p, &r)) {
        if(!p && !r) break;
        for(i = 0; i < p; i++) {
            scanf("%d", &s[i]);
        }
        for(i = 0; i < r; i++) {
           scanf("%d%d", &n, &state);
            for(j = 0, k = 0; j < n; j++, k++) {
                scanf("%d", &tmp);
                if(s[k]) {
                    if(tmp != state) {
                        s[k] = 0;
                    }
                } else {
                    for(; k < p; k++) {
                        if(s[k]) {
                            if(tmp != state) {
                                s[k] = 0;
                            }
                            break;
                        }
                    }
                }
            }
        }
        cout << "Teste " << (t++) << endl;
        for(i = 0; i < p; i++) {
            if(s[i] != 0) {
                cout << s[i] << endl;
                break;
            }
        }
    }
    return 0;
}

