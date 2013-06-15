#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<long long> W(N);

    long long sum = 0;

    for(int i = 0; i < N; i++) {
        scanf("%d", &W[i]);
        sum += W[i];
    }

    int average = sum / N;
    int ans = 0;

    for(int i = 0; i < N; i++) {
        if(W[i] > average) {
            ans += W[i] - average;
        }
    }

    printf("%d", ans);


    return 0;
}
