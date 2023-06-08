#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=5e5+5;
const int mod=1e9+7;
bool visited[N];
vector<int>adj[N];
pair<int,int>a[N];
void DFS(int x,int p)
    if(visited[x])return;
    visited[x]=1;
    for(int y : adj[x])
    {
        if(p ^ y)DFS(y,x);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,cnt=0;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i].first >> a[i].second;
    sort(a+1,a+n+1);
    set<pair<int,int>>st;
    for(i=1;i<=n  &&  cnt<n;i++)
    {
        while(!st.empty()  &&  (*(st.begin())).first < a[i].first)st.erase(st.begin());
        for(auto [x,y] : st)
        {
            if(x > a[i].second)break;
            ++cnt;
            adj[i].emplace_back(y);
            adj[y].emplace_back(i);
        }
        st.emplace(a[i].second,i);
    }
    if(cnt == n-1)
    {
        DFS(1,1);
        for(i=1,cnt=0;i<=n;i++)cnt+=visited[i];
        if(cnt == n)cout << "YES";
        else cout << "NO";
    }
    else cout << "NO";
    return 0;
}