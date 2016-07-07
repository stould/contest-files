#include <bits/stdc++.h>

using namespace std;

int N, V;
int K[10];
vector<int> C[10];
int ans;

void func(int r, int c) {
    if (r == N) {
        ans += 1;
    } else if (c >= (int) C[r].size()) {
        func(r + 1, 0);
    } else {
        int curr = 1;
    
        if (c - 1 >= 0) {
            curr = max(curr, C[r][c - 1]);
        }
        if (r - 1 >= 0) {
            curr = max(curr, C[r - 1][c] + 1);
        }

        for ( ; curr <= V; curr++) {
            C[r][c] = curr;
            func(r, c + 1);
        }
    }
}

int main() {
    while (cin >> N) {
        for (int i = 0; i < N; i++) {      
            cin >> K[i];

            C[i].clear();

            for (int j = 0; j < K[i]; j++) {
                C[i].push_back(0);
            }
        }

        cin >> V;

        ans = 0;
        func(0, 0);
        cout << ans << "\n";
    }
    return 0;
}
