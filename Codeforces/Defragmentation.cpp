#include <iostream>

using namespace std;

int i, j, ax, tmp, n, m, used[300], who[300];

int main(void) {
    cin >> n >> m;
    for(i = 0; i < n; i++) { used[i] = 0; who[i] = 0;}
    for(i = 0; i < m; i++) {
        cin >> ax;
        for(j = 0; j < ax; j++) {
            cin >> tmp;
            used[tmp] = 1;
            who[tmp] = i;
        }
    }
    int k = 0;
    vector<string> ans;
    for(i = 0; i <= n; i++) {
        if(used[i]) {
            int ct = 0;
            for(j = i + 1; j <= n; j++) {
                if(used[j] && who[j] == i) {
                    k += 1;
                    ans.push_back(i)
                }
            }
        }
    }
    return 0;
}
