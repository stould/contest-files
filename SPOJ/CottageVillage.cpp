#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
double t;

struct Home {
    int place, radius;

    Home() {}
    Home(double _p, double _r) {
        place = _p;
        radius = _r;
    }

    bool operator<(const Home& h) const {
        return place < h.place;
    }
};

int main(void) {
    cin >> n >> t;
    int ans = 2;
    vector<Home> mem(n);

    for(int i = 0; i < n; i++) {
        cin >> mem[i].place >> mem[i].radius;
    }
    sort(mem.begin(), mem.end());

    for(int i = 0; i < n - 1; i++) {
       double left = (mem[i].place + double(mem[i].radius / 2.0));
       double right = (mem[i + 1].place - double(mem[i + 1].radius / 2.0));
       double dist = (double) (hypot(left - right, 0));
       if(dist > t) ans += 2; else if(dist == t) ans += 1;
    }
    cout << ans << endl;
    return 0;
}
