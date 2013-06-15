#include <iostream>
#include <set>

using namespace std;

int n;

int main(void) {
    cin >> n;
    set<int> s;
    set<int>::iterator it;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp; s.insert(tmp);
    }
    if(s.size() == 1) {
        cout << "NO" << endl;
    } else {
        it = s.begin();
        for(int i = 0; i < 1; i++) it++;
        cout << (*it) << endl;
    }
    return 0;
}
