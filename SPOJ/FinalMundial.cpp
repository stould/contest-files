#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1061109567;
int c, n, m, u, v, w, o, d, t, helper[120][120][120], test = 1;

int main(void) {
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n; j++) {
				if(i != j) {
					helper[0][i][j] = INF;
				} else {
					helper[0][i][j] = 0;
				}
			}
		}
		
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if(w < helper[0][u][v]) helper[0][u][v] = w;
        }
		
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    helper[k][i][j] = helper[k - 1][i][j];
                    if(helper[k][i][j] > helper[k - 1][i][k] + helper[k - 1][k][j]) {
                        helper[k][i][j] = helper[k - 1][i][k] + helper[k - 1][k][j];
                    }
                    if(i == j) helper[k][i][j] = 0;
                }
            }
        }
        scanf("%d", &c);
        printf("Instancia %d\n", test++);
        for(int x = 0; x < c; x++) {
            scanf("%d%d%d", &o, &d, &t);
            if(helper[t][o][d] == INF) {
                printf("-1\n");
            } else {
                printf("%d\n", helper[t][o][d]);
            }
        }
        printf("\n");
    }
    return 0;
}

