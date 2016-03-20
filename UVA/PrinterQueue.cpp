#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

int i, p, test, n, m, base = 0;

bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second > b.second;
}

int main(void) {
    scanf("%d", &test);
    while(test--) {
        scanf("%d%d", &n, &m);
        base = 1;
        vector<pair<int, int> > q;
        for(i = 0; i < n; i++) {
            scanf("%d", &p);
            q.push_back(make_pair(p, i));
        }
        while(1) {
            pair<int, int> help = q[0];
            bool has = false;
            for(i = 1; i < q.size(); i++) {
                if(q[i].first > q[0].first) {
                    has = true; break;
                }
            }
            if(has) {
                q.erase(q.begin()); q.push_back(help);
            } else {
                if(q[0].second == m) break;
                q.erase(q.begin());
                base++;
            }
        }
        printf("%d\n", base);
    }
    return 0;
}
