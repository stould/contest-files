#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll i, index, n, v[101010];

int main(void) {
    scanf("%I64d", &n);
    for(i = 0; i < n; i++) {
        scanf("%I64d", &v[i]);
        if(v[i] < mx) {
            mx = v[i];
            index = i + 1;
        }
    }
    int count = 0;
    for(i = 0; i < n; i++) {
        if(v[i] == mx) count++;
    }
    if(count == 1) {
        printf("%I64d\n", index);
    } else {
        puts("Still Rozdil");
    }
    return 0;
}
