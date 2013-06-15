#include <iostream>
#include <vector>

using namespace std;

int x, t, a, b, da, db, ind, sa, sb;

int main(void) {
    cin >> x >> t >> a >> b >> da >> db;
    vector<pair<int, int> > va, vb;
    ind = 0; sa = a; sb = b;
    for(int i = 0; i < t; i++) {
        va.push_back(make_pair(a - da*i, ind));
        vb.push_back(make_pair(b - db*i, ind));
        ind++;
    }
    bool ans = false;
    for(int i = 0; i < va.size(); i++) {
        for(int j = 0; j < vb.size(); j++)  {
            if((va[i].first + vb[j].first == x || va[i].first == x || vb[j].first == x)) {
                ans = true;
                break;
            }
        }
    }
    if(ans || x == 0 || sa == x || sb == x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
