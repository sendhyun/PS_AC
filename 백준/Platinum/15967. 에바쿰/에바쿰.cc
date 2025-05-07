#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max_len 1000004
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
        tree[node] += (e-s+1)*lazy[node]; //관할 범위개 만큼 넣어줌
        if(s!=e)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int node,int s,int e,int l,int r,ll val)
{
    renew(node,s,e);
    if(r<s||l>e) return;
    if(l<=s&&r>=e)
    {
        tree[node] += (e-s+1)*val;
        if(s!=e)
        {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (s+e)/2;
    update(node*2,s,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll query(int node,int s,int e,int l,int r)
{
    renew(node,s,e);
    if(r<s||l>e) return 0;
    if(l<=s&&r>=e) return tree[node];
    int mid = (s+e)/2;
    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r); //값을 변형시키면 안됨됨
}

int main(int argc, char const *argv[])
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,q1,q2;
    cin >> n >> q1 >> q2;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    make(1,0,n-1);
    int a,b,c;
    for(int i=0;i<q1+q2;i++)
    {
        cin >> a >> b >> c;
        if(a==1)
        {
            cout << query(1,0,n-1,b-1,c-1) << "\n";
        }
        else
        {
            ll d;
            cin >> d;
            update(1,0,n-1,b-1,c-1,d);
        }
    }
}