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
const int N=4e6+5;
const int mod=1e9+7;
vector<int>bap[M];
int _time[M],cnt[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)_time[i]=-1,bap[i].clear();
        for(i=1;i<=n;i++)
        {
            cin >> k;
            cnt[i]=k;
            while(k--)
            {
                cin >> x;
                bap[x].emplace_back(i);
            }
        }
        deque<int>dq;
        for(i=1;i<=n;i++)
        {
            if(!cnt[i])_time[i]=1,dq.emplace_back(i);
        }
        ans=0;
        while(!dq.empty())
        {
            x=dq.front(),dq.pop_front();
            ans=max(ans,_time[x]);
            for(int it : bap[x])
            {
                --cnt[it];
                _time[it]=max(_time[it],_time[x]+(it < x));
                if(!cnt[it])dq.emplace_back(it);
            }
        }
        for(i=1;i<=n  &&  !cnt[i];i++);
        if(i <= n)ans=-1;
        cout << ans << '\n';
    }
    return 0;
}