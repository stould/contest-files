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
typedef unsigned uint;

int A, B;
string curr;
int dp[9][10][2][10][10];
int mark[9][10][2][10][10];
int state = 1;
int ans[12];

int func(int pos, int cnt, int prefix, int goal, int seen_non_zero, int last) {
    if (pos == (int) curr.size()) {
        return cnt;
    } else {
        int& ans = dp[pos][cnt][prefix][goal][last];

        if (mark[pos][cnt][prefix][goal][last] != state) {
            mark[pos][cnt][prefix][goal][last] = state;
            
            ans = 0;

            int now = curr[pos] - '0';
            int limit = prefix ? now : 9;
            
            for (int i = 0; i <= limit; i++) {
                int add = i == goal;
				
                if (i == 0 && goal == 0) {
                    if (!seen_non_zero) {
                        add = 0;
                    }
                }
                ans += func(pos + 1, cnt + add, (prefix && i == now) ? 1 : 0, goal, (seen_non_zero || (i != 0)) ? 1 : 0, i);
            }
        }
		
        return ans;
    }
}

void buildAnswer() {
    curr = to_string(B);
    state++;
    for (int i = 0; i < 10; i++) {        
        ans[i] = func(0, 0, 1, i, 0, 10);
    }
    curr = to_string(A - 1);
    state++;
    for (int i = 0; i < 10; i++) {
        ans[i] -= func(0, 0, 1, i, 0, 10);
    }
}

int main(void) {
    while (scanf("%d%d", &A, &B) == 2 && !(A == 0 && B == 0)) {
        buildAnswer();
        for (int i = 0; i < 10; i++) {
            if (i > 0) putchar(' ');
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}

