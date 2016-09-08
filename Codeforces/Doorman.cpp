#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int THERSHOLD = 101;
const int INF = 10001010;

string S;
int N, L;

int dp[MAXN][MAXN][2 * MAXN];

int func(int pos, int last, int df) {
    if (df > L || df < -L) {
        return -INF;
    } else if (pos >= N) {
        if (last == N) {
            return 0;
        } else {
            int nf = df;
      
            if (S[last] == 'M') {
                nf += 1;
            } else {
                nf -= 1;
            }
            if (nf > L || nf < -L) {
                return -INF;
            } else {
                return 0;
            }
        }
    } else {
        int& ans = dp[pos][last][df + THERSHOLD];
        
        if (ans == -1) {
            ans = 0;
      
            //try normal
            int nf = df;

            if (S[pos] == 'M') {
                nf += 1;
            } else {
                nf -= 1;
            }
            
            ans = max(ans, 1 + func(pos + 1, last, nf));
            
            //put in queue
            if (last == N) {
                ans = max(ans, func(pos + 1, pos, df));
            } else {
                //remove from queue
                int ndf = df;
	
                if (S[last] == 'M') {
                    ndf += 1;
                } else {
                    ndf -= 1;
                }      

                //use now
                int ndf_use = ndf;
	
                if (S[pos] == 'M') {
                    ndf_use += 1;
                } else {
                    ndf_use -= 1;
                }
                ans = max(ans, 2 + func(pos + 1, N, ndf_use));
	
                //dont use
                ans = max(ans, 1 + func(pos + 1, pos, ndf));
            }
        }
        return ans;
    }
}

int main() {
    cin >> L >> S;

    N = (int) S.size();

    memset(dp, -1, sizeof(dp));

    cout << func(0, N, 0) << "\n";

    return 0;
}
