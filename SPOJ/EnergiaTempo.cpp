#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int f, p, e, a, ha, hb;

struct task {
    int p, f, e, a, tot;
    task(int _p, int _f, int _e, int _a) {
        p = _p; f = _f; e = _e; a = _a;
        tot = e*a;
    }
    bool operator<(const task& t) const {
        return tot < t.tot;
    }
};

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d%d%d", &f, &p, &e, &a) == 4 && !(f+p+e+a == 0)) {
        vector<task> vt;
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < f; j++) {
                scanf("%d%d", &ha, &hb);
                vt.push_back(task(i, j, ha, hb));
            }
        }
        int ans = 0, last = -1;
        sort(vt.begin(), vt.end());
        for(int x = 0; x < p; x++) {
            for(int i = 0; i < vt.size(); i++) {
                if(vt[i].p == x) {
                    ans += vt[i].tot;
                    if(x != 0 && vt[i].f != last) {
                        ans += e*a;
                    }
                    last = vt[i].f;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
