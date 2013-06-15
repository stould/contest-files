#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

bool check(int a, int b) {
    while(a > 0 && b > 0) {
        if((a % 10) + (b % 10) >= 10) {
            return false;
        }
        a /= 10;
        b /= 10;
    }
    return true;
}

int main() {
    freopen("Escaping/I.8", "r", stdin);
    int N;
    scanf("%d", &N);

    vector<long long> w(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &w[i]);
    }
    int best = 0;

    for(int i = 0; i < (1 << N); i++) {
        long long sum = 0;
        int ct = 0;
        for(int j = 0; j < N; j++) {
            if((i >> j) & 1 > 0 && check(sum, w[j])) {
                ct += 1;
                sum += w[j];
            }
        }
        if(ct > best) {
            best = ct;
        }
    }
    t2 = clock();
    printf("%d\n%.3f", best, 1000 * (((float)t2 - (float)t1) / 1000000.0F));
    return 0;
}
