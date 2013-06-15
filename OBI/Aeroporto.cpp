#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int a, f, t, i, j, v, teste = 1, graph[101];

int main(void) {
  //  freopen("i.in", "r", stdin);
    while(1) {
        scanf("%d%d", &a, &v);
        if(!a && !v) break;

        memset(graph, 0, sizeof(graph));

        int flights = 0;
        for(i = 0; i < v; i++) {
            scanf("%d%d", &f, &t);
            graph[f] += 1;
            graph[t] += 1;
            flights = max(flights, max(graph[f], graph[t]));
        }
        printf("Teste %d\n", teste++);
        for(i = 1; i <= a; i++) {
            if(graph[i] == flights) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
    }
    return 0;
}
