#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

typedef pair<int, int> point;

int main() {
    int N;

    scanf("%d", &N);

    vector<point> p(N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    sort(p.begin(), p.end());
    sort(p.begin(), p.end());


    return 0;
}
