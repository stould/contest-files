#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int INF = 1 << 30;

struct Couple {
    int i;
    int j;

    Couple(int _i, int _j) {
        i = _i;
        j = _j;
    }

    bool operator<(const Couple& c) const {
        return i < c.i;
    }
};

int main() {
    int i, j, n, ct = 0;
    scanf("%d\n", &n);

    vector<bool> memo(n);
    vector<char> sex(n);
    vector<int> skill(n);
    vector<Couple> used;

    fill(memo.begin(), memo.end(), false);
    for(i = 0; i < n; i++) scanf("%c", &sex[i]);
    for(i = 0; i < n; i++) scanf("%d", &skill[i]);

    for(i = 0; i < n; i++) {
        int index = -1, minv = INF;
        for(j = i + 1; j < n; j++) {
            if(sex[i] != sex[j] && abs(skill[i] - skill[j] < minv) && !memo[i] && !memo[j]) {
                minv = abs(skill[i] - skill[j]);
                index = j;
                break;
            }
        }
        for(j = i - 1; j >= 0; j--) {
            if(sex[i] != sex[j] && abs(skill[i] - skill[j]) < minv && !memo[i] && !memo[j]) {
                minv = abs(skill[i] - skill[j]);
                index = j;
                break;
            }
        }
        if(index == -1) {
            break;
        } else {
            ct++;
            memo[i] = memo[index] = true;
            used.push_back(Couple(i + 1, index  + 1));
        }
    }

    sort(used.begin(), used.end());

    printf("%d\n", ct);

    for(i = 0; i < used.size(); i++) {
        printf("%d %d\n", used[i].i, used[i].j);
    }
    return 0;
}
