#include <iostream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
 }

int main(void) {
    freopen("i.in", "r", stdin);
    string g;
    int i, ans = 0;

    cin >> g;
    int l = 0, u = 0;
    for(i = 0; i < (int) g.size(); i++) {
        if(isUpper(g[i])) {
            u++;
        } else {
            l++;
        }
    }
    if(l == g.size() || u == )
    for(i = 0; i < (int) g.size(); i++) {
        if(isUpper(g[i])) {
            if(i + 1 < g.size() && isUpper(g[i + 1])) {
                g[i + 1] = tolower(g[i + 1]);
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
