#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j, n, k, s[100], b[100][100];

int main(void) {
    while(1) {
        scanf("%d%d", &n, &k);
        if(!n && !k) break;

        for(i = 0; i < k; i++) scanf("%d", &s[i]);

        for(i = 0; i < n; i++) {
            for(j = 0; j < k; j++) {
                scanf("%d", &b[i][j]);
                s[j] -= b[i][j];
            }
        }
        bool ok = true;
        for(i = 0; i < k; i++) if(s[i] < 0) ok = false;
        if(ok) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
