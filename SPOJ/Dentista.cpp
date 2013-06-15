#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int n;

int main(void) {
    scanf("%d", &n);
    vector<pair<int, int> > p(n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].first, & p[i].second);
    }
    sort(p.begin(), p.end());
    int ans = 1, j = 0;

    for(int i = 1; i < n; i++) {
        if(p[i].second >= p[j].first) {
            ans += 1;
            j = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}
