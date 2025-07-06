#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    long long int arr[1000020] ={0,};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<n+10;i++)
    {   
        arr[i] = (arr[i-1] + arr[i-2])%15746;
    }
    cout << arr[n];
    return 0;
}
/*
0 1 2 3 4
1 1 2 3 5
*/