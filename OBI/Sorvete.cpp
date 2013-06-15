#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int S = -1, P = -1;

int main() {
    while(S != 0 && P != 0) {
        scanf("%d %d", &S, &P);
        vector<pair<int, int> > m;
        int f, t;
        for(int i = 0; i < P; i++) {
            scanf("%d %d", &f, &t);
            m.push_back(make_pair(f, t));
        }
        sort(m.begin(), m.end());

        for(int i = 0; i < (int) m.size(); i++) {
            int st = m[i].first, j = i + 1;
            bool ok = false;
            while(j < m.size() && m[j].first <= m[i].second) {
                i++;
                j++;
                ok = true;
            }
            if(!ok) {
                printf("%d %d\n", st, m[j - 1].second);
            } else {
                printf("%d %d\n", st, m[j].second);
            }
            i = j;
        }
    }
    return 0;
}
