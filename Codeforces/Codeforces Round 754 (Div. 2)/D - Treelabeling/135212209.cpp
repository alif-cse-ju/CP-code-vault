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
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
int ans[M];
bool mark[M];
vector<int>even,odd,adj[M];
void DFS(int x,int p,bool par)
    if(par)odd.emplace_back(x);
    else even.emplace_back(x);
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x,!par);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,le,lo,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        odd.clear();
        even.clear();
        for(i=1;i<=n;i++)ans[i]=mark[i]=0, adj[i].clear();
        for(i=1;i<n;i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        DFS(1,1,1);
        lo=(int)odd.size();
        le=(int)even.size();
        if(le >= lo)
        {
            for(i=k=0;i<20  &&  k<lo;i++)
            {
                if((lo >> i) & 1)
                {
                    for(j=(1 << i);j<(1 << (i+1))  &&  k<lo;j++)ans[odd[k++]]=j, mark[j]=1;
                }
            }
            for(i=j=1;i<=n;i++)
            {
                if(ans[i])continue;
                while(mark[j])++j;
                ans[i]=j++;
            }
        }
        else
        {
            for(i=k=0;i<20  &&  k<le;i++)
            {
                if((le>> i) & 1)
                {
                    for(j=(1 << i);j<(1 << (i+1))  &&  k<le;j++)ans[even[k++]]=j, mark[j]=1;
                }
            }
            for(i=j=1;i<=n;i++)
            {
                if(ans[i])continue;
                while(mark[j])++j;
                ans[i]=j++;
            }
        }
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}