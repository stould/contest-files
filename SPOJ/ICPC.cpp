#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#define REP(i, n) for(i = 0; i < n; i++)

typedef long long ll;

using namespace std;

int n, test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.in", "w", stdout);
    while(scanf("%d", &n) && n != 0) {
        pair<double, double> p[110];
        double min_x = 100000000, max_x = -1000000000, max_y = -100000000, min_y = 10000000;
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &p[i].first, &p[i].second);
            min_x = min(min_x, p[i].first);
            max_x = max(max_x, p[i].first);
            min_y = min(min_y, p[i].second);
            max_y = max(max_y, p[i].second);
        }
        double middle_x = ((double) (max_x + min_x) / (double) 2.0);
        double middle_y = ((double) (max_y + min_y) / (double) 2.0);
        double raio = 0.0;

        for(int i = 0; i < n; i++) {
            raio = max(raio, (double) hypot(middle_x - p[i].first, middle_y - p[i].second));
        }
        if(n == 1) {
            middle_x = p[0].first;
            middle_y = p[0].second;
            raio = 1.0;
        }
        printf("Instancia %d\n%.2lf %.2lf %.2lf\n\n", test++, middle_x, middle_y, raio);
    }
    return 0;
}
