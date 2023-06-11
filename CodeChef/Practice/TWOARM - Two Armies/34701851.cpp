#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
long long val1[200002],val2[200002];
int m,n,cnt1[200002],cnt2[200002];
void Update1(int idx,int val)
{
    while(idx <= n)
    {
        cnt1[idx]+=val;
        idx+=idx & (-idx);
    }
}
void Update2(int idx,int val)
{
    while(idx <= m)
    {
        cnt2[idx]+=val;
        idx+=idx & (-idx);
    }
}
int Query1(int idx)
{
    int ans=0;
    while(idx > 0)
    {
        ans+=cnt1[idx];
        idx-=idx & (-idx);
    }
    return ans;
}
int Query2(int idx)
{
    int ans=0;
    while(idx > 0)
    {
        ans+=cnt2[idx];
        idx-=idx & (-idx);
    }
    return ans;
}
int main()
{
    FAST();
    int i,q,k,pos,x1,y1,x2,y2;
    cin >> n >> m >> q;
    for(i=1;i<=n;i++)cin >> val1[i];
    for(i=1;i<=m;i++)cin >> val2[i];
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> k >> pos;
        if(k == 1)
        {
            Update1(x1,1),Update2(x2,-1);
            Update1(y1+1,-1),Update2(y2+1,1);
            cout << (Query1(pos)+1)*val1[pos] << '\n';
        }
        else
        {
            Update1(x1,-1),Update2(x2,1);
            Update1(y1+1,1),Update2(y2+1,-1);
            cout << (Query2(pos)+1)*val2[pos] << '\n';
        }
    }
    return 0;
}