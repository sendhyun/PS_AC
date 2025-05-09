#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max_len 100004
ll arr[max_len];
ll tree[max_len*4];
ll lazy[max_len*4];

void make(int node,int s,int e)
{
    if(s==e)
    {
        tree[node] = arr[s];
        return;
    }
    else
    {
        int mid = (s+e)/2;
        make(node*2,s,mid);
        make(node*2+1,mid+1,e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void renew(int node,int s,int e)
{
    if(lazy[node]!=0)
    {
        if(lazy[node]&1)
        {
            tree[node] = (e-s+1) - tree[node];
        }
        if(s!=e)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node,int s,int e,int l,int r)
{
    renew(node,s,e);
    if(r<s||l>e) return;
    if(l<=s&&r>=e)
    {              //개수 반전
        tree[node] = (e-s+1) - tree[node];
        if(s!=e)
        {
            lazy[node*2]++; 
            lazy[node*2+1]++;
        }
        return;
    }
    int mid = (s+e)/2;
    update(node*2,s,mid,l,r);
    update(node*2+1,mid+1,e,l,r);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node,int s,int e,int l,int r)
{
    renew(node,s,e);
    if(r<s||l>e) return 0;
    if(l<=s&&r>=e) return tree[node];
    int mid = (s+e)/2;
    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}

int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    make(1,0,n-1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0)
        {
            update(1,0,n-1,b-1,c-1);
        }
        else
        {
            cout << query(1,0,n-1,b-1,c-1) << "\n";
        }
    }
}