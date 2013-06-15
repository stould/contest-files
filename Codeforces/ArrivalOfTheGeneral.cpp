#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int i, mini = 1000000, maxi = -1, min_in, max_in, N;

#define REP(i, n) for(i = 0; i < (n); i++)

int main() {
    cin >> N;

    vector<int> v(N);

    REP(i, N) {
        cin >> v[i];
        if(v[i] > maxi) {
            maxi = v[i];
            max_in = i;
        }
    }

    int steps = 0;

    while(v[0] != maxi) {
        swap(v[max_in], v[max_in - 1]);
        max_in--;
        steps++;
    }

    REP(i, N) {
       if(v[i] <= mini) {
            mini = v[i];
            min_in = i;
        }
    }
    while(v[N - 1] != mini) {
        swap(v[min_in + 1], v[min_in]);
        min_in++;
        steps++;
    }
    cout << steps << endl;
    return 0;
}
