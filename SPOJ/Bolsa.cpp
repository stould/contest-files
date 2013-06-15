#include <iostream>
#include <stdio.h>

using namespace std;

int i, j, n, tmp, v[10010];
int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n && n > 0) {
        int ans = -1000000; tmp = 0;
        for(i = 0; i < n; i++) {
            cin >> v[i];
            tmp += v[i];
            if(tmp > ans) ans = tmp;
            if(tmp < 0) tmp = 0;
        }
        if(ans > 0) {
            cout << "The maximum winning streak is " << ans << "." << endl;
        } else {
            cout << "Losing streak." << endl;
        }
    }
    return 0;
}
