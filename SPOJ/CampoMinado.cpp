#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, n, mem[60], ans;

int main(void) {
    memset(mem, 0, sizeof(mem));
    scanf("%d", &n); for(i = 0; i < n; i++) scanf("%d", &mem[i]);
    for(i = 0; i < n; i++) {
        ans = 0;
        if(i - 1 >= 0 && mem[i - 1] == 1) ans++;
        if(mem[i] == 1) ans++;
        if(i + 1 < n && mem[i + 1] == 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
