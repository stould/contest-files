#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> ans(n);
    fill(ans.begin(), ans.end(), true);
    ans[0] = ans[1] = false;

    for(int i = 2; i <= (int) sqrt(n); i++) {
        if(ans[i]) {
            for(int j = i * i; j <= n; j += i) {
                ans[j] = false;
            }
        }
    }
    return ans;
}

int main() {
    int n, ct = 0;
    scanf("%d", &n);

    vector<bool> v = sieve(n + 1);

    for(int i = 1; i <= n; i++) {
        int c = 0;
        for(int j = 1; j < n; j++) {
            if(v[j] && i % j == 0) {
                c++;
            }
        }
        if(c == 2) {
            ct++;
        }
    }
    printf("%d", ct);
    return 0;
}
