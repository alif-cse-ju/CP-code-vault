#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[105],b[105];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,t,x,sum;
    cin >> t;
    while(t--)
    {
        sum=0;
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i],sum+=b[i]-a[i];
        if(sum)cout << "-1\n";
        else
        {
            vector<pair<int,int>>ans;
            for(i=1;i<=n;i++)
            {
                x=max(0,b[i]-a[i]);
                while(x--)ans.emplace_back(i,0);
            }
            for(i=1,j=-1;i<=n;i++)
            {
                x=max(0,a[i]-b[i]);
                while(x--)ans[++j].second=i;
            }
            cout << (int)ans.size() << '\n';
            for(auto [x,y] : ans)cout << y << ' ' << x << '\n';
        }
    }
    return 0;
}