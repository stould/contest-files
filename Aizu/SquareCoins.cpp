#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int dp[350];

void mount() {
    int i, j;
    dp[0] = 1;
    for(i = 1; i < 18; i++) {
        for(j = i * i; j < 301; j++) {
            dp[j] += dp[j - i * i];
        }
    }
}

int main(void) {
    mount();
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        printf("%d\n", dp[n]);
    }
    return 0;
}
