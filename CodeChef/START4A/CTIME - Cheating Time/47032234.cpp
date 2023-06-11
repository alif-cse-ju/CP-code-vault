#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
void solve()
{
    int f,i,j,k,l,n,x,y,ans=0;
    cin >> n >> k >> f;
    vector<pair<int,int>>v;
    for(i = 1; i <= n; i++)
    {
        cin >> x >> y;
        v.emplace_back(x,y);
    }
    sort(v.begin(),v.end());
    l=(int)v.size();
    for(i=0;i<l;i++)
    {
        if(v[i].second < v[i].first)continue;
        ans+=v[i].second-v[i].first;
        for(j=i+1;j<l;j++)
        {
            if(v[j].first < v[i].second)v[j].first=v[i].second;
            else break;
        }
    }
    ans=f-ans;
    if(ans >= k)cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}