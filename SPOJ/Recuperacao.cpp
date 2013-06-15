#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j, n, mem[110], sum[110], test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(~scanf("%d", &n)) {
        mem[0] = sum[0] = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d", &mem[i]);
            sum[i] = sum[i - 1] + mem[i - 1];
        }
        int index = 0;
        bool found = false;
        for(i = 1; i <= n; i++) {
            if(!found && sum[i] == mem[i]) {
                index = sum[i]; found = true;
            }
        }
        printf("Instancia %d\n", (test++));
        if(!found) {
            printf("nao achei\n\n");
        } else {
            printf("%d\n\n", index);
        }
    }
    return 0;
}


