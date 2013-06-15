#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

int _n;

int main() {
    int n, x, d;
    vector<pair<int, int> > pos;

    scanf("%d", &n);
    _n = n;
    while(n > 0) {
        scanf("%d %d", &x, &d);
        pos.push_back(make_pair(x, d));
        n--;
    }
    bool hap = false;

    for(int i = 0; i < _n; i++) {
        for(int j = 0; j < _n; j++) {
            if(pos[i].first + pos[i].second == pos[j].first && pos[j].first + pos[j].second == pos[i].first) {
                hap = true;
                goto end;
            }
        }
    }
    end:
    if(hap) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
