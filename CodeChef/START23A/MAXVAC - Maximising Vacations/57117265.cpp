#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,len,t,tmp,x;
    cin >> t;
    while(t--)
    {
        cin >> len >> x >> s+1;
        vector<pair<int,int>>v;
        for(i=1;i<=len;i++)
        {
            if(s[i] == '0')
            {
                for(j=i+1;j<=len  && s[j] == '0';j++);
                v.emplace_back(i,j-1), i=j;
            }
        }
        ans=0;
        for(auto [l,r] : v)ans += (r-l+1)/x;
        tmp=ans, len=(int)v.size();
        for(i=0;i<len;i++)
        {
            auto [l,r] = v[i];
            tmp -= (r-l+1)/x;
            if(l > 1)ans=max(ans, tmp+(r-l+2)/x);
            if(r < len)ans=max(ans, tmp+(r-l+2)/x);
            if(i < len-1  &&  r+2 == v[i+1].first)ans=max(ans, tmp-(v[i+1].second-v[i+1].first+1)/x+(v[i+1].second
            tmp += (r-l+1)/x;
        }
        cout << ans << '\n';
    }
    return 0;
}