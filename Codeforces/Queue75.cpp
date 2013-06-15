#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, dp[100001], memo[100001];

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> memo[i];
    }
    dp[n - 1] = n - 1;

    vector<int> ans;
    ans.push_back(-1);
    for(int i = n - 2; i >= 0; i--) {
        if((memo[i] == memo[dp[i + 1]]) || (memo[i] < memo[dp[i + 1]])) {
            dp[i] = i;
        } else {
            for(int j = dp[i] + 1, k = dp[i] - 1; j < n || k >= 0; j++, k--) {
                if(j < n && memo[j] < memo[i]) dp[i] = j;
            }
        }
        int count = (dp[i]) - (i + 1);
        if(dp[i] == i) {
            ans.push_back(-1);
        } else {
            ans.push_back(count);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << endl;
    return 0;
}
