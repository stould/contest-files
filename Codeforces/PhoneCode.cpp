#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

int i, n;
vector<string> nums;

int main(void) {
    cin >> n;
    nums.resize(n);
    for(i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int base = 0;
    while(1) {
        set<char> s;
        for(i = 0; i < n; i++) {
            s.insert(nums[i][base]);
        }
        if(s.size() != 1) break;
        base += 1;
    }
    cout << base << endl;
    return 0;
}

