#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>

using namespace std;

struct Product {
    int first, second;

    Product(int a, int b) { first = a; second = b; }
    Product() { }

    bool operator<(const Product& p) const {
        return first + second < p.first + p.second;
    }
};


int main(void) {
    freopen("10.in", "r", stdin);
    int N, B;

    cin >> N >> B;

    vector<Product> v(N);

    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int buy = 0;
    for(int i = 0; i < N; i++) {
        int normal = v[i].first + v[i].second;
        int special = (v[i].first / 2) + v[i].second;

        if(B - normal >= 0) {
            B -= normal;
            buy += 1;
        } else if(B - special >= 0) {
            B -= special;
            buy += 1;
            break;
        } else {
            break;
        }
    }

    cout << buy << endl;

    return 0;
}
