#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 5001;

int main() {
    int n, ct = 0;
    scanf("%d", &n);

    vector<int> values(INF);
    vector<bool> memo(INF);
    fill(memo.begin(), memo.end(), false);

    for(int i = 0; i < n; i++) scanf("%d", &values[i]);

    for(int i = 0; i < n; i++) {
        if(values[i] > n) {
            ct++;
        } else if(memo[values[i]]) {
            ct++;
        } else {
            memo[values[i]] = true;
        }
    }
    printf("%d", ct);
    return 0;
}
