#include <iostream>
#include <string>

using namespace std;

int n, values[10000001], dp[1000001], ans[10000001];

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> values[i];
        dp[i] = -1;
        ans[i] = -1;
    }
    dp[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--) {
        if(values[i] < values[dp[i + 1]]) {
            dp[i] = i;
        } else {
            dp[i] = dp[i + 1];
        }
        for(int j = dp[i]; j < n; j++) if(values[j] < values[i]) dp[i] = j;
        int ac = 0;
        for(int j = i+1; j < dp[i]; j++) {
            if(values[j] < values[i]) {
                ac++;
            }
        }
        if(ac == 0 && dp[i] == i) {
            ans[i] = -1;
        } else {
            ans[i] = ac;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
