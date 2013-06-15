#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second - a.first) > (b.second - b.first);
}

int n, mem[1000010], ct, ok;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n) == 1) {
        vector<pair<int, int> > p(n);
        memset(mem, 0, sizeof(mem));
        int mx = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
            if(p[i].second > mx) mx = p[i].second;
        }

    }
    return 0;
}
