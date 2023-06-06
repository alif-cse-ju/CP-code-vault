#include<bits/stdc++.h>

using namespace std;

const int N=(1 << 16)+5;
const int mod=1e9+7;

int a[N],idx[4*N],node[4*N];

void Build(int nodeNum,int l,int r)
{
    if(l == r)
    {
        idx[nodeNum]=l;
        node[nodeNum]=a[l];
        return;
    }

    int mid=(l+r) >> 1;
    Build(2*nodeNum,l,mid);
    Build(2*nodeNum+1,mid+1,r);
    if(node[2*nodeNum] < node[2*nodeNum+1])
    {
        idx[nodeNum]=idx[2*nodeNum+1];
        node[nodeNum]=node[2*nodeNum+1];
    }
    else
    {
        idx[nodeNum]=idx[2*nodeNum];
        node[nodeNum]=node[2*nodeNum];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    cin >> n;
    for(i=1;i<=(1 << n);i++)cin >> a[i];
    Build(1,1,(1 << n));
    cout << idx[2]+idx[3]-idx[1];
    return 0;
}