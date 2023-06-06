#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

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

int a[M],b[M],m,n,sum[M];

void Update(int i,int v)
{
    while(i <= m)sum[i]+=v, i+=(i & -i);
}

int Query(int i)
{
    int ans=0;
    while(i)ans+=sum[i], i-=(i & -i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
        if(a[i] > b[i])swap(a[i], b[i]);
    }
    ordered_set<pair<int,int>>ost;
    for(int i=1;i<=n;i++)ost.insert({a[i],i});
    for(int i=1;i<=m;i++)
    {
        if((int)ost.size() < n)break;
        auto [y,v]=*(--ost.end());
        Update(y-i+1, 1), Update(m-i+2, -1);
        while(!ost.empty())
        {
            auto [in,id]=*(ost.begin());
            if(in > i)break;
            ost.erase(ost.begin());
            if(in < b[id])ost.insert({b[id],id});
        }
    }
    for(int i=1;i<=m;i++)cout << Query(i) << ' ';
    return 0;
}
