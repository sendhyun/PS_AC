#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int comp(double a,double b)
{
    return a>b;
}
int main(int argc, char const *argv[])
{
        cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    int p[n],q[n];
    for(int i=0;i<n;i++)
    {
        cin >> p[i] >> q[i];
    }
    double ans =  0.0;
    double lo = 0, hi = 1.0;
    double arr[n];
    while (hi-lo >= 1e-7)
    {
        double mid = (lo + hi)/2;
        for(int i=0;i<n;i++)
        {
            arr[i] = p[i] - mid*q[i];
        }
        sort(arr,arr+n,comp);
        double sum = 0.0;
        for(int i=0;i<k;i++)
        {
            sum +=arr[i];
        }
        if(sum>=0.0)
        {
            ans = max(ans,mid);
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    cout << ans;
    return 0;
}