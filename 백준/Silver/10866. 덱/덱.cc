#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    deque<int> data;
    int t;
    char ord[11];
    cin >> t;
    for(int i =0;i<t;i++)
    {
        int x;
        cin >> ord;
        if(strcmp(ord,"push_front")==0)
        {
            cin >> x;
            data.push_front(x);
        }
        else if(strcmp(ord,"push_back")==0)
        {
            cin >> x;
            data.push_back(x);
        }
        else if(strcmp(ord,"pop_front")==0)
        {
            if(data.empty() == true)
            {
                cout << "-1\n";
            }
            else
            {
                cout << data.front()<<"\n";
                data.pop_front();
            }
        }
        else if(strcmp(ord,"pop_back")==0)
        {
            if(data.empty() == true)
            {
                cout << "-1\n";
            }
            else
            {
                cout << data.back()<<"\n";
                data.pop_back();
            }
        }
        else if(strcmp(ord,"size")==0)
        {
            cout << data.size()<<"\n";
        }
        else if(strcmp(ord,"empty")==0)
        {
            if(data.empty() == true)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if(strcmp(ord,"front")==0)
        {
            if(data.empty() == true)
            {
                cout << "-1\n";
            }
            else
            {
                cout << data.front()<<"\n";
            }
        }
        else if(strcmp(ord,"back")==0)
        {
            if(data.empty() == true)
            {
                cout << "-1\n";
            }
            else
            {
                cout << data.back()<<"\n";
            }
        }
    }
}