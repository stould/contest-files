#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Triangle {
    int a, b, c;

    Triangle() { }
    Triangle(int _a, int _b, int _c) {
        a = _a; b = _b; c = _c;
    }

    bool operator== (const Triangle& t) const {
        return (a == t.a && b == t.b && c == t.c);
    }
};

int i, j, k, N;

vector<Triangle> v;
vector<ll> values;

int main(void) {
    while(1) {
        cin >> N;
        v.clear();
        values.clear();

        Triangle t;
        for(i = 0; i < N; i++) {
            cin >> values[i];
        }

        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                for(k = 0; k < N; k++) {
                    if(i != j && j != k && i != k) {
                        int low = min(values[i], min(values[j], values[k]));
                        int high = max(values[i], max(values[j], values[k]));
                        int mid = (high == values[i] ? max(values[j], values[k]) : high == values[j] ? max(values[i], values[k]) : values[k]);

                        t = Triangle(low, mid, high);

                        if(low + mid < high && count(values.begin(), values.end(), t) == 0) {
                            v.push_back(t);
                        }
                    }
                }
            }
        }
        cout << v.size() << endl;
    }
    return 0;
}
