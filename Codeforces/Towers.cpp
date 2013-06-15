#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> values(N);
    set<int> s;

    for(int i = 0; i < N; i++) {
        cin >> values[i];
        s.insert(values[i]);
    }

    int mx = 1;

    for(int i = 0; i < N; i++) {
        mx = max(mx, count(values.begin(), values.end(), values[i]));
    }

    cout << mx << " " << s.size() << endl;


    return 0;
}
