#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n, ans, mx;

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        ans = 0, mx = 0;
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            if(p[i] > mx) mx = p[i];
        }
        vector<int> v(mx + 1, -1);
        set<int> s;
        for(int i = 0; i < n; i++) {
            v[p[i] - 1] = p[i];
        }
        reverse(v.begin(), v.end());
        sort(v.begin(), v.end());
        int rec = 0;
        for(int i = 0; i < n; i++) {
            if(count(s.begin(), s.end(), p[i])) {
                for(int j = i - 1; j >= 0; j--) {
                    ans += 1;
                    if(p[i] == p[j]) {
                        rec++;
                        break;
                    }
                }
            } else {
                ans += rec + p[i];
                s.insert(p[i]);
                rec++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
