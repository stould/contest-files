#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, d, a, b, xi, yi;

struct client {
    int index, low, high;

    client() {}
    client(int _index, int _low, int _high) {
        index = _index;
        low = _low;
        high = _high;
    }
};

bool cmp(client ca, client cb) {
    int ta = (ca.low * a) + (ca.high * b);
    int tb = (cb.low * a) + (cb.high * b);
    return ta < tb;
}


int main(void) {
    cin >> n >> d;
    vector<client> v(n);
    cin >> a >> b;

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        cin >> v[i].low >> v[i].high; v[i].index = i + 1;
    }
    sort(v.begin(), v.end(), cmp);
    int i = 0;
    while(d > 0 && i < v.size()) {
        int low = v[i].low * a;
        int high = v[i].high * b;

        if(d - (low + high) >= 0) {
            d -= (low + high);
            ans.push_back(v[i].index);
        }
        i++;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

