#include<bits/stdc++.h>
 using namespace std;
 const int N=2e5+5;
 long long a[N],lazy[4*N],segTree[4*N];
 void Propagate(int n)
{
    int i,l=2*n,r=l+1;
    lazy[l]+=lazy[n],lazy[r]+=lazy[n];
    segTree[l]+=lazy[n],segTree[r]+=lazy[n];
    lazy[n]=0;
}
 void Build(int n,int s,int e)
{
    lazy[n]=0;
    if(s == e)
    {
        segTree[n]=a[s];
        return;
    }
    int l=2*n,r=l+1,mid=(s+e) >> 1;
    Build(l,s,mid);
    Build(r,mid+1,e);
    segTree[n]=min(segTree[l],segTree[r]);
}
 void Update(int n,int s,int e,int l,int r,int val)
{
    if(s >= l  &&  e <= r)
    {
        lazy[n]+=val;
        segTree[n]+=val;
        return;
    }
    if(s > r  ||  e < l)return;
    if(lazy[n])Propagate(n);
    int lc=2*n,rc=lc+1,mid=(s+e) >> 1;
    Update(lc,s,mid,l,r,val);
    Update(rc,mid+1,e,l,r,val);
    segTree[n]=min(segTree[lc],segTree[rc]);
}
 long long Query(int n,int s,int e,int l,int r)
{
    if(s >= l  &&  e <= r)return segTree[n];
    if(s > r  ||  e < l)return 1e18;
    if(lazy[n])Propagate(n);
    int lc=2*n,rc=lc+1,mid=(s+e) >> 1;
    return min(Query(lc,s,mid,l,r),Query(rc,mid+1,e,l,r));
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,m,n,r,x;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    Build(1,1,n);
    cin >> m;
    cin.ignore();
    while(m--)
    {
        getline(cin,s);
        vector<int>v;
        stringstream ss(s);
        while(ss >> x)v.emplace_back(x);
        if(v.size() == 2)
        {
            l=v[0]+1,r=v[1]+1;
            if(l <= r)cout << Query(1,1,n,l,r) << '\n';
            else cout << min(Query(1,1,n,l,n),Query(1,1,n,1,r)) << '\n';
        }
        else
        {
            l=v[0]+1,r=v[1]+1,x=v[2];
            if(l <= r)Update(1,1,n,l,r,x);
            else
            {
                Update(1,1,n,l,n,x);
                Update(1,1,n,1,r,x);
            }
        }
    }
    return 0;
}