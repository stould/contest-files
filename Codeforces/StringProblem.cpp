#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void chkmin(int &a, int b) { a = a < b ? a : b; }

int n, gr[30][30], dp[100010][2];
string a, b;

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> a >> b >> n;
    memset(gr, 63, sizeof(gr));
    memset(dp, 63, sizeof(dp));
    for(int i = 0; i < n; i++) {
        char x, y; int ct;
        cin >> x >> y >> ct;
        chkmin(gr[x-'a'][y-'a'], ct);
    }
    if(a.size() != b.size()) {
        cout << "-1\n"; return 0;
    } else {
        dp[0][0] = dp[0][1] = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                if(i == 0) {
                    dp[i][0] = min(dp[i][0], dp[i][0] + gr[a[i]-'a'][b[i]-'a']);
                    dp[i][1] = min(dp[i][1], dp[i][1] + gr[a[i]-'a'][b[i]-'a']);
                } else {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1];
                    dp[i][0] = min(dp[i][0], dp[i][0] + gr[a[i]-'a'][b[i]-'a']);
                    dp[i][1] = min(dp[i][1], dp[i][1] + gr[a[i]-'a'][b[i]-'a']);
                }
            } else {
                if(i != 0) {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1];
                }
            }
        }
        cout << min(dp[a.size()-1][0], dp[a.size()-1][1]) << endl;
    }
    return 0;
}
