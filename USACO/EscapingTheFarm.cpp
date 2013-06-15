#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int m = 0;

bool poss(int x, int y) {
    while(x > 0 && y > 0) {
        if(x % 10 + y % 10 >= 10) return false;
        x /= 10;
        y /= 10;
    }
    return true;
}

void rec(int index, int sum, int ct, vector<long long>& w, int size) {
    if(ct > m) m = ct;
    if(index >= size) return;
    if(poss(w[index], sum)) {
       rec(index + 1, sum + w[index], ct + 1, w, size);
    }
    rec(index + 1, sum, ct, w, size);
}

int main() {
    freopen("I.2", "r", stdin);
    int N;

    scanf("%d", &N);
    vector<long long> w(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }

    int index = 0;

    rec(0, 0, 0, w, N);

    printf("%d\n", m);
    return 0;
}
