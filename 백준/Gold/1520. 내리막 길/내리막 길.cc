#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int arr[500][500];
int dp[500][500];
int dfs(int r,int c)
{
    if(r==n-1&&c==m-1) return 1;
    if(dp[r][c]!=-1) return dp[r][c]; //방문했다면
    dp[r][c] = 0;
    for(int i=0;i<4;i++)
    {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr<n&&nr>=0&&nc<m&&nc>=0)
        {
            if(arr[nr][nc]<arr[r][c])
            {
                dp[r][c] += dfs(nr,nc);
            }
        }
    }
    return dp[r][c];
}
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0,0);
}