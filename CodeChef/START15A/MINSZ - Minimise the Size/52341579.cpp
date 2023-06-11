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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    int i,j,t,cnt[65];
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(!n)
        {
            cout << "2\n1 1\n";
            continue;
        }
        vector<ll>ans;
        memset(cnt,0,sizeof(cnt));
        for(i=59;i>=0;i--)
        {
            if((n >> i) & 1ll)
            {
                if(cnt[i] & 1)continue;
                x=(1ll << (i+1))-1;
                ans.emplace_back(x);
                for(j=i;j>=0;j--)++cnt[j];
            }
            else
            {
                if(!(cnt[i] & 1))continue;
                x=(1ll << (i+1))-1;
                ans.emplace_back(x);
                for(j=i;j>=0;j--)++cnt[j];
            }
        }
        cout << (int)ans.size() << '\n';
        for(ll it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}