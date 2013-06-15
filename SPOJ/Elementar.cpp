#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int i, j, k, t, n, v[100110];

int main(void) {
    scanf("%d", &t);
    while(t--) {
        int ct = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }
        int ans = 0;
        for(i = 1; i <= n; i++) {
            while(v[i] != i) {
                swap(v[v[i]], v[i]);
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
