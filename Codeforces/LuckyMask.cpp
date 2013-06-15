#include <iostream>
#include <vector>

using namespace std;

vector<int> base, cmp;

int main(void) {
    int N, M;

    cin >> N >> M;

    while(M > 0) {
        if(M % 10 == 7) base.push_back(7);
        if(M % 10 == 4) base.push_back(4);
        M /= 10;
    }

    for(int i = N + 1; ;i++) {
        int t = i;
        int s = 0, f = 0;
        cmp.clear();
        while(t > 0) {
            if(t % 10 == 4) cmp.push_back(4);
            if(t % 10 == 7) cmp.push_back(7);
            t /= 10;
        }
        if(base == cmp) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
