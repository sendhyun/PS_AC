#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int x=0,y=n-1;
    int ans = 2000000010;
    int lo = 0,hi = n-1;
    while (lo<hi)
    {
        int t = arr[lo] + arr[hi];
        if(abs(t)<ans)
        {
            ans = abs(t);
            x = lo;
            y = hi;
        }
        if(t>0)
        {
            hi--;
        }
        else if(t<0)
        {
            lo++;
        }
        else
        {
            x=lo;
            y=hi;
            break;
        }
    }
    cout << arr[x] << " " << arr[y];
}