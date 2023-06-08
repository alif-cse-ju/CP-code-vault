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
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[N],ans[N],d,n;
priority_queue<pair<int,int>>pq;
void Dijkstra()
    while(!pq.empty())
    {
        auto [v,x]=pq.top();
        pq.pop();
        v=-v;
        x=(x+d)%n;
        if(a[x])a[x]=0,ans[x]=v+1,pq.emplace(-v-1,x);
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i])ans[i]=INT_MAX;
            else ans[i]=0,pq.emplace(0,i);
        }
        Dijkstra();
        sort(ans,ans+n);
        if(ans[n-1] == INT_MAX)ans[n-1]=-1;
        cout << ans[n-1] << '\n';
    }
    return 0;
}