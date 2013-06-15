#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

int n, m, ans = 0;

int main(void) {
    cin >> n >> m;
    string maze[n+1];
    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = i+1; k < n; k++) {
                for(int l = j+1; l < m; l++) {
                    bool ok = true;
                    for(int a = i; a <= k; a++) for(int b = j; b <= l; b++) if(maze[a][b] == '1') ok = false;
                    if(ok && (abs(k - i + 1) * 2) + (abs(l - j + 1) * 2) > ans) {
                        ans = (abs(k - i + 1) * 2) + (abs(l - j + 1) * 2);
                    }
                 }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
