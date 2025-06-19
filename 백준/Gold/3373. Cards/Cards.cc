#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< tuple<int,int,int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        //큰거 작은거 앞뒤 선택시 효용 판단을 위한 변수
        int big = max(a,b);
        int sma = min(a,b);
        int val = big + sma;
        v.push_back({big,sma,val});
    }
    sort(v.begin(),v.end(),
    [](tuple<int,int,int> a, tuple<int,int,int> b)
    {
        return get<2>(a) > get<2>(b);
    });
    long long sum = 0;
    for(int i=0;i<n/2;i++) sum -= get<0>(v[i]);
    for(int i=n/2;i<n;i++) sum += get<1>(v[i]);
    cout << sum;
}