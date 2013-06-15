#include <limits>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

int n;

int main(void) {
    scanf("%d", &n);
    vector<pair<int, int> > p(n);

    double m = numeric_limits<double>::max();

    for(int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
        for(int j = i - 1; j >= 0; j--) {
            double tmp = hypot(p[i].first - p[j].first, p[i].second - p[j].second);
            if(tmp < m) {
                m = tmp;
            }
        }
    }
    printf("%.3f\n", m);
    return 0;
}
