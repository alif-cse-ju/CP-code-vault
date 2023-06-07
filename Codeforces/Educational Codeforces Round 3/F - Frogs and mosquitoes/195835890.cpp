#pragma GCC optimize("Ofast")

#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int X[M];
ll curSz[M],segtree[4*M];

void Build(int n,int l,int r)
{
    if(l == r)
    {
        segtree[n]=curSz[l]+X[l];
        return;
    }
    int m=(l+r) >> 1;
    Build(2*n,l,m), Build(2*n+1,m+1,r);
    segtree[n]=max(segtree[2*n], segtree[2*n+1]);
}

void Update(int n,int s,int e,int i,ll v)
{
    if(s == e)
    {
        segtree[n]=v;
        return;
    }
    int m=(s+e) >> 1;
    if(i <= m)Update(2*n,s,m,i,v);
    else Update(2*n+1,m+1,e,i,v);
    segtree[n]=max(segtree[2*n], segtree[2*n+1]);
}

int Query(int n,int s,int e,ll v)
{
    if(s == e)return s;
    int m=(s+e) >> 1;
    if(segtree[2*n] >= v)return Query(2*n,s,m,v);
    return Query(2*n+1,m+1,e,v);
}

ll ans[M];
int cnt[M],id[M];
tuple<int,int,int>bang[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        int x,t;cin >> x >> t;
        bang[i]=make_tuple(x,x+t,i);
    }
    sort(bang+1,bang+n+1);
    for(int i=1;i<=n;i++)
    {
        auto [x,t,j]=bang[i];
        curSz[i]=t-x, id[i]=j, X[i]=x;
    }
    Build(1,1,n);
    ordered_set<pair<ll,ll>>ost;
    while(m--)
    {
        ll p,b;cin >> p >> b;
        if(segtree[1] < p)ost.insert({p,b});
        else
        {
            int bangKhabe=Query(1,1,n,p);
            if(X[bangKhabe] > p)ost.insert({p,b});
            else
            {
                ++cnt[id[bangKhabe]], curSz[bangKhabe]+=b;
                while(1)
                {
                    int i=ost.order_of_key({X[bangKhabe], -1});
                    if(i == (int)ost.size())break;
                    else
                    {
                        auto tmp=*ost.find_by_order(i);
                        if(tmp.first > X[bangKhabe]+curSz[bangKhabe])break;
                        ++cnt[id[bangKhabe]], curSz[bangKhabe]+=tmp.second;
                        ost.erase(ost.find_by_order(i));
                    }
                }
                Update(1,1,n,bangKhabe,curSz[bangKhabe]+X[bangKhabe]);
            }
        }
    }
    for(int i=1;i<=n;i++)ans[id[i]]=curSz[i];
    for(int i=1;i<=n;i++)cout << cnt[i] << ' ' << ans[i] << '\n';
    return 0;
}
