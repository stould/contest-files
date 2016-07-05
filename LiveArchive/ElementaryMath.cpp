#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N;
vector<int> graph[MAXN];
long long A[MAXN], B[MAXN];
map<long long, int> fa;
int id = 1;
int matchR[MAXN], matchL[MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
        int v = graph[u][i];
		
        if (!seen[v]) {
            seen[v] = true; 
 
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM() {
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

int build(int x) {
    if (fa.find(x) == fa.end()) {
        fa[x] = id;
        id++;      
    }  
    return fa[x];
}

int main() {
    while (cin >> N) {
        for (int i = 0; i < MAXN; i++) {
            graph[i].clear();
        }
	for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];    

            graph[i].push_back(N + build(A[i] + B[i]));
            graph[i].push_back(N + build(A[i] * B[i]));
            graph[i].push_back(N + build(A[i] - B[i]));
	}

	int ans = maxBPM();

	if (ans == N) {
            for (int i = 0; i < N; i++) {
                if (matchL[i] == N + build(A[i] + B[i])) {
                    cout << A[i] << " + " << B[i] << " = " << A[i] + B[i] << "\n";
                } else if (matchL[i] == N + build(A[i] * B[i])) {
                    cout << A[i] << " * " << B[i] << " = " << A[i] * B[i] << "\n";
                } else {
                    cout << A[i] << " - " << B[i] << " = " << A[i] - B[i] << "\n";
                }
            }
	} else {
            cout << "impossible\n";
	}
    }
    return 0;
}
