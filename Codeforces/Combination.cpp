#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Card {
    int a, b;
    Card() {}
    Card(int _a, int _b) {
        a = _a;
        b = _b;
    }
    bool operator<(const Card& c) const {
        if(a > c.a && b > c.b) {
            return true;
        } else {
            if(b == c.b) {
                if(a > c.a) {
                    return true;
                }
            }
            if(b > c.b) return true;
        }
        return false;
    }
};

vector<Card> v;

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int ta, tb;
        cin >> ta >> tb;
        v.push_back(Card(ta, tb));
    }
    sort(v.begin(), v.end());
    int c = 1, pivot = 0, points = 0;
    while(c > 0 && pivot < n) {
        c -= 1;
        points += v[pivot].a;
        c += v[pivot].b;
        pivot++;
    }
    cout << points << endl;
    return 0;
}
