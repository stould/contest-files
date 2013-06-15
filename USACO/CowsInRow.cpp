#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, j, n, cows[1010], record[1000001];

int main(void) {
    freopen("cowrow.in", "r", stdin);
    freopen("cowrow.out", "w", stdout);

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &cows[i]);
        record[cows[i]] += 1;
    }
    int mx = 0, index = 0;
    for(i = 0; i < 1000001; i++) {
        if(record[i] > mx) {
            mx = record[i];
            index = i;
        }
    }
    int ma = 1 << 15, mb = -1;
    for(i = 0; i < n; i++) {
        if(cows[i]  == index) {
            ma = min(ma, i);
            mb = max(mb, i);
        }
    }
    memset(record, 0, sizeof(record));
    for(i = ma; i <= mb; i++) {
        record[cows[i]] += 1;
    }
    int second = 0, sindex = 0;
    for(i = 0; i < 1000001; i++) {
        if(record[i] > second && i != index) {
            second = record[i];
            sindex = i;
        }
    }
    int mxcontiguous = 0;
    for(i = ma; i <= mb; i++) {
        if(cows[i] == index) {
            j = i;
            int ct = 0;
            while(j <= mb && (cows[j] == index || cows[j] == sindex)) {
                if(cows[j] == index) {
                    ct += 1;
                }
                j += 1;
            }
            mxcontiguous = max(mxcontiguous, ct);
            i = j;
        }
    }
    cout << mxcontiguous << endl;
    return 0;
}
