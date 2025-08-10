#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int arr[n][n];
    int dp[n][n][3];
    //0:right 1:daegak 2:down
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
            dp[i][j][0] = 0;dp[i][j][1] = 0;dp[i][j][2] = 0;
        }
    }
    dp[0][1][0] = 1;
    for(int r=0;r<n;r++)
    {
        for(int c=1;c<n;c++)
        {
            if(arr[r][c+1]==0&&arr[r+1][c+1]==0&&arr[r+1][c]==0)
            {
                dp[r][c+1][0] += dp[r][c][0] + dp[r][c][1];
                dp[r+1][c+1][1] += dp[r][c][0] + dp[r][c][1] + dp[r][c][2];
                dp[r+1][c][2] += dp[r][c][1] + dp[r][c][2];
                continue;
            }
            if(arr[r][c+1]==0)
            {
                dp[r][c+1][0] += dp[r][c][0] + dp[r][c][1];
            }
            if(arr[r+1][c]==0)
            {
                dp[r+1][c][2] += dp[r][c][1] + dp[r][c][2];
            }
        }
    }
    cout << dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
}