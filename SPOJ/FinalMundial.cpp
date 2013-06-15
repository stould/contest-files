#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1061109567;
int c, n, m, u, v, w, o, d, t, helper[110][110][110], test = 1;

struct query {
    int o, d, t;
    query(int _o, int _d, int _t) {
        o = _o; d = _d; t = _t;
    }
    query(){}
};

int main(void) {
    while(~scanf("%d%d", &n, &m)) {
        memset(helper, 63, sizeof(helper));
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if(w < helper[0][u][v]) helper[0][u][v] = w;
        }
        scanf("%d", &c);
        printf("Instancia %d\n", test++);
        vector<query> qp;
        int maximal_t = 0;
        for(int x = 0; x < c; x++) {
            scanf("%d%d%d", &o, &d, &t);
            qp.push_back(query(o, d, t));
            if(t > maximal_t) maximal_t = t;
        }
        if(maximal_t == 0) maximal_t = 1;
        for(int k = 1; k <= maximal_t; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    helper[k][i][j] = helper[k - 1][i][j];
                    if(helper[k][i][j] > helper[k - 1][i][k] + helper[k - 1][k][j]) {
                        helper[k][i][j] = helper[k - 1][i][k] + helper[k - 1][k][j];
                    }
                }
            }
        }
        for(int x = 0; x < c; x++) {
            if(helper[qp[x].t][qp[x].o][qp[x].d] != INF) {
                printf("%d\n", helper[qp[x].t][qp[x].o][qp[x].d]);
            } else {
                printf("-1\n");
            }
        }
        printf("\n");
    }
    return 0;
}
