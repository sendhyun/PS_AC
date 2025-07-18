#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr['z'-'a'+1];
    while (1)
    {  //32
        //65 97
        int cnt=0;
        char tg;
        cin >> tg;
        char inp[300];
        scanf("%[^\n]s",inp);
        for(int i=0;i<strlen(inp);i++)
        {
            if(inp[i]==tg||inp[i]==(char)(tg-32))
            cnt++;
        }
        if(tg=='#')
        {
            break;
        }
        cout << tg <<" " << cnt <<"\n";
        cnt=0;
    }
}