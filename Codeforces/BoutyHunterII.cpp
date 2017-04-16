#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int N;
int D[MAXN];
vector<int> graph[MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
        int v = graph[u][i];

        if (!seen[v]) {
            seen[v] = true; 
 
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM() {
    int matchR[MAXN];
 
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; 
    for (int u = 0; u < N; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(u, seen, matchR)) {
            result++;
        }
    }
    return result;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> D[i];
    
        for (int j = 0; j < D[i]; j++) {
            int A;
            cin >> A;
            graph[i].push_back(A);
        }
    }
  
    cout << N - maxBPM() << "\n";
    return 0;
}

