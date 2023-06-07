#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans,x,y,z;
    int i,k,l,m,n,t;
    cin >> t;
    while(t--)
    {
        deque<ll>pos,neg;
        cin >> n >> k;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(x < 0)neg.emplace_back(x);
            else if(x > 0)pos.emplace_back(x);
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        ans=x=y=z=0, l=(int)neg.size(), m=l%k;
        if(m)
        {
            while(m--)x=abs(neg.back()), neg.pop_back();
            ans += 2*x;
        }
        while(!neg.empty())
        {
            m=k;
            while(m--)x=abs(neg.back()), neg.pop_back();
            ans += 2*x;
        }
        y=x;
         x=0, l=(int)pos.size(), m=l%k;
        if(m)
        {
            while(m--)x=pos.front(), pos.pop_front();
            ans += 2*x;
        }
        while(!pos.empty())
        {
            m=k;
            while(m--)x=pos.front(), pos.pop_front();
            ans += 2*x;
        }
        z=x;
        ans-=max(y,z);
        cout << ans << '\n';
    }
    return 0;
}