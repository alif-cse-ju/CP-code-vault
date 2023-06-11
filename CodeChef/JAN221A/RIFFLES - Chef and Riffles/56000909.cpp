#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int ans[M],n;
bool visited[M];
vector<int>cycle;
void DFS(int x)
{
    visited[x]=1;
    cycle.emplace_back(x);
    if(x & 1)x=(x+1)/2;
    else x=(n+x)/2;
    if(!visited[x])DFS(x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,kk,l,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans[1]=1, ans[n]=n;
        for(i=2;i<n;i++)visited[i]=0;
        for(i=2;i<n;i++)
        {
            if(!visited[i])
            {
                cycle.clear();
                DFS(i);
                l=(int)cycle.size();
                kk=k%l;
                for(j=0;j<l;j++)ans[cycle[(j+kk)%l]]=cycle[j];
            }
        }
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}