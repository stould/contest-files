#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>

#define FOR(i, j) for((int)(i); (i) <= (j); i++)

using namespace std;

int main() {
    ifstream read;
    ofstream write;

    vector<int> values;

    string line;
    int i, j, tests, money, items, temp;

    if(read.is_open()) {
        getline(read, line);
        stringstream(line) >> tests;

        for(i = 1; i <= tests; i++) {
            getline(read, line);
            stringstream(line) >> money;

             getline(read, line);
             stringstream(line) >> items;

             for(j = 1; j <= items; j++) {
                getline(read, line);
                stringstream(line) >> temp;
                values.push_back(temp);
            }
            write << "Case #" << i << ": ";
        }
    }
    return 0;
}
