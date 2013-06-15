#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef __int64 ll;

vector<ll> memo;
ll temp;

int main(void) {
    while(cin >> temp) memo.push_back(temp);

    reverse(memo.begin(), memo.end());

    for(int i = 0; i < (int) memo.size(); i++) {
        printf("%.4f\n",sqrt(memo[i]));
    }
    return 0;
}
