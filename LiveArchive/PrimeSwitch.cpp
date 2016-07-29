#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int T, N, K;
int P[MAXN];

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K;

        vector<int> small, big;
    
        for (int i = 0; i < K; i++) {
            cin >> P[i];
      
            if (P[i] <= (int) sqrt(N)) {
                small.push_back(P[i]);
            } else {
                big.push_back(P[i]);
            }
        }

        sort(small.begin(), small.end());
        sort(big.begin(), big.end());

        vector<int> state(N + 1, 0);
        int best = 0;
		
        for (int i = 0; i < (1 << (int) small.size()); i++) {
            vector<int> tmpState(N + 1, 0);
            int on = 0;
			
            for (int j = 0; j < (int) small.size(); j++) {
                if (i & (1 << j)) {
                    for (int k = small[j]; k <= N; k += small[j]) {
                        tmpState[k] ^= 1;

                        if (tmpState[k] == 1) {
                            on += 1;
                        } else {
                            on -= 1;
                        }
                    }
                }
            }
      
            for (int j = 0; j < (int) big.size(); j++) {
                vector<int> st = tmpState;
                int now = on;
					
                for (int k = big[j]; k <= N; k += big[j]) {
                    st[k] ^= 1;

                    if (st[k] == 1) {
                        now += 1;
                    } else {
                        now -= 1;
                    }
                }
                if (now > on) {
                    tmpState = st;
                }
            }
			
            int cnt = accumulate(tmpState.begin(), tmpState.end(), 0);

            if (best < cnt) {
                best = cnt;
                state = tmpState;
            }
        }

        int ans = accumulate(state.begin(), state.end(), 0);

        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
