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
const int M=9e4+5;
const int N=1e6+5;
const int mod=998244353;
int a[M],idx[M];
pair<int,int>b[M];
ordered_set<int>ost[305];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int i,j,jj,k,l,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)cin >> a[i*m+j];
        }
        for(i=0;i<m*n;i++)b[i]={a[i],i};
        sort(b,b+m*n);
        deque<int>dq;
        for(i=k=0;i<m*n;)
        {
            dq.clear();
            dq.emplace_back(b[i].second);
            for(j=i+1;j<m*n;j++)
            {
                if(b[j].first == b[i].first)dq.emplace_back(b[j].second);
                else break;
            }
            i=j;
            while(!dq.empty())
            {
                j=min(m-k%m,(int)dq.size());
                vector<int>v;
                while(j--)
                {
                    v.emplace_back(dq.front());
                    dq.pop_front();
                }
                while(!v.empty())idx[v.back()]=k++,v.pop_back();
            }
        }
        ans=0;
        for(i=0;i<n;i++)ost[i].clear();
        for(i=0;i<m*n;i++)
        {
            x=idx[i]%m;
            ans+=ost[idx[i]/m].order_of_key(x);
            ost[idx[i]/m].insert(x);
        }
        cout << ans << '\n';
    }
    return 0;
}