#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
queue<int>Q;
bool frozen[M];
vector<int>adj[M];
void Cal(const int& n)
{
    int i,j,l,x;
    for(i=0;i<n  &&  !Q.empty();i++)
    {
        l=(int)Q.size();
        for(j=0;j<l;j++)
        {
            x=Q.front(), Q.pop();
            for(int y : adj[x])
            {
                if(!frozen[y])frozen[y]=1, Q.emplace(y);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q,t,x,y;
    cin >> n >> m >> q;
    while(m--)
    {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    while(q--)
    {
        cin >> t >> x;
        if(t == 1)
        {
            if(!frozen[x])frozen[x]=1, Q.emplace(x);
        }
        else if(t == 2)Cal(x);
        else
        {
            if(frozen[x])cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}