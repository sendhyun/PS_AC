#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    while(1)
    {
        x++;
        if(x>=10000)
        {
            cout << "-1";
            break;
        }
        int fir = x/100,sec = x%100;
        if(x == pow((fir+sec),2))
        {
            cout << x;
            break;
        }
    }
    return 0;
}