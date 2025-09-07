#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[505],s[505],dp[505][505];
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i],s[i]=s[i-1]+a[i];

        for(int j=2;j<=n;j++)
        {
            for(int i=j-1;i>=1;i--)
            {
                dp[i][j] = 987654321;
                for(int k=i;k<j;k++) dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
                if(i+1==j) dp[i][j] = 0;
                dp[i][j] +=s[j] - s[i-1]; //구간합 더해주기
            }
        }
        cout << dp[1][n] << "\n";
    }   
}