#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, num = 0;

int fat(int x) {
    if(x <= 1) return 1;
    return x * fat(x - 1);
}

int main(void) {
    ifstream is("i.in");
    ofstream os("o.out");

    is >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++) v.push_back(i);

    os << fat(n) << "\n";

    do {
        for(int i = 0; i < n; i++) {
            os << v[i] << " ";
        }
        os << "\n";
    } while(next_permutation(v.begin(), v.end()));

    os.close();
    return 0;
}

