#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0;

int main(void) {
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());

    int coins = 0, amount = 0, i = 0;

    while(i < n) {
        amount += v[i];
        coins += 1;
        int brother = sum - amount;

        if(amount > brother) break;
        i++;
    }

    cout << coins << endl;

    return 0;
}
