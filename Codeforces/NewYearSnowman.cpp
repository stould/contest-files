#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

struct Snow {
    int a, b, c;
    Snow(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};

int main() {
    int N;
    scanf("%d", &N);

    vector<int> v(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    vector<bool> memo(N);
    fill(memo.begin(), memo.end(), false);


    vector<Snow> balls;
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        int _a = v[i], _b = -1, _c = -1;
        bool hp = false;
        if(!memo[i]) {
            memo[i] = true;
            bool oka = false, okb = false;;
            for(int j = 0; j < v.size(); j++) {
                if(!oka && !memo[j] && v[j] > _a) {
                    memo[j] = true;
                    _b = v[j];
                    oka = true;
                }
                if(!okb && oka && !memo[j] && v[j] > _a && v[j] > _b) {
                    memo[j] = true;
                    _c = v[j];
                    okb = true;
                }
                if(oka && okb) {
                    break;
                }
            }
            if(_b == -1 || _c == -1) {
                memo[i] = false;
                break;
            } else {
                hp = true;
                balls.push_back(Snow(_c, _b, _a));
            }
        }
    }

    cout << balls.size() << endl;

    for(int i = 0; i < balls.size(); i++) {
        cout << balls[i].a << " " << balls[i].b << " " << balls[i].c << endl;
    }
    return 0;
}
