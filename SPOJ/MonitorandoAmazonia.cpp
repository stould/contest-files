#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n;
pair<int, int> vp[1010];

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        for(int i = 0; i < n; i++) scanf("%d%d", &vp[i].first, vp[i].second);
    }
    return 0;
}
