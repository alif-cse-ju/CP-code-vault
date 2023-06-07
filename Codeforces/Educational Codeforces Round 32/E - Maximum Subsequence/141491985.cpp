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
int ans,m;
vector<int>v;
ordered_set<int>ost;
void Solve(const vector<int>&vv,const bool& id)
    int sum,i,j,l=(int)vv.size(),_ll;
    _ll=(1 << l);
    for(i=1;i<_ll;i++)
    {
        sum=0;
        for(j=0;j<l;j++)
        {
            if((i >> j) & 1)sum += vv[j], sum %= m;
        }
        ans=max(ans,sum);
        if(id)ost.insert(sum);
        else v.emplace_back(sum);
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,x;
    vector<int>va,vb;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(i <= n/2)va.emplace_back(x);
        else vb.emplace_back(x);
    }
    Solve(va,0);
    Solve(vb,1);
    for(int it : v)
    {
        l=ost.order_of_key(m-it);
        if(l)ans=max(ans, it+*(ost.find_by_order(l-1)));
    }
    cout << ans;
    return 0;
}