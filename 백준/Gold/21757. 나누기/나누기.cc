#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    long long int n;
    cin >> n;   
    long long int arr[n],copy[n];
    long long all = 0;
    long long int cnt = 0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        copy[i] = arr[i];
        all += arr[i];
    }
    all = all/4;
    long long int now = 0;
    long int one=0,two=0,thr=0;
    for(int i=0;i<n;i++)
    {
        now += arr[i];
        if(all == 0) // 모든 인풋이 0일때
        {
            if(now==0)
            {
                cnt++;
            }
        }
        else
        {
            if(now%all==0)
            {
                int dur = now/all;
                //자를 수 있는 구간 nCr x --> 구간별 개수의 곱
                if(dur==1) //p1개수 누적
                {
                    one++;
                }
                else if(dur==2) //p2가 나올 때 마다
                {
                    two+=one;
                }
                else if(dur==3) //p3
                {
                    thr+=two;
                }
                if(now!=0)
                {
                    cnt++;
                }
            }
        }
    }
    if(cnt < 3) cout << "0";
    else
    {
        if(all == 0)
        { //어디서 잘라도 상관 x --> nCr
            //0일때는 6개면 6개가 찍히니 빼고 시작해야함
            cout << (cnt-1)*(cnt-2)*(cnt-3)/6;
        }
        else
        {
            cout << thr;
        }
    }
}