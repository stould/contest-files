#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> memo(1001);
    fill(memo.begin(), memo.end(), 0);

    memo[2] = 1;
    cin >> n;

    for(int i = 3; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }

    cout << memo[n] % 26 << endl;
    return 0;
}
