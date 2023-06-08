#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2e5+5;
ll sumF[2][M],sumR[2][M];
int n,a[M],fSub[M],rSub[M];
void UpdateF(int num,int idx,ll val)
    while(idx <= n)
    {
        sumF[num][idx]+=val;
        idx+=idx & (-idx);
    }
ll QueryF(int num,int idx)
    ll ans=0;
    while(idx)
    {
        ans+=sumF[num][idx];
        idx-=idx & (-idx);
    }
    return ans;
void RangeUpdateF(int l,int r,ll val)
    UpdateF(0,l,val);
    UpdateF(0,r+1,-val);
    UpdateF(1,l,val*(l-1));
    UpdateF(1,r+1,-val*r);
ll PrefixSumF(int idx)
{
    return QueryF(0,idx)*idx-QueryF(1,idx);
}
 ll RangeQueryF(int l,int r)
{
    return PrefixSumF(r)-PrefixSumF(l-1);
}
 void UpdateR(int num,int idx,ll val)
{
    while(idx <= n)
    {
        sumR[num][idx]+=val;
        idx+=idx & (-idx);
    }
}
 ll QueryR(int num,int idx)
{
    ll ans=0;
    while(idx)
    {
        ans+=sumR[num][idx];
        idx-=idx & (-idx);
    }
    return ans;
}
 void RangeUpdateR(int l,int r,ll val)
{
    UpdateR(0,l,val);
    UpdateR(0,r+1,-val);
    UpdateR(1,l,val*(l-1));
    UpdateR(1,r+1,-val*r);
}
 ll PrefixSumR(int idx)
{
    return QueryR(0,idx)*idx-QueryR(1,idx);
}
 ll RangeQueryR(int l,int r)
{
    return PrefixSumR(r)-PrefixSumR(l-1);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tmp1,tmp2;
    int i,q,t,x,y;
    cin >> n >> q;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=n;i;i--)
    {
        fSub[i]=1;
        if(a[i] <= a[i+1])fSub[i]+=fSub[i+1];
        RangeUpdateF(i,i,fSub[i]);
    }
    for(i=1;i<=n;i++)
    {
        rSub[i]=1;
        if(a[i] >= a[i-1])rSub[i]+=rSub[i-1];
        RangeUpdateR(i,i,rSub[i]);
    }
    while(q--)
    {
        cin >> t >> x >> y;
        if(t == 2)
        {
            if(y == n  ||  a[y] > a[y+1])cout << RangeQueryF(x,y) << '\n';
            else if(x == 1  ||  a[x-1] > a[x])cout << RangeQueryR(x,y) << '\n';
            else
            {
                tmp1=RangeQueryF(y+1,y+1);
                tmp2=RangeQueryR(y,y);
                RangeUpdateF(y-tmp2+1,y,-tmp1);
                cout << RangeQueryF(x,y) << '\n';
                RangeUpdateF(y-tmp2+1,y,tmp1);
            }
        }
        else
        {
            tmp1=RangeQueryR(x,x);
            tmp2=RangeQueryF(x,x);
            RangeUpdateF(x-tmp1+1,x,-tmp2);
            RangeUpdateR(x,x+tmp2-1,-tmp1);
            a[x]=y;
            if(x > 1)tmp1=RangeQueryR(x-1,x-1);
            if(x < n)tmp2=RangeQueryF(x+1,x+1);
            if(x > 1  &&  a[x] >= a[x-1])RangeUpdateR(x,x,tmp1+1);
            else RangeUpdateR(x,x,1);
            if(x < n  &&  a[x] <= a[x+1])RangeUpdateF(x,x,tmp2+1);
            else RangeUpdateF(x,x,1);
            if(x < n  &&  a[x+1] >= a[x])RangeUpdateR(x+1,x+RangeQueryF(x+1,x+1),RangeQueryR(x,x));
            if(x > 1  &&  a[x-1] <= a[x])RangeUpdateF(x-RangeQueryR(x-1,x-1),x-1,RangeQueryF(x,x));
        }
    }
    return 0;
}