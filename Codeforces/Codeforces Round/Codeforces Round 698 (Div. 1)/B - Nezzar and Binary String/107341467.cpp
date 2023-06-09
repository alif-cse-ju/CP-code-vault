#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
char s[N],f[N];
int l[N],r[N],tree[4*N],lazy[4*N];
void Clear(int nodeNum,int l,int r)
    tree[nodeNum]=0;
    lazy[nodeNum]=-1;
    if(l < r)
    {
        Clear(2*nodeNum,l,(l+r) >> 1);
        Clear(2*nodeNum+1,((l+r) >> 1)+1,r);
    }
void Update(int nodeNum,int start,int end,int l,int r,int value)
    if(lazy[nodeNum] != -1)
    {
        tree[nodeNum]=(end-start+1)*lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]=lazy[nodeNum];
            lazy[nodeNum*2 + 1]=lazy[nodeNum];
        }
        lazy[nodeNum]=-1;
    }
    if(start > end  ||  start > r  ||  end < l)return;
    if(start >= l  &&  end <= r)
    {
        tree[nodeNum]=(end-start+1)*value;
        if(start != end)
        {
            lazy[nodeNum*2]=value;
            lazy[nodeNum*2 + 1]=value;
        }
        return;
    }
     int mid=(start+end)/2;
    Update(nodeNum*2,start,mid,l,r,value);
    Update(nodeNum*2 + 1,mid+1,end,l,r,value);
     tree[nodeNum]=tree[nodeNum*2] + tree[nodeNum*2 + 1];
}
 int Query(int nodeNum,int start,int end,int l,int r)
{
    if(start > end  ||  start > r  ||  end < l)return 0;
    if(lazy[nodeNum] != -1)
    {
        tree[nodeNum]=(end-start+1)*lazy[nodeNum];
        if(start != end)
        {
            lazy[nodeNum*2]=lazy[nodeNum];
            lazy[nodeNum*2 + 1]=lazy[nodeNum];
        }
        lazy[nodeNum]=-1;
    }
    if(start >= l  &&  end <= r)return tree[nodeNum];
     int mid=(start+end)/2;
    long long ans1=Query(nodeNum*2,start,mid,l,r);
    long long ans2=Query(nodeNum*2 + 1,mid+1,end,l,r);
     return (ans1+ans2);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,n,t,q,x,y;
    cin >> t;
    while(t--)
    {
        flag=1;
        cin >> n >> q >> s+1 >> f+1;
        for(i=1;i<=q;i++)cin >> l[i] >> r[i];
        Clear(1,1,n);
        for(i=1;i<=n;i++)
        {
            if(f[i] == '1')Update(1,1,n,i,i,1);
        }
        for(i=q;i;i--)
        {
            x=Query(1,1,n,l[i],r[i]);
            y=(r[i]-l[i]+1)-x;
            if(x > y)Update(1,1,n,l[i],r[i],1);
            else if(x < y)Update(1,1,n,l[i],r[i],0);
            else flag=0;
        }
        for(i=1;i<=n;i++)
        {
            if(s[i]-'0' != Query(1,1,n,i,i))
            {
                flag=0;
                break;
            }
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//