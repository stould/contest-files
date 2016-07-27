#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 200;

int N;
int P[MAXN];
bool used[MAXN];
vector<int> graph[MAXN];
vector<pair<int, int> > ans;

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

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans.push_back(make_pair(i + 1, matchR[i] + 1));
            used[i] = used[matchR[i]] = true;
        }
    }
    return result;
}


int main(void) {
    cin >> N;

    int all = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        all += P[i];
    }

    int each = all / (N / 2);


    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N; j++) {
            if (i != j && P[i] + P[j] == each) {
                graph[i].push_back(j);
            }
        }
    }

    maxBPM();

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";        
    }
    return 0;    
}
