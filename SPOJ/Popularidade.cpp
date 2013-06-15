#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int i, j, n, aux, votes[110];

int main(void) {
    while(scanf("%d", &n) && n > 0) {
        memset(votes, 0, sizeof(votes));
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &aux);
                if(aux == 1) {
                    votes[j] += 1;
                }
            }
        }
        int mx = 0;
        for(i = 0; i < n; i++) {
            mx = max(mx, votes[i]);
        }
        printf("%d\n", mx);
    }
    return 0;
}

