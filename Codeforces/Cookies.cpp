#include <iostream>
#include <vector>

using namespace std;

int main() {
    int bags, temp, cook = 0, ways = 0;
    vector<int> b;

    cin >> bags;

    while(bags > 0) {
        cin >> temp;
        cook += temp;
        b.push_back(temp);
        bags--;
    }

    for(int i = 0; i < b.size(); i++) {
        if((cook - b[i]) % 2 == 0) { ways++; }
    }

    cout << ways << endl;
    return 0;
}
