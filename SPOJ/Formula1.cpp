#include <iostream>
#include <vector>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <valarray>
#include <complex>
#include <utility>
#include <new>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <math.h>

using namespace std;

int i, j, k, g, p, s, tmp, start;

struct piloto {
    int index, pontos;

    piloto() {
        pontos = 0;
    }

    bool operator<(const piloto& p) const {
        if(pontos != p.pontos) {
            return pontos > p.pontos;
        } else {
            return index < p.index;
        }
    }
};

int main(void) {
    while(scanf("%d%d", &g, &p) && !(g == 0 && p == 0)) {
        vector<int> v[g];
        for(i = 0; i < g; i++) {
            v[i] = vector<int>(p, 0);
            for(j = 0; j < p; j++) {
                scanf("%d", &tmp); tmp--;
                v[i][tmp] = j;
            }
        }
        scanf("%d", &s);
        vector<int> grid[s];
        for(i = 0; i < s; i++) {
            scanf("%d", &start);
            for(j = 0; j < start; j++) {
                scanf("%d", &tmp);
                grid[i].push_back(tmp);
            }
            vector<piloto> vp(p);
            for(j = 0; j < p; j++) vp[j].index = j + 1;
            for(j = 0; j < g; j++) {
                for(k = 0; k < start; k++) {
                    vp[v[j][k]].pontos += grid[i][k];
                }
            }
            sort(vp.begin(), vp.end());
            int mx = vp[0].pontos;
            vector<int> sp;
            for(j = 0; j < vp.size() && vp[j].pontos == mx; j++) {
                sp.push_back(vp[j].index);
            }
            for(j = 0; j < sp.size(); j++) {
                if(j == sp.size() - 1) {
                    printf("%d\n", sp[j]);
                } else {
                    printf("%d ", sp[j]);
                }
            }
        }
    }
    return 0;
}
