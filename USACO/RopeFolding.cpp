#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, l, ct, all;

int main(void) {
    freopen("11.in", "r", stdin);
    freopen("o.o", "w", stdout);
    scanf("%d%d", &n, &l);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int fold = 0;
    if(n == 2) {
        puts("1"); return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        double mid = (double) v[i] + ((v[i + 1] - v[i]) / 2.0);
        ct = 0, all = 0;
        for(int j = i + 1, k = i; j < n && k >= 0; j++, k--) {
            if(mid - v[k] == v[j] - mid) {
                ct += 1;
            }
            all += 1;
        }
        if(ct == all) {
            fold += 1;
        }
        if(i != 0) {
            ct = 0, all = 0;
            for(int k = i - 1, j = i + 1; k >= 0 && j < n; k--, j++) {
                if(v[i] - v[k] == v[j] - v[i]) ct += 1;
                all += 1;
            }
            if(all == ct) fold += 1;
        }
    }
    printf("%d\n", fold);
}
