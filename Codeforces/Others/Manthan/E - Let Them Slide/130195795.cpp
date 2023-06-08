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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
ll ans[N];
void Update(int l,int r,int v)
    ans[l]+=v,ans[r]-=v;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l,n,r,w,x;
    cin >> n >> w;
    for(i=1;i<=n;i++)
    {
        cin >> k;
        priority_queue<pair<int,int>>pq;
        for(j=1;j<=k;j++)
        {
            cin >> x;
            pq.emplace(x,j);
        }
        pq.emplace(0,k+1);
        if(k < w)pq.emplace(0,0);
        x=pq.top().first;
        l=pq.top().second;
        r=l+w-k,pq.pop();
        if(x)Update(l,r+1,x);
        set<int>st;
        for(j=1;j<l;j++)st.insert(j);
        for(j=r+1;j<=w;j++)st.insert(j);
        while(!pq.empty()  &&  !st.empty())
        {
            x=pq.top().first;
            j=pq.top().second;
            pq.pop();
            auto it=st.lower_bound(j);
            if(it != st.end())
            {
                vector<int>v;
                while(it != st.end()  &&  *(it) <= w+j-k)v.emplace_back(*(it)),++it;
                for(int it : v)
                {
                    st.erase(it);
                    if(x)Update(it,it+1,x);
                }
            }
        }
    }
    for(i=1;i<=w;i++)ans[i]+=ans[i-1],cout << ans[i] << ' ';
    return 0;
}