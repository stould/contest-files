#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<int> prices(N);
    for(int i = 0; i < N; i++) cin >> prices[i];
    sort(prices.begin(), prices.end());
    int sum = 0, mx = 0;
    for(int i = 0; i < M; i++) {
        if(prices[i] > 0) {
            sum -= prices[i];
        } else {
            sum += -prices[i];
        }
        mx = max(mx, sum);
    }
    cout << mx << endl;
    return 0;
}
