#include <iostream>
#include <map>

using namespace std;

int n;

map<int, int> mp;

int main(void) {
    cin >> n;
    mp.clear();
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        mp[tmp]++;
    }
    return 0;
}
