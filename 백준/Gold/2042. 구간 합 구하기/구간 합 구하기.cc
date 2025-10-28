#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define dis 1000001
typedef long long ll;

ll inp[dis];
ll tree[4000004];

ll make(int node,int start,int end)
{
    if(start == end)
    {
        return tree[node] = inp[start];
    }
    else
    {
        int mid = (start+end)/2;
        return tree[node] = make(node*2,start,mid) + make(node*2+1,mid+1,end);
    }
}

ll query(int node,int start,int end,int l,int r)
{
    if(r<start||l>end) return 0; //해당 범위가 없다.
    if(l<=start&&r>=end) return tree[node]; //구간합 범위 안에 해당 노드가 완전히 포함된다.
    int mid = (start+end)/2;
    return query(node*2,start,mid,l,r) + query(node*2+1,mid+1,end,l,r);
    //노드를 위에서부터 탐색한다
    //노드가 쿼리를 완전히 품지 X라면 쪼개서 탐색한다.
    //노드의 두 자식 노드는 각각 노드번호*2 노드번호*2+1이다
    //ㄴ증명은 어떻게 할까?
}

void update(int node,int start,int end,int idx,ll val)
{
    if(idx<start||end<idx) return;
    tree[node] += val;
    if(start==end) return; //리프노드라면
    int mid = (start+end)/2;
    update(node*2,start,mid,idx,val);
    update(node*2+1,mid+1,end,idx,val);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,exc,sum;
    cin >> n >> exc >> sum;
    for(int i=0;i<n;i++)
        cin >> inp[i];
    make(1,0,n-1);
    for(int i=0;i<exc+sum;i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        //1은 업데이트,2는 쿼리
        if(a==1)
        {
            ll dif = c - inp[b-1];
            inp[b-1] = c;
            update(1,0,n-1,b-1,dif);
        }
        else
            //cout <<"print:"<< query(1,0,n-1,b-1,c-1) << "\n";
            cout << query(1,0,n-1,b-1,c-1) << "\n";
    }
    return 0;
}