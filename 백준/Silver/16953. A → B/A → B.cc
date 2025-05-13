#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    long long a,b;
    cin >> a >> b;
    int cnt = 0;
    while (1)
    {
        if(a==b)
        {
            cout << cnt+1;
            break;
        }
        if(b<a)
        {
            cout << "-1"; break;
        }
        if(b%2==0)
        {
            b/=2;
        }  
        else if(b%10==1) 
        {
            b = (b-1)/10;
        }
        else
        {
            cout << "-1"; break;
        }
        cnt++;
    }
}