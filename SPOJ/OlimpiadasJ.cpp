#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

struct pais {
    int id, gold, plate, bronze, all;
    pais(int _id){
        id = _id;
        gold = plate = bronze = all = 0;
    }

    bool operator<(const pais& p) const {
        if(all != p.all) {
            return all > p.all;
        } else {
            return id < p.id;
        }
    }
};

int i, n, m, a, b, c;

int main(void) {
    scanf("%d%d", &n, &m);
    vector<pais> v;
    for(i = 0; i < n; i++) v.push_back(pais(i));
    for(i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
        v[a].all += 1;
        v[b].all += 1;
        v[c].all += 1;
    }
    sort(v.begin(), v.end());
    for(i = 0; i < n; i++) {
        if(i == n - 1) {
            printf("%d\n", v[i].id+1);
        } else {
            printf("%d ", v[i].id+1);
        }
    }
    return 0;
}
