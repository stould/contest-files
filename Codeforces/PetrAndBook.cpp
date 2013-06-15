#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int N;
    vector<int> days(7);

    scanf("%d", &N);

    for(int i = 0; i < 7; i++) scanf("%d", &days[i]);

    int stop_day, i = 0;
    while(N > 0) {
        if(i == 7) { i = 0; }
        N -= days[i];
        if(N <= 0) {
            stop_day = i + 1;
            break;
        }
        i++;
    }
    printf("%d\n", stop_day);
    return 0;
}
