#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    int n, r = 0;
    scanf("%d", &n);

    vector<pair<int , int> > v(n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());
    int ct = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].second < r) {
            ct++;
        } else {
            r = v[i].second;
        }
    }

    printf("%d", ct);

    return 0;
}
