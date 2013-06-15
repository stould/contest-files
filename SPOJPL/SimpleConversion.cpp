#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int i, x;
long long  num,r,s,real_value,remm;
string n;
string answer;
string temp;

int main()
{
    freopen("i.in", "r", stdin);
    cin >> num;
    for(int x = 0; x < num; x++)
    {
        cin >> n >> r >> s;
        string answer;
        long long sum = 0;
        int power = 0;

        for(i = n.size() - 1; i >= 0; i -= 1)
        {
            if(n[i]>=65&&n[i]<=90)
            {
                real_value = static_cast<int>(n[i])-55;
            }
            else
            {
                real_value = static_cast<int>(n[i])-48;
            }
            sum = static_cast<int>(sum + real_value*pow(r*1.0,power));
            power++;
        }
        while(sum != 0)
        {
            remm = sum % s;
            sum = sum / s;
            if(remm<10)
            {
                temp = static_cast<char>(remm+48);
            }
            else
            {
                temp = static_cast<char>(remm+55);
            }
            answer = answer + temp;
        }
        for(i = answer.length()-1; i>=0; i -= 1) {
            cout << answer[i];
        }
        cout << endl;
    }
    return 0;
}
