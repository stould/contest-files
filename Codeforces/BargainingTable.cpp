#include <iostream>
#include <string>

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
            for(int k = i; k < n; k++) {
                for(int l = j; l < m; l++) {
                    bool ok = true;
                    for(int a = i; a <= k; a++) for(int b = j; b <= l; b++) if(maze[a][b] == '1') ok = false;
                    if(ok) {
                        ans = max(ans, (k - i + 1 + l - j + 1)*2);
                    }
                 }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
