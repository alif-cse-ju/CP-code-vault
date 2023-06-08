#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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
ll cnt[M],sum[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<=n;i++)cnt[i]=0;
        for(i=0;i<n;i++)cin >> x, ++cnt[x];
        cout << cnt[0];
        sum[0]=cnt[0];
        priority_queue<ll>pq;
        for(i=1;i<=n;i++)sum[i] = sum[i-1]+cnt[i];
        for(i=1;i<cnt[0];i++)pq.emplace(0);
        for(i=1, ans=0;i<=n;i++)
        {
            if(sum[i-1] < i)break;
            cout << ' ' << ans+cnt[i];
            if(!cnt[i]  && !pq.empty())ans += i-pq.top(), pq.pop();
            if(cnt[i])
            {
                --cnt[i];
                while(cnt[i]--)pq.emplace(i);
            }
        }
        while(i <= n)cout << " -1", ++i;
        cout << '\n';
    }
    return 0;
}