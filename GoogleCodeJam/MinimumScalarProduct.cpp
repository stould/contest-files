#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);

    int i, x, n, t, z, temp;
    string buff;

    vector<long long> v1, v2;

    scanf("%d", &t);

    for(z = 1; z <= t; z++) {
        cin >> n;
        getline(cin, buff);
        getline(cin, buff);
        istringstream ss(buff);
        buff.clear();

        for(i = 0; i < n; i++) {
            ss >> temp;
            v1.push_back(temp);
        }

        getline(cin, buff);
        istringstream sss(buff);
        buff.clear();

        for(i = 0; i < n; i++) {
            sss >> temp;
            v2.push_back(temp);
        }
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());

        long long sum = 0;

        for(i = 0; i < v1.size(); i++) {
            sum += (long long) (v1[i] * v2[i]);
        }

        cout << "Case #" << z << ": " << sum << endl;

        v1.clear();
        v2.clear();
    }
    return 0;
}
