#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int N, M;

    scanf("%d %d", &N, &M);
    vector<int> cows(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &cows[i]);
    }

    map<int, int> cost;

    for(int i = 1; i < M + 1; i++) {
        scanf("%d", &cost[i]);
    }

    return 0;
}
