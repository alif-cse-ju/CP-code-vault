#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>voda;
        vector<pair<int,vector<int>>>dhon;
        for(i=0;i<n;i++)
        {
            cin >> k;
            y=INT_MIN;
            voda.clear();
            for(j=0;j<k;j++)
            {
                cin >> x;
                y=max(y,x-j);
                voda.emplace_back(x);
            }
            dhon.emplace_back(y,voda);
        }
        sort(dhon.begin(),dhon.end());
        ans=INT_MIN,i=0;
        for(auto [x,v] : dhon)
        {
            for(j=0;j<(int)v.size();j++)ans=max(ans,v[j]-i++);
        }
        cout << ans+1 << '\n';
    }
    return 0;
}