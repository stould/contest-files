#include <iostream>
#include <map>

using namespace std;

const int MAXN = 100007;
int i, tmp, n, mx = -1, index = 0;

int main(void) {
    ios::sync_with_stdio(false);
    map<int, int> m;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> tmp;
        m[tmp] += 1;
        if(m[tmp] > mx) {
            mx = m[tmp]; index = tmp;
        }
    }
    cout << index << endl;
    return 0;
}
