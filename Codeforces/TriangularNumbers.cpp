#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vp;

int main(void) {
    for(int i = 1; i <= 500; i++) vp.push_back((int)(i*(i + 1))/2);
    cin >> n;
    if(binary_search(vp.begin(), vp.end(),n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
