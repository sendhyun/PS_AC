#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int map[101][101];
int len[101][101];
int n,m;
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1}; 
int main(int argc, char const *argv[])
{   
    int i,j;
    char inp;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> inp;
            map[i][j] = inp - '0';
        }
    }
    for(i=0;i<n;i++) fill(len[i],len[i]+m,-1);
    queue<pair<int,int>> Q;
    Q.push({0,0});
    len[0][0] = 1;
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(i=0;i<4;i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(nr<0||nr>=n||nc<0||nc>=m) 
                continue;
            //len이 0이상이므로 이미 방문한 곳
            if(len[nr][nc]>=0||map[nr][nc]!= 1)
                continue;
            len[nr][nc] = len[cur.first][cur.second] + 1;
            Q.push({nr,nc});
        }
    }
    cout<<len[n-1][m-1];
}