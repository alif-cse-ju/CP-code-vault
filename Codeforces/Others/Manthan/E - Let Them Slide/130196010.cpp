#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
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