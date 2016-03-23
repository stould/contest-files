#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int i, n, k, steps;

int main(void) {
    while(scanf("%d%d", &n, &k)) {
        vector<int> v; v.push_back(n);
        steps = 0;
        while(1) {
            int c = 0;
            for(i = 0; i < v.size(); i++) {
                if(v[i] > k) {
                    int a = (int)floor(v[i] / 2.);
                    int b = (int)ceil(v[i] / 2.);
                    v.push_back(a);
                    v.push_back(b);
                    v.erase(v.begin() + i);
                    c++;
                }
            }
            if(c == 0) break;
            steps++;
        }
        printf("%d\n", v.size());
    }
    return 0;
}
