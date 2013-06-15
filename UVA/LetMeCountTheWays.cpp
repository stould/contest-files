#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 30000;

ll coins[5] = {1, 5, 10, 25, 50};
ll memo[MAX + 1];

int main(void) {
    memo[0] = 1;
    for(int i = 0; i < 5; i++) {
        ll c = coins[i];
        for(int j = c; j <= MAX; j++) {
            memo[j] += memo[j - c];
        }
    }
    ll n;
    while(cin >> n) {
        if(memo[n] == 1) {
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        } else {
            cout << "There are " << memo[n] << " ways to produce " << n << " cents change." << endl;
        }
    }
    return 0;
}
