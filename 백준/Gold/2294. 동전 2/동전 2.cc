#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,k;
    int coin[100];
    int dp[10001] = {0,};
    int cnt=10000;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> coin[i];
        if(coin[i]>10000)
        continue;
        dp[coin[i]] = 1;
    }
    for(int i=1;i<=k;i++) // k_val넘어가는 값 필요 X
    {
        int max = 100001; // i를 만들 수 있는 가짓수
        for(int j=0;j<n;j++)
        {
            if(i<coin[j]) continue;
            if(dp[i-coin[j]]<max) max = dp[i-coin[j]]+1;
        }
        dp[i] = max;
    }
    if(dp[k]>100000)
    {
        cout <<"-1";
        return 0;
    }
    cout << dp[k];
}