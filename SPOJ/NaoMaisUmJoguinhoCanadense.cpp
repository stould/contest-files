#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
ll dp[63];
string s;
 
int main(void) {
    for(int i = 0; i <= 60; i++) dp[i] = (ll) 1 << i;
    int test = 1;
    while(cin >> s) {
        ll ans = 0L;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++) if(s[i] == 'b') ans += (ll) dp[i];
        cout << "Palavra " << (test++) << endl << ans << endl << endl;
    }
    return 0;
}
 
