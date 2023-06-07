#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi pair<int,int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update>
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>
#define pi3 pair<int, pi>
#define p4 pair<pi, pi>
const int MX=600000+10;
const ll mod=1e9+7;
map<ll, int>mp;
set<ll>st;
set<ll>::iterator it;
ll type[MX], l[MX], r[MX], N;
int T[4*MX], lazy[4*MX], flip[4*MX];
ll mp2[MX];
void propagate(int p, int l, int h)
{
    if(lazy[p]!=-1) // if the lattest update is lazy operation than we just calculate the lazy value of the current vertex, there will be no use of flip operation
    {
        T[p]=(h-l+1)*lazy[p];
        if(l!=h)
        {
            lazy[2*p]=lazy[2*p+1]=lazy[p];
            flip[2*p]=flip[2*p+1]=0;
        }
        lazy[p]=-1;
    }
    if(flip[p])  // if the lattest update is flip operation than we first calculate the lazy value than we will calculate the flip operation of the current vertex
    {
        T[p]=(h-l+1)-T[p];
        if(l!=h)
        {
            flip[2*p]^=1, flip[2*p+1]^=1;
        }
        flip[p]=0;
    }
}
 void up(int p, int l, int h, int x, int y, int val)
{
    propagate(p, l, h);
    if(l>y || h<x) return;
     int mid=(l+h)/2;
     if(l>=x && h<=y)
    {
        if(val!=2)      lazy[p]=val, flip[p]=0;
        else            flip[p]^=1;
        propagate(p, l, h);
        return;
    }
     up(2*p, l, mid, x, y, val);
    up(2*p+1, mid+1, h, x, y, val);
    T[p]=T[2*p]+T[2*p+1];
}
 int Q(int p, int l, int h)
{
    if(l==h) return l;
     propagate(p, l, h);
     int mid=(l+h)/2;
    propagate(2*p, l, mid);
    propagate(2*p+1, mid+1, h);
     if(T[2*p]>=1) return Q(2*p, l, mid);
    else          return Q(2*p+1, mid+1, h);
}
 int main()
{
    FasterIO;
     mem(lazy, -1);
     int n; cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>type[i]>>l[i]>>r[i];
        st.insert(l[i]), st.insert(r[i]), st.insert(l[i]+1), st.insert(r[i]+1);
        if(l[i]-1!=0) st.insert(l[i]-1);
        if(r[i]-1!=0) st.insert(r[i]-1);
    }
     st.insert(1);
    for(it=st.begin(); it!=st.end(); it++)  mp[*it]=++N, mp2[N]=*it;
     up(1, 1, N, 1, N, 1);
     for(int i=1; i<=n; i++)
    {
        if(type[i]==1)      up(1, 1, N, mp[l[i]], mp[r[i]], 0);
        else if(type[i]==2) up(1, 1, N, mp[l[i]], mp[r[i]], 1);
        else                up(1, 1, N, mp[l[i]], mp[r[i]], 2);
         int id=Q(1, 1, N);
        cout<<mp2[id]<<'\n';
    }
    return 0;
}