#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int n, m, a, b;

int marker[1100][1100], caps[1100][1100], difm[1100], difc[1100];

int main(void) {
    cin >> n >> m;
    int mat = 0, perf = 0;

    memset(marker, 0, sizeof(marker)); memset(caps, 0, sizeof(caps));
    memset(difm, 0, sizeof(difm)); memset(difc, 0, sizeof(difc));

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        marker[a][b]++;
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        caps[a][b]++;
    }

    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            int matched = min(marker[i][j], caps[i][j]);
            mat += matched;
            perf += matched;
            difm[j] += marker[i][j] - matched;
            difc[j] += caps[i][j] - matched;
        }
    }
    for(int i = 0; i < 1001; i++) {
        mat += min(difm[i], difc[i]);
    }
    cout << mat << " " << perf << endl;
    return 0;
}
