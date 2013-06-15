#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void) {
    int k, v[12];

    scanf("%d", &k);
    for(int i = 0; i < 12; i++) scanf("%d", &v[i]);

    if(k == 0) { printf("%d\n", 0); return 0; }

    sort(v, v + 12);
    reverse(v, v + 12);

    int ct = 0, ind = 0;

    for(int i = 0; i < 12; i++) {
        ct += v[i];
        ind += 1;
        if(ct >= k) break;
    }
    if(ct < k) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", ind);
    }
    return 0;
}
