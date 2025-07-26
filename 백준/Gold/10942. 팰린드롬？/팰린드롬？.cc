#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ql[3] = {0,-1,-1};
int qr[3] = {1,0,1};
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    //0-based arr
    int dt[n][n] ={0,};

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        dt[i][i] = 1;
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1]) dt[i][i+1] = 1;
    }

    for(int i=2;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]==arr[i+j]&&dt[j+1][i+j-1]==1) dt[j][j+i] = 1;
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int s,e;
        cin >> s >> e;
        s--; e--;
        cout << ((dt[s][e]==1)? "1":"0") <<"\n";
    }
   /* cout << "\n\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << dt[i][j]<<" ";
        }
        cout << "\n";
    }*/
}