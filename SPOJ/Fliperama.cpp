#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    int N, M, ct = 0;

    cin >> N >> M;
    vector<int> memo(N);

    for(int i = 0; i < N; i++) scanf("%d", &memo[i]);

    sort(memo.begin(), memo.end());

    for(int i = memo.size() - 1; i >= 0 && ct < M; i--, ct++) {
        cout << memo[i] << endl;
    }
    return 0;
}
