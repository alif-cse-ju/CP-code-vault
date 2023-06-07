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

const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll a[M];
pair<ll,int>dp[M][105];
tuple<ll,ll,ll,int>trainings[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    for(int i=1;i<=100;i++)dp[0][i]={10000000000000000,0};
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=m;i++)
        {
            int x,y,z;cin >> x >> y >> z;
            trainings[i]=make_tuple(x,y,z,i);
        }
        sort(trainings+1,trainings+m+1);
        ll cur=0;
        vector<int>ans;
        int i,j=1,last=0;
        for(i=1;i<=n;i++)
        {
            while(j <= m)
            {
                auto [x,y,z,id]=trainings[j];
                if(x != i)break;
                for(int k=1;k<=100;k++)dp[j-last][k]=min(dp[j-last-1][k], {dp[j-last-1][max(0ll, k-z)].first+y, id});
                ++j;
            }
            cur += dp[j-last-1][100].first;
            if(cur > a[i])break;
            int rem=100;
            for(int k=j-last-1;k  &&  rem > 0;k--)
            {
                if(dp[k][rem] != dp[k-1][rem])
                {
                    auto [x,y,z,id]=trainings[last+k];
                    ans.emplace_back(id), rem -= z;
                }
            }
            last=j-1;
        }
        if(i <= n)cout << "-1\n";
        else
        {
            cout << (int)ans.size() << '\n';
            for(int &it : ans)cout << it << ' ';
            cout << '\n';
        }
    }
    return 0;
}