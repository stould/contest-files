#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

typedef long long Int;

const int MAXN = 100005;

int N, M, C[MAXN], W[MAXN];
bool pressed[MAXN];

vector<int> graph[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    int A, B;
    
    for (int i = 0; i < M; i++) {
        cin >> A >> B;        
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    queue<int> q;
    
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        
        if (C[i] == W[i]) {
            q.push(i);
        }        
    }
    
    vector<int> press;
   
    for ( ; !q.empty(); ) {
        int now = q.front();
        press.push_back(now);
        q.pop();
        
        for (int j = 0; j < (int) graph[now].size(); j++) {
            W[graph[now][j]] += 1;    
            if (C[graph[now][j]] == W[graph[now][j]]) {
                q.push(graph[now][j]);
            }    
        }
    }   
    
    cout << press.size() << "\n";
    
    for (int i = 0; i < (int) press.size(); i++) {
        cout << press[i] << " ";
    }
    cout << "\n";   
    return 0;
}
