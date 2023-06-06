#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

vector<ll>v;
ordered_set<ll>ost;

void PreCal(vector<ll>&vv,bool idx)
{
    ll sum;
    int i,j,k,l=(int)vv.size();
    k=(1 << l);
    for(i=0;i<k;i++)
    {
        sum=0;
        for(j=0;j<l;j++)
        {
            if((i >> j) & 1)sum += vv[j];
        }
        if(idx)ost.insert(sum);
        else v.emplace_back(sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x;
    ll ans=0,t,y;
    vector<ll>v1,v2;
    cin >> n >> t;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(i <= (n+1)/2)v1.emplace_back(x);
        else v2.emplace_back(x);
    }
    PreCal(v1, 0);
    PreCal(v2, 1);
    for(auto x : v)
    {
        if(x > t)continue;
        ans=max(ans, x);
        n=ost.order_of_key(t-x+1);
        if(n)
        {
            y=*(ost.find_by_order(n-1)), ans=max({ans, y, x+y});
        }
    }
    cout << ans;
    return 0;
}