#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

struct pais {
    int id, gold, plate, bronze;
    pais(int _id){
        id = _id;
        gold = plate = bronze = 0;
    }

    bool operator<(const pais& p) const {
        if(gold != p.gold) {
            return gold > p.gold;
        } else if(plate != p.plate) {
            return plate > p.plate;
        } else if(bronze != p.bronze) {
            return bronze > p.bronze;
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
        v[a].gold += 1;
        v[b].plate += 1;
        v[c].bronze += 1;
    }
    sort(v.begin(), v.end());// reverse(v.begin(), v.end());
    for(i = 0; i < n; i++) {
        if(i == n - 1) {
            //printf("%d %d %d %d\n", v[i].gold, v[i].plate, v[i].bronze, v[i].id);
            printf("%d\n", v[i].id+1);
        } else {
            //printf("%d %d %d %d\n", v[i].gold, v[i].plate, v[i].bronze, v[i].id);
            printf("%d ", v[i].id+1);
        }
    }
    return 0;
}
