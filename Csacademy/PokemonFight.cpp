#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int P[100005];
int Q[100005];

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    for (int i = 0 ; i < M; i++) {
        cin >> Q[i];
    }
    
    sort(P, P + N);
    sort(Q, Q + M);
    
    int pos = 0;
    vector<int> used(N, 0);
    
    for (int i = 0; i < N; i++) {
        if (pos == M) break;
        if (P[i] > Q[pos]) {
            used[i] = true;
            pos += 1;
        }
    }
    if (pos != M) {
        cout << "-1\n";
    } else {
        int ans = 0;
        
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                ans += P[i];
            }
        }
        cout << ans << "\n";
    }
}
