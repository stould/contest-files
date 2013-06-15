#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n;
char type;
double value;

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n && n > 0) {
        priority_queue<double, vector<double>, greater<double> > venda;
        priority_queue<double, vector<double>, less<double> > compra;
        double profit = 0;
        for(int i = 0; i < n; i++) {
            cin >> type >> value;
            if(type == 'C') {
                compra.push(value);
            } else {
                venda.push(value);
            }
            while(compra.size() > 0 && venda.size() > 0 && compra.top() >= venda.top()) {
                profit += (double) (compra.top() - venda.top());
                compra.pop(); venda.pop();
            }
        }
        printf("%.2f\n", profit);
    }
    return 0;
}
