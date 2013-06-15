#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int d, v;
char str[1000000000];
vector<int> n;

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("i.out", "w", stdout);
    while(scanf("%d%d", &d, &v) && !(d == 0 && v == 0)) {
        n.clear();
        scanf("%s", str);
        for(int i = 0; i < d; i++) {
            n.push_back(str[i] - '0');
        }
        while(v > 0 && n.size() > 0) {
            int less = 11, index = -1;
            for(int i = 0; i < n.size(); i++) {
                if(n[i] < less) {
                    less = n[i];
                    index = i;
                }
            }
            n.erase(n.begin() + index);
            v -= 1;
        }
        if(n.size() == 0) {
            printf("0\n");
        } else {
            for(int i = 0; i < n.size(); i++) {
                printf("%d",n[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
