#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300030;

int N, K;

int main() {
    while (cin >> N >> K) {

        vector<pair<long long, int> > P;

        for (int i = 0; i < N; i++) {
            int A, B;
    
            cin >> A >> B;
    
            P.push_back(make_pair(A, 1));
            P.push_back(make_pair(A + B, 0));    
        }

        sort(P.begin(), P.end());

        int ans = 0;

        priority_queue<long long, vector<long long>, greater<long long> > pool;
  
        for (int i = 0; i < 2 * N; i++) {
            if (P[i].second == 0) {
                pool.push(P[i].first);
            } else {
                bool can = false;
      
                while (!pool.empty()) {
                    if (P[i].first - pool.top() > K) {
                        pool.pop();
                    } else {
                        can = true;
                        pool.pop();
                        break;
                    }
                }      
      
                if (!pool.empty() || can) {
                    ans += 1;
                }
            }
        }
  
        cout << ans << "\n";
    }
    return 0;
}
