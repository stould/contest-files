#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)

using namespace std;

int a, b, k, maze[6][6] = {0};

int rec()

int main(void) {
    scanf("%d", &k);
    REP(i, k) {
        scanf("%d%d", &a, &b);
        maze[a][b] = 1;
    }
    return 0;
}
