#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

int n, m;

ll ans = 1L;
const int MOD = 1000000007;

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set<char> st;
        for(int j = 0; j < m; j++) {
            st.insert(s[j]);
        }
        ans = (ans * (ll) (st.size())) % MOD;
    }
    cout << ans << endl;
    return 0;
}

