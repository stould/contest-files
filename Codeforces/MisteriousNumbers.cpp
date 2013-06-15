#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

string a, b;

int main(void) {
    cin >> a >> b;

    reverse(b.begin(), b.end());

    int na = atoi(a.c_str());
    int nb = atoi(b.c_str());

    cout << na + nb << endl;

    return 0;
}
