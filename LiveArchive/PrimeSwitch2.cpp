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

const int MAXN = 1010;

int T, N, K;
int P[MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K;

        vector<int> sp, lp;
        int ans = 0;
        
        for (int i = 0; i < K; i++) {
            cin >> P[i];

            if (P[i] <= (int) sqrt(N)) {
                sp.push_back(P[i]);
            } else {
                lp.push_back(P[i]);
            }
        }

        int S = (int) sp.size();
        Int L = (int) lp.size();

        sort(lp.begin(), lp.end());
        
        for (int x = 0; x < (1 << S); x++) {
            vector<int> batch(N + 1, 0);
            int sumNow = 0;
            
            for (int i = 0; i < S; i++) {
                if (x & (1 << i)) {
                    for (int j = sp[i]; j <= N; j += sp[i]) {
                        batch[j] ^= 1;

                        if (batch[j] == 1) {
                            sumNow += 1;
                        } else {
                            sumNow -= 1;
                        }
                    }
                }
            }

            for (int i = 0; i < L; i++) {
                vector<int> curr = batch;
                int currSum = sumNow;
                
                for (int j = lp[i]; j <= N; j += lp[i]) {
                    curr[j] ^= 1;

                    if (curr[j] == 1) {
                        currSum += 1;
                    } else {
                        currSum -= 1;
                    }
                }
                if (currSum > sumNow) {
                    batch = curr;
                }
            }

            chmax(ans, accumulate(batch.begin(), batch.end(), 0));
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
