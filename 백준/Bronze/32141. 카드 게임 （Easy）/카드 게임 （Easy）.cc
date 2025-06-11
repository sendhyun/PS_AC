#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,h;
    cin >> n >> h;
    int arr[n];
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(h<=0) break;
        cin >> arr[i];
        h-=arr[i];
        cnt++;
    }
    if(h>0)
    {
        cout <<"-1";
        return 0;
    }
    cout << cnt;
}