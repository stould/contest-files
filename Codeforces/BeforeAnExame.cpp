#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d, sumTime, lbound = 0, hbound = 0;
vector<pair<int, int> > ranges;

int main(void) {
    cin >> d >> sumTime;

    for(int i = 0; i < d; i++) {
        int low, high;
        cin >> low >> high;
        ranges.push_back(make_pair(low, high));
        lbound += low;
        hbound += high;
    }
    if(!(lbound <= sumTime && hbound >= sumTime)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> ans;
        int tsum = 0;
        for(int i = 0; i < d; i++) {
            int tmp = (int) (ranges[i].first + ranges[i].second) / 2;
            tsum += tmp;
            ans.push_back(tmp);
        }
        while(tsum > sumTime) {
            for(int i = 0; i < d; i++) {
                if(ans[i] > ranges[i].first) {
                    ans[i] -= 1;
                    tsum -= 1;
                    break;
                }
            }
        }
        while(tsum < sumTime) {
            for(int i = 0; i < d; i++) {
                if(ans[i] < ranges[i].second) {
                    ans[i] += 1;
                    tsum += 1;
                    break;
                }
            }
        }
        for(int i = 0; i < d; i++) {
            if(i == d - 1) {
                cout << ans[i] << endl;
            } else {
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}
