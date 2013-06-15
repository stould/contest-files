#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <string.h>

using namespace std;

int i, j, l, x, y, d, n, k;

map<pair<int, int>, int> m;
map<pair<int, int>, int>::iterator it;

int main(void) {
    cin >> n >> k;
    for(i = 0; i < k; i++) {
        cin >> x >> y >> d;
        for(j = 0; j < n; j++) {
            for(l = 0; l < n; l++) {
                if(fabs(x - j) + fabs(y - l) == d) {
                    m[make_pair(j, l)] += 1;
                }
            }
        }
    }
    int ansx = 0, ansy = 0, tot = 0;
    for(it = m.begin(); it != m.end(); it++) {
        if(it->second == k) {
            tot += 1;
            ansx = it->first.first;
            ansy = it->first.second;
        }
    }
    if(tot != 1) {
        ansx = -1;
        ansy = -1;
    }
    cout << ansx << " " << ansy << endl;

    return 0;
}

